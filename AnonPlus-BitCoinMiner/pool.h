#ifndef POOL_H
#define POOL_H

#include <QObject>
#include <QMutex>
/*
int pool_no;
int prio;
int accepted, rejected;
bool submit_fail;
bool idle;
bool has_rolltime;
bool probed;
bool enabled;
unsigned int getwork_requested;
unsigned int stale_shares;
unsigned int discarded_work;
unsigned int localgen_occasions;
unsigned int remotefail_occasions;
struct timeval tv_idle;

char *rpc_url;
char *rpc_userpass;
char *rpc_user, *rpc_pass;
*/

class Pool : public QObject
{
private:
    int pool_no;
    int prio;
    int accepted, rejected;
    bool submit_fail;
    bool idle;
    bool has_rolltime;
    bool probed;
    bool enabled;
    unsigned int getwork_requested;
    unsigned int stale_shares;
    unsigned int discarded_work;
    unsigned int localgen_occasions;
    unsigned int remotefail_occasions;

    QString rpc_url, rpc_user, rpc_pass;
    QMutex mutex;


    Q_OBJECT
public:
    explicit Pool(QObject *parent = 0);

    bool tset(bool &var);

signals:

public slots:

};

#endif // POOL_H
