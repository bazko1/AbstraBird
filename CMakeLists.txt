cmake_minimum_required(VERSION 3.7)
project(AbstraBird)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp IDrawable.h IIntersects.h Bird.cpp Bird.h Obstacle.cpp Obstacle.h ObstacleSet.cpp ObstacleSet.h IUpdate.h GameLogic.cpp GameLogic.h Window.cpp Window.h cmake-build-debug/Game.cpp cmake-build-debug/Game.h InputListener.cpp InputListener.h Pipe.cpp Pipe.h)
add_executable(AbstraBird ${SOURCE_FILES})