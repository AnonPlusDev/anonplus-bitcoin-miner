#ifndef MINERCLASS_H
#define MINERCLASS_H

#include <QObject>
#include <QDateTime>
#ifndef WIN32
extern "C" {
#include <sys/resource.h>
}
#endif

#define PROGRAM_NAME		"anonplus-bitcoin-pool-miner"
#define DEF_RPC_URL		"http://127.0.0.1:8332/"
#define DEF_RPC_USERNAME	"rpcuser"
#define DEF_RPC_PASSWORD	"rpcpass"
#define DEF_RPC_USERPASS	DEF_RPC_USERNAME ":" DEF_RPC_PASSWORD

class MinerClass : public QObject
{
    int pools_active;
    qint64 total_tv_start;
    qint64 total_tv_end;
    qint64 tm;
    qint16 num_processors;
    qint16 opt_n_threads;

    Q_OBJECT
public:
    explicit MinerClass(QObject *parent = 0);

signals:

public slots:

};

#endif // MINERCLASS_H
