cmake_minimum_required(VERSION 3.7)
project(AbstraBird)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Window.h Window.cpp DeltaTimer.h SquareObject.h SquareObject.cpp ObstacleSet.h ObstacleSet.cpp  GameLogic.cpp GameLogic.h Game.cpp Game.h InputListener.cpp InputListener.h SquareMovingObject.h SquareMovingObject.cpp RectBird.h Bird.cpp Bird.h  Obstacle.cpp Obstacle.h Pipes.h IIntersects.h IUpdate.h IRenderable.h)
add_executable(AbstraBird ${SOURCE_FILES})

INCLUDE(FindPkgConfig)
PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)

PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)

INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})


#INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS})
#TARGET_LINK_LIBRARIES( ${PROJECT_NAME} ${SDL2_LIBRARIES} )

