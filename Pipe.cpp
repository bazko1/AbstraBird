//
// Created by bazyli on 1/9/18.
//

#include "Pipe.h"
template <typename T>
const int Pipe<T>::getHeight() const {
    return Height;
}

template <typename T>
const int Pipe<T>::getWidth() const {
    return Width;
}
template <typename T>
int Pipe<T>::getX() const {
    return x;
}
template <typename T>
void Pipe<T>::setX(int x) {
    Pipe::x = x;

}
template <typename T>
void Pipe<T>::Move(int dx , int dy) {

    Pipe::x += dx;
    Pipe::y += dy;

}

template <typename T>
int Pipe<T>::getY() const {
    return y;
}
template <typename T>
void Pipe<T>::setY(int y) {
    Pipe::y = y;
}
template <typename T>
void Pipe<T>::Draw() {

}

