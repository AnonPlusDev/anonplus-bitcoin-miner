#ifndef MININGTHREAD_H
#define MININGTHREAD_H

#include <QThread>

class MiningThread : public QThread
{
    Q_OBJECT
public:
    explicit MiningThread(QObject *parent = 0);

signals:

public slots:

};

#endif // MININGTHREAD_H
