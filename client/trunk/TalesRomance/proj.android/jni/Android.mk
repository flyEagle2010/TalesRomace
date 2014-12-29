LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := game_shared
#LOCAL_MODULE_FILENAME := libgame

$(call import-add-path,$(LOCAL_PATH)/../../cocos2d)
$(call import-add-path,$(LOCAL_PATH)/../../cocos2d/external)
$(call import-add-path,$(LOCAL_PATH)/../../cocos2d/cocos)

LOCAL_MODULE := cocos2dcpp_shared

LOCAL_MODULE_FILENAME := libcocos2dcpp


#LOCAL_SRC_FILES := hellocpp/main.cpp \
#                   ../../Classes/AppDelegate.cpp \
#                   ../../Classes/HelloWorldScene.cpp
#
#LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes


#=======================cpp=====================================================================
MY_CPP_PATH  := $(LOCAL_PATH)/

MY_FILES_PATH  :=  $(LOCAL_PATH) \
                   $(LOCAL_PATH)/../../Classes

MY_FILES_SUFFIX := %.cpp %.c %.cc %.m %.mm

My_All_Files := $(foreach src_path,$(MY_FILES_PATH), $(shell find $(src_path) -type f) ) 
My_All_Files := $(My_All_Files:$(MY_CPP_PATH)/./%=$(MY_CPP_PATH)%)
MY_SRC_LIST  := $(filter $(MY_FILES_SUFFIX),$(My_All_Files)) 
MY_SRC_LIST  := $(MY_SRC_LIST:$(LOCAL_PATH)/%=%)
LOCAL_SRC_FILES := $(MY_SRC_LIST)
$(warning $(LOCAL_SRC_FILES))

#=======================hfile=====================================================================

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes \
                    $(LOCAL_PATH)/../../cocos2d/external/libpomelo/include \
                    $(LOCAL_PATH)/../../cocos2d/external/libpomelo/deps/jansson/src \
                    $(LOCAL_PATH)/../../cocos2d/external/libpomelo/deps/uv/include \
                    $(LOCAL_PATH)/../../cocos2d/external/libpomelo/deps/uv/include/uv-private \                   

LOCAL_C_INCLUDES += $(shell ls -FR $(LOCAL_C_INCLUDES) | grep $(LOCAL_PATH)/$ )
LOCAL_C_INCLUDES := $(LOCAL_C_INCLUDES:$(LOCAL_PATH)/%:=$(LOCAL_PATH)/%)
					
#============================================================================================

LOCAL_STATIC_LIBRARIES := cocos2dx_static pomelo_static spine_static cocostudio_static

COMMON_GLOBAL_CFLAGS:= -D__ANDROID__

include $(BUILD_SHARED_LIBRARY)

$(call import-module,.)
$(call import-module,libpomelo)
