cmake_minimum_required(VERSION 3.7)
project(AbstraBird)

set(CMAKE_CXX_STANDARD 14)

include_directories(mainGame/headers)

include_directories(gui)
include_directories(SDL-bindings)

#"mainGame/src/*.cpp"
file(GLOB SOURCE_FILES
    
    "gui/*.cpp"
    "main.cpp"
    "SDL-bindings/*.cpp"
    "mainGame/src/*.cpp"
)

add_executable(AbstraBird ${SOURCE_FILES})
add_definitions( -D_VAR="${PROJECT_SOURCE_DIR}/mainGame/Pictures/")
INCLUDE(FindPkgConfig)
PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)

PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)
PKG_SEARCH_MODULE(SDL2TTF REQUIRED SDL2_ttf>=2.0.0)

INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS} ${SDL2TTF_INCLUDE_DIRS} )
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES} ${SDL2TTF_LIBRARIES} )

set (CMAKE_CXX_FLAGS "-Wno-write-strings"  )


