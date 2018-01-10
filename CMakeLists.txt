cmake_minimum_required(VERSION 3.7)
project(AbstraBird)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp IDrawable.h IIntersects.h Bird.cpp Bird.h Obstacle.cpp Obstacle.h ObstacleSet.cpp ObstacleSet.h IUpdate.h GameLogic.cpp GameLogic.h Window.cpp Window.h cmake-build-debug/Game.cpp cmake-build-debug/Game.h InputListener.cpp InputListener.h Pipe.cpp Pipe.h DeltaTimer.h Renderer.cpp Renderer.h)
add_executable(AbstraBird ${SOURCE_FILES})

INCLUDE(FindPkgConfig)
PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)

PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)

INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})


#INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS})
#TARGET_LINK_LIBRARIES( ${PROJECT_NAME} ${SDL2_LIBRARIES} )

