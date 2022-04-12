ARCHS = arm64 arm64e
TARGET = iphone:clang:14.8.1:13.0
PREFIX = $(THEOS)/toolchain/Xcode.xctoolchain/usr/bin/
SYSROOT = $(THEOS)/sdks/iPhoneOS14.5.sdk

include $(THEOS)/makefiles/common.mk

TWEAK_NAME = ZCustomShortcutActions

ZCustomShortcutActions_FILES = Tweak.xm
ZCustomShortcutActions_CFLAGS = -fobjc-arc
ZCustomShortcutActions_PRIVATE_FRAMEWORKS += WorkflowKit ContentKit

include $(THEOS_MAKE_PATH)/tweak.mk