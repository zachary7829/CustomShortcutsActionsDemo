#import <UIKit/UIKit.h>
#import "ShortcutsHeaders.h"

@interface WFActionProvider : NSObject
- (id)availableActionIdentifiers;
- (void)createActionsForRequests:(id)arg1;
- (id)createAllAvailableActions;
- (id)delegate;
- (void)deleteCache;
- (void)setDelegate:(id)arg1;
- (void)updateCache:(id /* block */)arg1;

@end

@interface WFBundledActionProvider : WFActionProvider

- (id)actionDefinitionsWithIdentifiers:(id)arg1;
- (id)availableActionIdentifiers;
- (id)bundledURL;
- (id)cacheDirectoryURL;
- (id)cacheURL;
- (void)createActionsForRequests:(id)arg1;
- (id)createAllAvailableActions;
- (id)currentVersion;
- (void)deleteCache;
- (void)updateCache:(id /* block */)arg1;

@end

%hook WFAction
-(id)output { //switch to setOutput latr
    if ([[self identifier] isEqualToString:@"com.zachary7829.coolaction"]) {
        WFContentCollection *newRet = [[WFContentCollection alloc] init];
        // custom code here, to see params you can do WFContentCollection *ret = %orig and then ret.items, which is an NSArray
        [newRet addObject:@"hopefully this will work"];
        return newRet;
    } else {
        return %orig;
    }
}
%end

%hook WFBundledActionProvider
-(id)createAllAvailableActions {
    NSLog(@"ZCustomShortcutActions started hooking");
    id createactions = %orig; // __NSSetM
    NSMutableSet *newCreateActions = [[NSMutableSet alloc]init];
    for (WFAction *newCreateAction in createactions) {
        if ([[newCreateAction identifier] isEqualToString:@"is.workflow.actions.list"]){
            [newCreateActions addObject:newCreateAction];
            NSLog(@"ZCustomShortcutActions newCreateAction: %@", newCreateAction);
            %log;
            WFAction *customActionToCreate = [[WFAction alloc] initWithIdentifier:@"com.zachary7829.coolaction" definition:MSHookIvar<NSDictionary *>(newCreateAction, "_definition") serializedParameters:MSHookIvar<NSDictionary *>(newCreateAction, "_initialSerializedParameters")];
            NSDictionary *origDef = MSHookIvar<NSDictionary *>(customActionToCreate, "_definition");
            NSMutableDictionary *mutableDefinition = [origDef mutableCopy];
            [mutableDefinition setValue:@"zachary7829 return ${WFVariable}" forKey:@"ParameterSummary"];
            [mutableDefinition setValue:@"Zachary Cool Action" forKey:@"Name"];
            NSMutableDictionary *listOutputVariable = [[mutableDefinition valueForKey:@"Output"] mutableCopy];
            [listOutputVariable setValue:@"zachary7829s Custom Action" forKey:@"OutputName"];
            [mutableDefinition setValue:listOutputVariable forKey:@"Output"];
            NSMutableDictionary *listDescriptionVariable = [[mutableDefinition valueForKey:@"Description"] mutableCopy];
            [listDescriptionVariable setValue:@"This is a custom description" forKey:@"DescriptionSummary"];
            [mutableDefinition setValue:listDescriptionVariable forKey:@"Description"];
            MSHookIvar<NSDictionary *>(customActionToCreate, "_definition") = [[NSDictionary alloc] initWithDictionary:mutableDefinition];
            NSLog(@"ZCustomShortcutActions customActionToCreate: %@", customActionToCreate);
            %log;
            [newCreateActions addObject:customActionToCreate];
        } else {
            [newCreateActions addObject:newCreateAction];
        }
    }

    NSSet *retCreateActions = [[NSSet alloc] initWithSet: newCreateActions];

    return retCreateActions;
}
%end