#ifndef UTILS_H
#define UTILS_H

#include "QTime"

class Utils
{
public:
    Utils();

    static int getRand(int start,int end);
private:
    static long seed;
};

#endif // UTILS_H
