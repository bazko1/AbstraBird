#ifndef DIRMANAGER_H
#define DIRMANAGER_H
#include <iostream>
#ifdef _VAR
    #define path _VAR
#else
    #define path "error"
#endif
class DirManager {
public:
    static std::string getDir(char* dir) {
        const char* c = _VAR;
        std::string ret = std::string(c);
        ret.append(dir);
        return ret;
    }
};
#endif // DIRMANAGER_H
