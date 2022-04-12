@class NSArray;
@protocol WFVariableProvider <NSObject>
@property (nonatomic,readonly) NSArray * availableVariableNames; 
@property (nonatomic,readonly) NSArray * availableOutputActions; 
@property (nonatomic,readonly) NSArray * workflowInputClasses; 
@required
-(BOOL)hasAvailableVariables;
-(BOOL)isVariableWithNameAvailable:(id)arg1;
-(id)possibleContentClassesForVariableNamed:(id)arg1 context:(id)arg2;
-(BOOL)hasAvailableActionOutputVariables;
-(BOOL)isVariableWithOutputUUIDAvailable:(id)arg1;
-(id)actionProvidingVariableWithOutputUUID:(id)arg1;
-(id)actionsProvidingVariableName:(id)arg1;
-(void)addVariableObserver:(id)arg1;
-(void)removeVariableObserver:(id)arg1;
-(NSArray *)availableVariableNames;
-(NSArray *)availableOutputActions;
-(NSArray *)workflowInputClasses;

@end

@interface WFActionGroupingCache : NSObject {
    NSMutableDictionary * _actionsByGroupingIdentifier;
}

@property (nonatomic, readonly) NSMutableDictionary *actionsByGroupingIdentifier;

- (id)actionsByGroupingIdentifier;
- (id)actionsForGroupingIdentifier:(id)arg1;
- (void)addAction:(id)arg1 sortingWithWorkflowActions:(id)arg2;
- (id)init;
- (void)removeAction:(id)arg1;
- (void)sortActionsForGroupingIdentifier:(id)arg1 withWorkflowActions:(id)arg2;

@end

@protocol WFUUIDProvider <NSObject>
@required
-(id)generateOutputUUIDForAction:(id)arg1;

@end

@protocol WFParameterEventObserver <NSObject>
@optional
-(void)parameterAttributesDidChange:(id)arg1;
-(void)parameterDefaultSerializedRepresentationDidChange:(id)arg1;
-(void)parameterStateValidityCriteriaDidChange:(id)arg1;

@end

@interface WFContentSourceTracker : NSObject {
    NSMutableDictionary * _contentSources;
    NSObject<OS_dispatch_queue> * _trackingContentSourceQueue;
}

@property (nonatomic, readonly) NSMutableDictionary *contentSources;
@property (nonatomic, readonly) NSObject<OS_dispatch_queue> *trackingContentSourceQueue;

- (void)addContentSource:(id)arg1 forParameter:(id)arg2;
- (id)contentSourceForParameter:(id)arg1;
- (id)contentSources;
- (id)init;
- (id)trackedContentSource;
- (id)trackingContentSourceQueue;

@end

@interface WFCoercionOptions : NSObject <NSCopying> {
    NSDictionary * _dictionary;
}

@property (nonatomic, readonly) NSDictionary *dictionary;

+ (id)new;
+ (id)optionsWithDictionary:(id)arg1;
+ (void)registerDefaultDisallowedCoercionPath:(id)arg1;

// - (void).cxx_destruct;
- (bool)coercionPathIsDisallowed:(id)arg1;
// - (id)copyWithZone:(struct _NSZone { }*)arg1;
- (id)dictionary;
- (id)init;
- (id)initWithDictionary:(id)arg1;
- (id)itemClassPrioritizationType;
- (void)makeContactAccessResourceAvailableIfNeededWithCompletionHandler:(id /* block */)arg1;
- (void)makeRemoteServerAccessResourceAvailableIfNeededWithURLs:(id)arg1 completionHandler:(id /* block */)arg2;
- (id)optionsByAddingContentsOfOptions:(id)arg1;
- (id)preferredTypes;

@end

@interface WFContentCollection : NSObject <NSCopying, NSSecureCoding> {
    WFCoercionOptions * _defaultCoercionOptions;
    NSLock * _itemWriteLock;
    NSMutableArray * _mutableItems;
}

@property (nonatomic, retain) WFCoercionOptions *defaultCoercionOptions;
@property (nonatomic, retain) NSLock *itemWriteLock;
@property (nonatomic, readonly) NSArray *items;
@property (nonatomic, retain) NSMutableArray *mutableItems;
@property (nonatomic, readonly) long long numberOfItems;

// Image: /System/Library/PrivateFrameworks/ContentKit.framework/ContentKit

+ (id)collectionWithItems:(id)arg1;
+ (void)generateCollectionFromDragItems:(id)arg1 allowedItemClasses:(id)arg2 completionHandler:(id /* block */)arg3;
+ (void)generateCollectionFromPasteboard:(id)arg1 completionHandler:(id /* block */)arg2;
+ (void)getContentItemsForPasteboardItems:(id)arg1 resultBlock:(id /* block */)arg2;
+ (bool)supportsSecureCoding;

- (void)addFile:(id)arg1;
- (void)addItem:(id)arg1;
- (void)addItems:(id)arg1;
- (void)addObject:(id)arg1;
- (void)addObject:(id)arg1 named:(id)arg2;
- (bool)canPerformCoercion:(id)arg1;
- (id)collectionByFilteringItemsWithBlock:(id /* block */)arg1 excludedItems:(id*)arg2;
- (id)collectionByFilteringToItemClass:(Class)arg1 excludedItems:(id*)arg2;
- (id)collectionByMergingContentSource:(id)arg1;
- (id)contentSource;
- (void)copyToPasteboard:(id)arg1 options:(id)arg2 completionHandler:(id /* block */)arg3;
- (id)defaultCoercionOptions;
- (id)description;
- (id)effectiveCoercionOptionsForRequest:(id)arg1;
- (void)encodeWithCoder:(id)arg1;
- (void)enumerateFileRepresentations:(id /* block */)arg1 forType:(id)arg2 completionHandler:(id /* block */)arg3;
- (void)enumerateObjectRepresentations:(id /* block */)arg1 forClass:(Class)arg2 completionHandler:(id /* block */)arg3;
- (id)extensionItems;
- (void)generateCollectionByCoercingToItemClass:(Class)arg1 completionHandler:(id /* block */)arg2;
- (void)generateCollectionByCoercingToItemClasses:(id)arg1 completionHandler:(id /* block */)arg2;
- (void)generateCollectionByCoercingToItemClasses:(id)arg1 options:(id)arg2 completionHandler:(id /* block */)arg3;
- (void)generateCollectionByEvaluatingQuery:(id)arg1 forContentItemClass:(Class)arg2 completionHandler:(id /* block */)arg3;
- (void)getFileRepresentation:(id /* block */)arg1 forType:(id)arg2;
- (void)getFileRepresentationAndContentSource:(id /* block */)arg1 forType:(id)arg2;
- (void)getFileRepresentations:(id /* block */)arg1 forType:(id)arg2;
- (void)getFileRepresentations:(id /* block */)arg1 options:(id)arg2 forType:(id)arg3;
- (void)getObjectRepresentation:(id /* block */)arg1 forClass:(Class)arg2;
- (void)getObjectRepresentationAndContentSource:(id /* block */)arg1 forClass:(Class)arg2;
- (void)getObjectRepresentations:(id /* block */)arg1 forClass:(Class)arg2;
- (void)getObjectRepresentations:(id /* block */)arg1 options:(id)arg2 forClass:(Class)arg3;
- (void)getStringRepresentation:(id /* block */)arg1;
- (void)getStringRepresentations:(id /* block */)arg1;
- (unsigned long long)hash;
- (id)init;
- (id)initWithCoder:(id)arg1;
- (id)initWithDefaultCoercionOptions:(id)arg1;
- (id)initWithItems:(id)arg1 defaultCoercionOptions:(id)arg2;
- (bool)isCoercibleToItemClass:(Class)arg1;
- (bool)isCoercibleToItemClasses:(id)arg1;
- (bool)isEqual:(id)arg1;
- (id)itemWriteLock;
- (id)items;
- (id)minimalExtensionItems;
- (id)mutableItems;
- (long long)numberOfItems;
- (void)performCoercion:(id)arg1;
- (void)removeItem:(id)arg1;
- (void)transformFileRepresentationsForType:(id)arg1 usingBlock:(id /* block */)arg2 completionHandler:(id /* block */)arg3;
- (void)transformFirstFileRepresentationForType:(id)arg1 usingBlock:(id /* block */)arg2 completionHandler:(id /* block */)arg3;
- (void)transformFirstObjectRepresentationForClass:(Class)arg1 usingBlock:(id /* block */)arg2 completionHandler:(id /* block */)arg3;
- (void)transformItemsAndFlattenUsingBlock:(id /* block */)arg1 completionHandler:(id /* block */)arg2;
- (void)transformItemsUsingBlock:(id /* block */)arg1 completionHandler:(id /* block */)arg2;
- (void)transformObjectRepresentationsForClass:(Class)arg1 usingBlock:(id /* block */)arg2 completionHandler:(id /* block */)arg3;

// Image: /System/Library/PrivateFrameworks/WorkflowKit.framework/WorkflowKit

- (void)getRecipients:(id /* block */)arg1;

// Image: /System/Library/PrivateFrameworks/WorkflowUI.framework/WorkflowUI

- (void)generatePreviewControllerDataSource:(id /* block */)arg1;
- (long long)numberOfPreviewItemsInPreviewController:(id)arg1;
- (id)previewController:(id)arg1 previewItemAtIndex:(long long)arg2;

@end

@protocol WFActionParameterInputProvider <NSObject>
@required
-(void)action:(id)arg1 provideInputForParameters:(id)arg2 withDefaultStates:(id)arg3 completionHandler:(/*^block*/id)arg4;
-(BOOL)action:(id)arg1 canProvideInputForParameter:(id)arg2;

@end

@interface WFWorkflow : NSObject
@end

@interface WFAction : NSObject <NSCopying, WFParameterEventObserver, WFUUIDProvider, WFVariableProvider> {
    id /* block */  _completionHandler;
    WFContentSourceTracker * _contentSourceTracker;
    NSDictionary * _definition;
    NSHashTable * _eventObservers;
    NSString * _identifier;
    NSDictionary * _initialSerializedParameters;
    WFContentCollection * _input;
    NSArray * _inputContentClasses;
    bool  _inputParameterUnlocked;
    WFContentCollection * _output;
    NSArray * _outputContentClasses;
    NSArray * _parameters;
    NSDictionary * _parametersByKey;
    NSDictionary * _processedParameters;
    NSProgress * _progress;
    bool  _running;
    bool  _skipsProcessingHiddenParameters;
    NSMutableDictionary * _supplementalSerializedParameters;
    WFWorkflow * _workflow;
}

@property (nonatomic, copy) NSString *UUID;
@property (nonatomic, readonly) NSString *accessibilityName;
@property (nonatomic, readonly) NSSet *allPossibleDescriptionRequires;
@property (nonatomic, readonly) NSArray *allPossibleDescriptionResults;
@property (nonatomic, readonly, copy) NSString *appBundleIdentifier;
@property (nonatomic, readonly) NSString *appIdentifier;
@property (nonatomic, copy) NSString *groupingIdentifier;
@property (nonatomic, readonly, copy) NSString *identifier;
@property (nonatomic, readonly) NSArray *supportedAppIdentifiers;
@property (nonatomic, readonly) NSArray *unsupportedEnvironments;
@property (nonatomic, readonly) NSArray *userInterfaceTypes;
@property (nonatomic, readonly) WFWorkflow *workflow;
@property (nonatomic, readonly) NSArray *workflowInputClasses;
@property (nonatomic, readonly) NSString *descriptionSummary;
@property (nonatomic, readonly) NSString *name;
@property (nonatomic, readonly, copy) NSDictionary *definition;

+ (id)iconCache;
+ (id)indentationLevelsForActions:(id)arg1;
+ (bool)outputIsExemptFromTaintTrackingInheritance;
+ (void)showImplicitChooseFromListWithInput:(id)arg1 userInterface:(id)arg2 cancelHandler:(id /* block */)arg3 selectionHandler:(id /* block */)arg4;

- (id)UUID;
- (void)_processParameterStates:(id)arg1 withInput:(id)arg2 skippingHiddenParameters:(bool)arg3 askForValuesIfNecessary:(bool)arg4 completionHandler:(id /* block */)arg5;
- (id)accessResourcesToBeAuthorizedImplicitlyForUpdatedParameterState:(id)arg1 forParameter:(id)arg2;
- (id)accessibilityName;
- (id)actionForAppIdentifier:(id)arg1;
- (id)actionProvidingVariableWithOutputUUID:(id)arg1;
- (id)actionsProvidingVariableName:(id)arg1;
- (void)addEventObserver:(id)arg1;
- (void)addVariableObserver:(id)arg1;
- (id)allPossibleDescriptionRequires;
- (id)allPossibleDescriptionResults;
- (id)app;
- (id)appBundleIdentifier;
- (id)appIdentifier;
- (id)appSection;
- (id)attributedLocalizedName;
- (id)attribution;
- (id)availableOutputActions;
- (id)availableVariableNames;
- (bool)blocksSnapping;
- (id)groupingIdentifier;
- (bool)hasAvailableActionOutputVariables;
- (bool)hasAvailableVariables;
- (bool)hasChildren;
- (id)icon;
- (id)iconName;
- (id)identifier;
- (bool)ignoresOutputFromAction:(id)arg1 inWorkflow:(id)arg2;
- (id)inheritedInputVariableInWorkflow:(id)arg1;
- (id)inheritedOutputContentClassesInWorkflow:(id)arg1;
- (id)inheritedOutputContentClassesInWorkflow:(id)arg1 context:(id)arg2;
- (id)initWithIdentifier:(id)arg1 definition:(id)arg2 serializedParameters:(id)arg3;
- (id)initialSerializedParameters;
- (long long)initialSuggestionBehavior;
- (void)initializeParameters;
- (id)input;
- (id)inputContentClasses;
- (id)inputParameter;
- (id)inputParameterKey;
- (bool)inputParameterUnlocked;
- (bool)inputPassthrough;
- (bool)inputRequired;
- (id)inputSourceInWorkflow:(id)arg1;
- (bool)inputTypePassthrough;
- (id)inputTypes;
- (bool)inputsMultipleItems;
- (bool)isConstructorAction;
- (bool)isDebugAction;
- (bool)isDeletable;
- (bool)isDiscontinued;
- (bool)isDiscoverable;
- (bool)isDiscoverableInSearch;
- (bool)isFavorite;
- (bool)isLastAction;
- (bool)isMissing;
- (bool)isRelevantToUser;
- (bool)isResidentCompatible;
- (bool)isRunning;
- (bool)isUnsupportedWhenRunWithEnvironment:(id)arg1;
- (bool)isVariableWithNameAvailable:(id)arg1;
- (bool)isVariableWithOutputUUIDAvailable:(id)arg1;
- (bool)isWatchCompatible;
- (id)keyCommands;
- (id)keyImage;
- (id)keywords;
- (id)lastModifiedDate;
- (bool)legacyBehaviorIgnoresOutputFromAction:(id)arg1 inWorkflow:(id)arg2;
- (id)localizedAttribution;
- (id)localizedCategories;
- (id)localizedDefaultOutputName;
- (id)localizedDescriptionAttribution;
- (id)localizedDescriptionInput;
- (id)localizedDescriptionNote;
- (id)localizedDescriptionRequires;
- (id)localizedDescriptionResult;
- (id)localizedDescriptionSummary;
- (id)localizedFooter;
- (id)localizedKeyParameterDisplayName;
- (id)localizedKeywords;
- (id)localizedName;
- (id)localizedShortName;
- (id)localizedSubcategoryForCategory:(id)arg1;
- (id)localizedSubtitle;
- (void)lockInputParameter;
- (void)makeAccessResourcesAvailableAtWorkflowLevelAndRun;
- (id)minimumSupportedClientVersion;
- (id)name;
- (void)nameUpdated;
- (bool)neverSuggested;
- (id)output;
- (id)outputContentClasses;
- (void)outputDetailsUpdated;
- (id)outputDictionary;
- (unsigned long long)outputDisclosureLevel;
- (id)outputIcon;
- (id)outputMeasurementUnitType;
- (id)outputName;
- (id)outputTypes;
- (id)outputVariableWithVariableProvider:(id)arg1 UUIDProvider:(id)arg2;
- (bool)outputsMultipleItems;
- (unsigned long long)parameterCollapsingBehavior;
- (void)parameterDefaultSerializedRepresentationDidChange:(id)arg1;
- (id)parameterDefinitions;
- (id)parameterForKey:(id)arg1;
- (id)parameterInputProvider;
- (id)parameterKeysIgnoredForParameterSummary;
- (id)parameterStateForKey:(id)arg1;
- (id)parameterStateForKey:(id)arg1 fallingBackToDefaultValue:(bool)arg2;
- (void)parameterStateValidityCriteriaDidChange:(id)arg1;
- (id)parameterSummary;
- (id)parameterValueForKey:(id)arg1 ofClass:(Class)arg2;
- (id)parameters;
- (id)parametersByKey;
- (id)parametersRequiringUserInputAlongsideParameter:(id)arg1;
- (id)populatedInputWithProcessedParameterValues:(id)arg1;
- (bool)populatesInputFromInputParameter;
- (id)possibleContentClassesForVariableNamed:(id)arg1 context:(id)arg2;
- (id)previousAction;
- (id)processedParameters;
- (id)progress;
- (id)providedVariableNames;
- (long long)rateLimitDelay;
- (long long)rateLimitThreshold;
- (long long)rateLimitTimeout;
- (void)removeEventObserver:(id)arg1;
- (void)removeVariableObserver:(id)arg1;
- (id)requiredResources;
- (bool)requiresHandoffWhenRunWithUserInterfaceType:(id)arg1;
- (bool)requiresUserInteractionWhenRunWithInput:(id)arg1;
- (void)resetOutput;
- (id)resourceManager;
- (void)runAsynchronouslyWithInput:(id)arg1;
- (bool)runAsynchronouslyWithInput:(id)arg1 userInterfaceType:(id)arg2 userInterface:(id)arg3;
- (void)runWithInput:(id)arg1 error:(id*)arg2;
- (void)runWithInput:(id)arg1 userInterface:(id)arg2 parameterInputProvider:(id)arg3 variableSource:(id)arg4 completionHandler:(id /* block */)arg5;
- (void)runWithSiriUserInterface:(id)arg1 input:(id)arg2;
- (void)runWithUIKitUserInterface:(id)arg1 input:(id)arg2;
- (void)runWithUIKitWidgetUserInterface:(id)arg1 input:(id)arg2;
- (Class)runningViewClass;
- (id)serializedParameters;
- (id)serializedParametersForDonatedIntent:(id)arg1 allowDroppingUnconfigurableValues:(bool)arg2;
- (void)setContentSourceTracker:(id)arg1;
- (void)setDefaultCoercionOptionsOnContentCollection:(id)arg1;
- (void)setDefaultCoercionOptionsOnInputs;
- (void)setFavorite:(bool)arg1;
- (void)setInitialSerializedParameters:(id)arg1;
- (void)setInputParameterUnlocked:(bool)arg1;
- (void)setOutput:(id)arg1;
- (void)setOutput:(id)arg1 onVariableSource:(id)arg2;
- (void)setOutputName:(id)arg1;
- (void)setParameterInputProvider:(id)arg1;
- (bool)setParameterState:(id)arg1 forKey:(id)arg2;
- (void)setParametersByKey:(id)arg1;
- (void)setProcessedParameters:(id)arg1;
- (void)setProgress:(id)arg1;
- (void)setRunning:(bool)arg1;
- (void)setSupplementalParameterValue:(id)arg1 forKey:(id)arg2;
- (void)setSupplementalSerializedParameters:(id)arg1;
- (void)setUserInterface:(id)arg1;
- (void)setVariableSource:(id)arg1;
- (id)settingsUIDefinition;
- (Class)settingsViewControllerClass;
- (id)shortName;
- (bool)shouldBeConnectedToPreviousActionInWorkflow:(id)arg1 withOutputsConsumedByFollowingActions:(id)arg2;
- (bool)shouldBeIncludedInAppsList;
- (bool)shouldBeSuggestedAfterAction:(id)arg1 inWorkflow:(id)arg2;
- (bool)showsImplicitChooseFromListWhenRunWithInput:(id)arg1;
- (bool)showsSettingsWhenResourcesUnavailable;
- (bool)skipsProcessingHiddenParameters;
- (void)snapInputParameterIfNecessary;
- (bool)snappingPassthrough;
- (id)specifiedInputContentClasses;
- (id)specifiedOutputContentClasses;
- (id)subcategoryForCategory:(id)arg1;
- (id)supplementalParameterValueForKey:(id)arg1 ofClass:(Class)arg2;
- (id)supplementalSerializedParameters;
- (id)supportedAppIdentifiers;
- (bool)supportsUserInterfaceType:(id)arg1;
- (id)targetDataInfo;
- (id)typeDescriptionWithTypes:(id)arg1 explanationText:(id)arg2 multiple:(bool)arg3 optional:(bool)arg4;
- (void)unlockInputParameter;
- (id)unsupportedEnvironments;
- (id)userDefinedParameterStates;
- (id)userInterface;
- (id)userInterfaceTypes;
- (id)variableSource;
- (id)visibleParametersWithProcessing:(bool)arg1;
- (void)wasAddedToWorkflow:(id)arg1;
- (void)wasAddedToWorkflowByUser:(id)arg1;
- (void)wasRemovedFromWorkflow:(id)arg1;
- (id)workflow;
- (id)workflowInputClasses;
- (id)definition;

@end

@interface WFActionParameterSummary : NSObject {
    // WFAction * _action;
    // <WFPropertyListObject> * _definition;
    NSArray * _possibleValues;
    NSString * _singleFormatString;
}

@property (nonatomic) WFAction *action;
// @property (nonatomic, readonly, copy) <WFPropertyListObject> *definition;
@property (nonatomic, readonly, copy) NSArray *possibleValues;
@property (nonatomic, readonly, copy) NSString *singleFormatString;

// - (id)action;
- (id)definition;
- (id)explodedPossibleValuesForLocalization;
- (id)explodedPossibleValuesForLocalizationWithParameterReplacements;
- (id)explodedSummaryStringWithKey:(id)arg1 value:(id)arg2;
- (id)initWithAction:(id)arg1 definition:(id)arg2;
- (id)localizedFormatString;
- (id)parameterReplacedString:(id)arg1 withOverrides:(id)arg2;
- (id)placeholderForKey:(id)arg1;
- (id)possibleValues;
- (id)possibleValuesFromDictionary:(id)arg1;
// - (void)setAction:(id)arg1;
- (id)singleFormatString;

@end

@interface WFExitAction : WFAction

- (bool)legacyBehaviorIgnoresOutputFromAction:(id)arg1 inWorkflow:(id)arg2;
- (void)runWithInput:(id)arg1 error:(id*)arg2;

@end

@interface WFContentItem
@end

@protocol WFContentItemClass


+(id)contentCategories;
+(id)countDescription;
+(id)defaultSourceForRepresentation:(id)arg0 ;
+(id)filterDescription;
+(id)localizedFilterDescription;
+(id)localizedPluralFilterDescription;
+(id)localizedPluralTypeDescription;
+(id)localizedTypeDescription;
+(id)outputTypes;
+(id)ownedTypes;
+(id)pluralFilterDescription;
+(id)pluralTypeDescription;
+(id)typeDescription;

@optional
+(BOOL)supportedTypeMustBeDeterminedByInstance:(id)arg0 ;
+(id)filterRepresentationsForAllowedContent:(id)arg0 ;
+(id)itemWithSerializedItem:(id)arg0 forType:(id)arg1 named:(id)arg2 contentSource:(id)arg3 ;
+(id)ownedPasteboardTypes;
+(id)propertyBuilders;
-(BOOL)cachesSupportedTypes;
-(BOOL)canGenerateRepresentationForType:(id)arg0 ;
-(BOOL)includesFileRepresentationInSerializedItem;
-(id)additionalRepresentationsForSerialization;
-(id)internalRepresentationForCopying;
-(id)preferredFileType;
-(id)preferredObjectType;
@end

@interface WFGenericFileContentItem : WFContentItem <WFContentItemClass>





+(id)contentCategories;
+(id)itemWithSerializedItem:(id)arg0 forType:(id)arg1 named:(id)arg2 contentSource:(id)arg3 ;
+(id)outputTypes;
+(id)ownedTypes;
+(id)propertyBuilders;
-(BOOL)canGenerateRepresentationForType:(id)arg0 ;
-(BOOL)isContent;

@end

@interface WFDataDetectorResults
@end

@interface WFStringContentItem : WFGenericFileContentItem <WFContentItemClass> {
    WFDataDetectorResults * _dataDetectorResults;
}

@property (retain, nonatomic) WFDataDetectorResults *dataDetectorResults; // ivar: _dataDetectorResults
@property (nonatomic, readonly) NSString *string;

+ (id)contentCategories;
+ (id)itemWithSerializedItem:(id)arg1 forType:(id)arg2 named:(id)arg3 contentSource:(id)arg4;
+ (id)outputTypes;
+ (id)ownedTypes;
+ (id)pluralTypeDescription;
+ (bool)supportedTypeMustBeDeterminedByInstance:(id)arg1;
+ (id)typeDescription;

- (bool)canGenerateRepresentationForType:(id)arg1;
- (id)dataDetectorResults;
- (id)generateFileRepresentationForType:(id)arg1 options:(id)arg2 error:(id*)arg3;
- (void)generateObjectRepresentations:(id /* block */)arg1 options:(id)arg2 forClass:(Class)arg3;
- (id)generateObjectRepresentationsForClass:(Class)arg1 options:(id)arg2 error:(id*)arg3;
- (id)generateObjectsForClass:(Class)arg1 error:(id*)arg2;
- (bool)includesFileRepresentationInSerializedItem;
- (id)internalRepresentationForCopying;
- (bool)isContent;
// - (void)setDataDetectorResults:(id)arg1;
- (id)string;

@end