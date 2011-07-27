#ifndef POOLS_H
#define POOLS_H

#include <QObject>
#include <QVector>
#include "pool.h"
#include "global.h"

class Pools : public QObject
{

    //Pool *pools[MAX_POOLS];
    QVector<Pool*>  *pools;
    Pool* currentPool;
    quint8 total_pools;


    Q_OBJECT
public:
    explicit Pools(QObject *parent = 0);
    ~Pools();


    enum pool_strategy {
            POOL_FAILOVER,
            POOL_ROUNDROBIN,
            POOL_ROTATE,
            POOL_LOADBALANCE,
    };

    void addPool();
    quint8 get_total_pools() const;


signals:

public slots:



};

#endif // POOLS_H
