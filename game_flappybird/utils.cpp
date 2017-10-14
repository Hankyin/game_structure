#include "utils.h"

Utils::Utils()
{

}

int Utils::getRand(int start, int end)
{
    //得到[start,end]之间的随机整数
    //end必须大于start
    //每次要更换种子值，否则得到的随机数是一样的。
    //用时间当种子有问题，在短时内大量调用该函数会导致返回相同的随机数
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()) * seed);
    seed++;
    return qrand()%(end - start) + start;
}

long Utils::seed = 0;
