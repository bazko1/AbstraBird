cmake_minimum_required(VERSION 3.7)
project(AbstraBird)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp IDrawable.h IIntersects.h Bird.cpp Bird.h Obstacle.cpp Obstacle.h ObstacleSet.cpp ObstacleSet.h IMovable.h GameLogic.cpp GameLogic.h Window.cpp Window.h cmake-build-debug/Game.cpp cmake-build-debug/Game.h)
add_executable(AbstraBird ${SOURCE_FILES})