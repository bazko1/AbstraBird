cmake_minimum_required(VERSION 3.7)
project(AbstraBird)

set(CMAKE_CXX_STANDARD 14)


include_directories(mainGame/headers)

file(GLOB SOURCE_FILES
    "mainGame/src/*.cpp"
    "main.cpp"
)



add_executable(AbstraBird ${SOURCE_FILES})
add_definitions( -D_VAR="${PROJECT_SOURCE_DIR}/mainGame/Pictures/")
INCLUDE(FindPkgConfig)
PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)

PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)

INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})

set (CMAKE_CXX_FLAGS "-Wno-write-strings")

