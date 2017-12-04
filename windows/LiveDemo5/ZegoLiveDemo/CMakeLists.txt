cmake_minimum_required(VERSION 3.6)

#设置工程名称
project(ZegoLiveDemo)

#set(CMAKE_SKIP_BUILD_RPATH TRUE)                 # 编译时加上RPATH  
#set(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE)

SET(CMAKE_PREFIX_PATH $ENV{QT_DIR})

#添加qt库
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Network REQUIRED)

#编译时自动打开moc
set(CMAKE_AUTOMOC ON)
#设置工程包含当前目录，非必须                    
set(CMAKE_INCLUDE_CURRENT_DIR ON)

#添加.ui文件，并将通过qt5_wrap_ui将.ui文件包裹成ui_*.h文件
FILE(GLOB_RECURSE FORMS "*.ui")
QT5_WRAP_UI(FORMS_UIC ${FORMS})

#添加资源文件.qrc
FILE(GLOB RES "*.qrc")
QT5_ADD_RESOURCES(RES_RCC ${RES})

file(GLOB_RECURSE All_SOURCES ${CMAKE_CURRENT_LIST_DIR}/*.mm 
                              ${CMAKE_CURRENT_LIST_DIR}/*.m 
                              ${CMAKE_CURRENT_LIST_DIR}/*.cpp 
                              ${CMAKE_CURRENT_LIST_DIR}/*.mm 
                              ${CMAKE_CURRENT_LIST_DIR}/*.c 
                              ${CMAKE_CURRENT_LIST_DIR}/*.cc 
                              ${CMAKE_CURRENT_LIST_DIR}/*.hh 
                              ${CMAKE_CURRENT_LIST_DIR}/*.h)
            
if(WIN32)
    list(REMOVE_ITEM All_SOURCES ${CMAKE_CURRENT_LIST_DIR}/OSX_Objective-C/ZegoAVDevice.h)
    list(REMOVE_ITEM All_SOURCES ${CMAKE_CURRENT_LIST_DIR}/OSX_Objective-C/ZegoAVDevice.mm)
    list(REMOVE_ITEM All_SOURCES ${CMAKE_CURRENT_LIST_DIR}/OSX_Objective-C/ZegoCGImageToQImage.h)
    list(REMOVE_ITEM All_SOURCES ${CMAKE_CURRENT_LIST_DIR}/OSX_Objective-C/ZegoCGImageToQImage.mm)
    list(REMOVE_ITEM All_SOURCES ${CMAKE_CURRENT_LIST_DIR}/OSX_Objective-C/ZegoViewZoom.h)
    list(REMOVE_ITEM All_SOURCES ${CMAKE_CURRENT_LIST_DIR}/OSX_Objective-C/ZegoViewZoom.mm)
elseif(APPLE)
    list(REMOVE_ITEM All_SOURCES ${CMAKE_CURRENT_LIST_DIR}/AudioHookDialog/ZegoMusicHookDialog.h)
    list(REMOVE_ITEM All_SOURCES ${CMAKE_CURRENT_LIST_DIR}/AudioHookDialog/ZegoMusicHookDialog.cpp)
endif(WIN32)

source_group_by_dir(All_SOURCES)

include_directories(${CMAKE_CURRENT_BINARY_DIR})

if(WIN32)
    include_directories(${CMAKE_CURRENT_LIST_DIR}/../include/zegoliveroom
                        ${CMAKE_CURRENT_LIST_DIR}/../include/zegosurfacemerge
                        ${CMAKE_CURRENT_LIST_DIR}/../include/zegoaudiohook
                        ${CMAKE_CURRENT_LIST_DIR}
                        ${CMAKE_CURRENT_LIST_DIR}/UI
                        ${CMAKE_CURRENT_LIST_DIR}/AudioHookDialog)

elseif(APPLE)
    include_directories(${CMAKE_CURRENT_LIST_DIR}/../include/zegoliveroom
                        ${CMAKE_CURRENT_LIST_DIR}
                        ${CMAKE_CURRENT_LIST_DIR}/UI)
endif(WIN32)

if(WIN32)
	set(exe_property WIN32)
    set(ZegoLiveDemo_RC ${CMAKE_CURRENT_LIST_DIR}/Resources/res.rc)
	set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MD")
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MDd")
	set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /Zi")
	set(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} /DEBUG /OPT:REF /OPT:ICF")
	set(LINK_LIBRARY zegoliveroom.lib ZegoSurfaceMerge.lib ZegoAudioHook.lib)
	set(ZEGOLIVEROOM_PATH ${CMAKE_CURRENT_LIST_DIR}/../libs/windows/x86/$(Configuration)/zegoliveroom.dll)
    set(ZEGOSURFACEMERGE_PATH ${CMAKE_CURRENT_LIST_DIR}/../libs/windows/x86/$(Configuration)/ZegoSurfaceMerge.dll)
    set(ZEGOAUDIOHOOK_PATH ${CMAKE_CURRENT_LIST_DIR}/../libs/windows/x86/$(Configuration)/ZegoAudioHook.dll)
    set(OPENSSL_PATH ${CMAKE_CURRENT_LIST_DIR}/openssl)
    set(MSVC_PATH ${CMAKE_CURRENT_LIST_DIR}/msvc/x86)
    set(MUSICHOOK_PATH ${CMAKE_CURRENT_LIST_DIR}/MusicHook/ZegoMusicAudio.dll)
	add_definitions(-DUNICODE -D_UNICODE -D_SCL_SECURE_NO_WARNINGS -DWIN32 -DV_LOG -DCURL_STATICLIB)
	link_directories(${CMAKE_CURRENT_LIST_DIR}/../libs/windows/x86)

elseif(APPLE)
    SET(BUILD_WITH_INSTALL_RPATH TRUE)
    set(exe_property MACOSX_BUNDLE)
    set(MACOSX_BUNDLE_ICON_FILE ${CMAKE_CURRENT_LIST_DIR}/Resources/ZegoLiveDemo.icns)
    #set(ZegoLiveDemo_RC ${CMAKE_CURRENT_LIST_DIR}/Info.plist)
    set (CMAKE_CXX_FLAGS "--std=gnu++11 ${CMAKE_CXX_FLAGS}")
    set(LINK_LIBRARY libZegoLiveRoomOSX.dylib)				

    link_directories(${CMAKE_CURRENT_LIST_DIR}/../libs/mac)	

endif(WIN32)

#构建可执行文件
set(NAME ZegoLiveDemo)
add_executable(${NAME} ${exe_property} ${All_SOURCES} ${ZegoLiveDemo_RC} ${FORMS_UIC} ${RES_RCC} ${MACOSX_BUNDLE_ICON_FILE} ${LangSrcs})


if(WIN32)
	add_custom_command(TARGET ZegoLiveDemo POST_BUILD COMMAND if exist ${ZEGOLIVEROOM_PATH} cmake -E copy ${ZEGOLIVEROOM_PATH} ${CMAKE_CURRENT_BINARY_DIR}/$(Configuration))
    add_custom_command(TARGET ZegoLiveDemo POST_BUILD COMMAND if exist ${ZEGOSURFACEMERGE_PATH} cmake -E copy ${ZEGOSURFACEMERGE_PATH} ${CMAKE_CURRENT_BINARY_DIR}/$(Configuration))
    add_custom_command(TARGET ZegoLiveDemo POST_BUILD COMMAND if exist ${ZEGOAUDIOHOOK_PATH} cmake -E copy ${ZEGOAUDIOHOOK_PATH} ${CMAKE_CURRENT_BINARY_DIR}/$(Configuration))
    add_custom_command(TARGET ZegoLiveDemo POST_BUILD COMMAND if exist ${OPENSSL_PATH}/libeay32.dll cmake -E copy ${OPENSSL_PATH}/libeay32.dll ${CMAKE_CURRENT_BINARY_DIR}/$(Configuration))
    add_custom_command(TARGET ZegoLiveDemo POST_BUILD COMMAND if exist ${OPENSSL_PATH}/ssleay32.dll cmake -E copy ${OPENSSL_PATH}/ssleay32.dll ${CMAKE_CURRENT_BINARY_DIR}/$(Configuration))
    add_custom_command(TARGET ZegoLiveDemo POST_BUILD COMMAND if exist ${MSVC_PATH}/msvcp120.dll cmake -E copy ${MSVC_PATH}/msvcp120.dll ${CMAKE_CURRENT_BINARY_DIR}/$(Configuration))
    add_custom_command(TARGET ZegoLiveDemo POST_BUILD COMMAND if exist ${MSVC_PATH}/msvcr120.dll cmake -E copy ${MSVC_PATH}/msvcr120.dll ${CMAKE_CURRENT_BINARY_DIR}/$(Configuration))
    add_custom_command(TARGET ZegoLiveDemo POST_BUILD COMMAND if exist ${MUSICHOOK_PATH} cmake -E copy ${MUSICHOOK_PATH} ${CMAKE_CURRENT_BINARY_DIR}/$(Configuration)/MusicHook)

elseif(APPLE)
    set_source_files_properties(${CMAKE_CURRENT_LIST_DIR}/Resources/ZegoLiveDemo.icns PROPERTIES MACOSX_PACKAGE_LOCATION Resources)
    set_target_properties(${NAME} PROPERTIES MACOSX_BUNDLE_ICON_FILE ZegoLiveDemo.icns)

    ADD_FRAMEWORK(Foundation ZegoLiveDemo)
    ADD_FRAMEWORK(AVFoundation ZegoLiveDemo)
    ADD_FRAMEWORK(cocoa ZegoLiveDemo)
    ADD_FRAMEWORK(CoreMedia ZegoLiveDemo)
    ADD_FRAMEWORK(CoreVideo ZegoLiveDemo)

    #set(CMAKE_XCODE_ATTRIBUTE_DEBUG_INFORMATION_FORMAT dwarf-with-dsym)
    set_target_properties(ZegoLiveDemo PROPERTIES XCODE_ATTRIBUTE_DEBUG_INFORMATION_FORMAT "dwarf-with-dsym")
    set_target_properties(ZegoLiveDemo PROPERTIES XCODE_ATTRIBUTE_GCC_GENERATE_DEBUGGING_SYMBOLS "YES")

    set_target_properties(ZegoLiveDemo PROPERTIES XCODE_ATTRIBUTE_SEPARATE_STRIP "YES")
    set_target_properties(ZegoLiveDemo PROPERTIES XCODE_ATTRIBUTE_STRIP_STYLE "Non-Global Symbols")

endif(WIN32)

qt5_use_modules(${NAME} Core)
qt5_use_modules(${NAME} Gui)
qt5_use_modules(${NAME} Widgets)
qt5_use_modules(${NAME} Network)

target_link_libraries(${NAME} ${LINK_LIBRARY})



