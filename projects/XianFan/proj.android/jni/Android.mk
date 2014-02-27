LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := cocos2dcpp_shared

LOCAL_MODULE_FILENAME := libcocos2dcpp

CLASS_PATH := ../../Classes/

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes \
					$(LOCAL_PATH)/../../Classes/protobuf

LOCAL_SRC_FILES :=  ../../Classes/google/protobuf/descriptor.cc  \
					../../Classes/google/protobuf/descriptor.pb.cc  \
					../../Classes/google/protobuf/descriptor_database.cc  \
					../../Classes/google/protobuf/dynamic_message.cc  \
					../../Classes/google/protobuf/extension_set.cc  \
					../../Classes/google/protobuf/extension_set_heavy.cc  \
					../../Classes/google/protobuf/generated_message_reflection.cc  \
					../../Classes/google/protobuf/generated_message_util.cc  \
					../../Classes/google/protobuf/io/coded_stream.cc  \
					../../Classes/google/protobuf/io/gzip_stream.cc  \
					../../Classes/google/protobuf/io/printer.cc  \
					../../Classes/google/protobuf/io/tokenizer.cc  \
					../../Classes/google/protobuf/io/zero_copy_stream.cc  \
					../../Classes/google/protobuf/io/zero_copy_stream_impl.cc  \
					../../Classes/google/protobuf/io/zero_copy_stream_impl_lite.cc  \
					../../Classes/google/protobuf/message.cc  \
					../../Classes/google/protobuf/message_lite.cc  \
					../../Classes/google/protobuf/reflection_ops.cc  \
					../../Classes/google/protobuf/repeated_field.cc  \
					../../Classes/google/protobuf/service.cc  \
					../../Classes/google/protobuf/stubs/atomicops_internals_x86_gcc.cc  \
					../../Classes/google/protobuf/stubs/atomicops_internals_x86_msvc.cc  \
					../../Classes/google/protobuf/stubs/common.cc  \
					../../Classes/google/protobuf/stubs/once.cc  \
					../../Classes/google/protobuf/stubs/stringprintf.cc  \
					../../Classes/google/protobuf/stubs/structurally_valid.cc  \
					../../Classes/google/protobuf/stubs/strutil.cc  \
					../../Classes/google/protobuf/stubs/substitute.cc  \
					../../Classes/google/protobuf/text_format.cc  \
					../../Classes/google/protobuf/unknown_field_set.cc  \
					../../Classes/google/protobuf/wire_format.cc  \
					../../Classes/google/protobuf/wire_format_lite.cc  \
					../../Classes/protobuf/netmsg.pb.cc \
					hellocpp/main.cpp \
					../../Classes/AppDelegate.cpp \
					../../Classes/HelloWorldScene.cpp \
					../../Classes/Actor.cpp \
					../../Classes/LoginScene.cpp \
					../../Classes/SceneManager.cpp \
					../../Classes/CreateCharacter.cpp \
					../../Classes/CCLocalizedString.cpp

LOCAL_WHOLE_STATIC_LIBRARIES += cocos2dx_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocosdenshion_static
LOCAL_WHOLE_STATIC_LIBRARIES += box2d_static
LOCAL_WHOLE_STATIC_LIBRARIES += chipmunk_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocos_extension_static

include $(BUILD_SHARED_LIBRARY)

$(call import-module,cocos2dx)
$(call import-module,cocos2dx/platform/third_party/android/prebuilt/libcurl)
$(call import-module,CocosDenshion/android)
$(call import-module,extensions)
$(call import-module,external/Box2D)
$(call import-module,external/chipmunk)
