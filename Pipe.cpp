//
// Created by bazyli on 1/9/18.
//

#include "Pipe.h"

const int Pipe::getHeight() const {
    return Height;
}

const int Pipe::getWidth() const {
    return Width;
}

int Pipe::getX() const {
    return x;
}

void Pipe::setX(int x) {
    Pipe::x = x;

}

void Pipe::Move(int dx , int dy) {

    Pipe::x += dx;
    Pipe::y += dy;

}


int Pipe::getY() const {
    return y;
}

void Pipe::setY(int y) {
    Pipe::y = y;
}

void Pipe::Draw() {

}

