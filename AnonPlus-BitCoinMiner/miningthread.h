#ifndef MININGTHREAD_H
#define MININGTHREAD_H

#include <QThread>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <qjson/qjson_export.h>
#include <qjson/parser.h>
#include "global.h"
#ifdef __linux
#include <sched.h>
#endif

enum workio_commands {
        WC_GET_WORK,
        WC_SUBMIT_WORK,
};

struct work {
        unsigned char	data[128];
        unsigned char	hash1[64];
        unsigned char	midstate[32];
        unsigned char	target[32];

        unsigned char	hash[32];
};

struct workio_cmd {
        enum workio_commands	cmd;
        struct thr_info		*thr;
        union {
                struct work	*work;
        } u;
};



class MiningThread : public QThread
{

    static QString rpc_url;
    QNetworkAccessManager *manager;
    QJson::Parser json_rpc_call(const QString &,
                         const QString &, const QString &,
                         bool longpool_scan,
                         bool longpool
                         );

    Q_OBJECT
public:
    explicit MiningThread(QObject *parent = 0);
    void run();
    bool submitWork(workio_cmd *wc);
    bool getWork(workio_cmd *wc);
    bool get_upstream_work(work *work);




signals:

public slots:
    void networkReplyFinished ( QNetworkReply * reply );

};

#endif // MININGTHREAD_H
