#include "pool.h"

Pool::Pool(QObject *parent) :
    QObject(parent)
{
}


bool Pool::tset(bool &var)
{
    bool ret;
    mutex.lock();
    ret = var;
    var = true;
    mutex.unlock();
    return ret;
}
