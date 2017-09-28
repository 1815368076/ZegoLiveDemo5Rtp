#设置cmake版本号
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

file(GLOB_RECURSE All_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.mm ${CMAKE_CURRENT_SOURCE_DIR}/*.m ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/*.mm ${CMAKE_CURRENT_SOURCE_DIR}/*.c ${CMAKE_CURRENT_SOURCE_DIR}/*.cc 
									${CMAKE_CURRENT_SOURCE_DIR}/*.hh ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
source_group_by_dir(All_SOURCES)	

include_directories(${CMAKE_CURRENT_BINARY_DIR})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}
s                                       ${CMAKE_CURRENT_SOURCE_DIR}/../include/zegoliveroom
                                        ${CMAKE_CURRENT_SOURCE_DIR}/Base
                                        ${CMAKE_CURRENT_SOURCE_DIR}/Config
                                        ${CMAKE_CURRENT_SOURCE_DIR}/Delegate
                                        ${CMAKE_CURRENT_SOURCE_DIR}/Model
                                        ${CMAKE_CURRENT_SOURCE_DIR}/Settings
                                        ${CMAKE_CURRENT_SOURCE_DIR}/Signal
                                        ${CMAKE_CURRENT_SOURCE_DIR}/UI
                                        ${CMAKE_CURRENT_SOURCE_DIR}/Dialog
                                        ${CMAKE_CURRENT_SOURCE_DIR}/VideoCapture
                                        ${CMAKE_CURRENT_SOURCE_DIR}/VideoFilter
)
					
if(WIN32)
	set(exe_property WIN32)
    set(ZegoLiveDemo_RC ${CMAKE_CURRENT_SOURCE_DIR}/ZegoLiveDemo.rc)
	set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MD")
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MDd")
	set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /Zi")
	set(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} /DEBUG /OPT:REF /OPT:ICF")
	set(LINK_LIBRARY zegoliveroom.lib)
	set(ZEGOLIVEROOM_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../ZegoLiveRoom/lib/windows/$(Configuration)/zegoliveroom.dll)

	add_definitions(-DUNICODE -D_UNICODE -D_SCL_SECURE_NO_WARNINGS -DWIN32 -DV_LOG -DCURL_STATICLIB)
	link_directories(${CMAKE_CURRENT_SOURCE_DIR}/../ZegoLiveRoom/lib/windows)

elseif(APPLE)
    SET(BUILD_WITH_INSTALL_RPATH TRUE)
    set(exe_property MACOSX_BUNDLE)
    #set(ZegoLiveDemo_RC ${CMAKE_CURRENT_SOURCE_DIR}/Info.plist)
    set (CMAKE_CXX_FLAGS "--std=gnu++11 ${CMAKE_CXX_FLAGS}")
	set(LINK_LIBRARY libzegoliveroom.dylib)				

	link_directories(${CMAKE_CURRENT_SOURCE_DIR}/../libs/x86/Release)	

endif(WIN32)

#构建可执行文件
set(NAME ZegoLiveDemo)
add_executable(${NAME} ${exe_property} ${All_SOURCES} ${ZegoLiveDemo_RC} ${FORMS_UIC} ${RES_RCC} ${MACOSX_BUNDLE_ICON_FILE} ${LangSrcs})


if(WIN32)
	add_custom_command(TARGET ZegoLiveDemo POST_BUILD COMMAND if exist ${ZEGOLIVEROOM_PATH} cmake -E copy ${ZEGOLIVEROOM_PATH} ${CMAKE_CURRENT_BINARY_DIR}/$(Configuration))

elseif(APPLE)
    ADD_FRAMEWORK(Foundation ZegoLiveDemo)	
    ADD_FRAMEWORK(SystemConfiguration ZegoLiveDemo)	

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



