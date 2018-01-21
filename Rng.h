#ifndef RNG_H
#define RNG_H
#include <random>
#include "algorithm"
#include <time.h>
#include <unistd.h>
template <typename T, template <typename,typename = std::allocator<T>> class Container>
class RNG
{
    Container<T> cont;

public:


    RNG(T a, T b, double granulity){
        this->cont = Container<T>();
        for(T i=a; i<=b; i+=(T)granulity) {
            cont.push_back(i);

        }
    }

    T getRandom(){

        std::random_shuffle( cont.begin(), cont.end() );
        return cont[0];
    }

};


#endif // RNG_H
