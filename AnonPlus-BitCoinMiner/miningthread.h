#ifndef MININGTHREAD_H
#define MININGTHREAD_H

#include <QThread>
#include "minerclass.h"


class MiningThread : public QThread
{
    Q_OBJECT
    //Q_PROPERTY(bool want_longbool READ get_want_longpool WRITE set_want_longpool);
public:
    explicit MiningThread(QObject *parent = 0);
    void run();



private:


signals:

public slots:


};

#endif // MININGTHREAD_H
