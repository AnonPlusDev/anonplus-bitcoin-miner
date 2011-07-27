#include "pools.h"

Pools::Pools(QObject *parent) :
    QObject(parent),
    pools(new QVector<Pool*>(MAX_POOLS))
{

}


void Pools::addPool()
{
    Pool* pool;
    try {
        pool = new Pool();
    } catch(...)
    {

    }

}

quint8 Pools::get_total_pools() const
{
    return total_pools;
}

Pools::~Pools()
{
    for(int i = 0; i < pools->size(); ++i)
    {
        delete pools->at(i);
    }
    delete pools;
}
