cmake_minimum_required(VERSION 3.5)

project(Game_FlipCoin VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

find_package(Qt6 REQUIRED COMPONENTS Multimedia)

set(PROJECT_SOURCES
        main.cpp
        mainscene.cpp
        mainscene.h
        mainscene.ui
        res.qrc
        mypushbutton.h mypushbutton.cpp
        chooselevelscene.h chooselevelscene.cpp
        playscene.h playscene.cpp
        mycoin.h mycoin.cpp
        dataconfig.cpp dataconfig.h
#####add by liu
        Coin0001.icns
#####
)

####add by liu
set_source_files_properties(Coin0001.icns PROPERTIES
    MACOSX_PACKAGE_LOCATION "Resources")
#####

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Game_FlipCoin
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET Game_FlipCoin APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(Game_FlipCoin SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(Game_FlipCoin
            ${PROJECT_SOURCES}
            MACOSX_BUNDLE
        )
    endif()
endif()

target_link_libraries(Game_FlipCoin PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(Game_FlipCoin PRIVATE Qt6::Multimedia)

set_target_properties(Game_FlipCoin PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE

#####add by liu
    MACOSX_BUNDLE_ICON_FILE Coin0001
#####
)

install(TARGETS Game_FlipCoin
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Game_FlipCoin)
endif()
