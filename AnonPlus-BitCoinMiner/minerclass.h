#ifndef MINERCLASS_H
#define MINERCLASS_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <qjson/qjson_export.h>
#include <qjson/parser.h>
#include "global.h"

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

class MinerClass : public QObject
{
    static QString rpc_url;
    QNetworkAccessManager *manager;
    QJson::Parser json_rpc_call(const QString &,
                         const QString &, const QByteArray &,
                         bool longpool_scan,
                         bool longpool
                         );




    Q_OBJECT
    //Q_PROPERTY(bool want_longbool READ get_want_longpool WRITE set_want_longpool);
public:
    explicit MinerClass(QObject *parent = 0);

    bool submitWork(workio_cmd *wc);
    bool getWork(workio_cmd *wc);
    bool get_upstream_work(work *work);
    bool get_want_longpool() const { return want_longpool; }
    bool set_want_longpool(bool v) { want_longpool = v; }


private:
    bool have_longpool;
    bool want_longpool;


signals:

public slots:
    void networkReplyFinished ( QNetworkReply * reply );

};

#endif // MINERCLASS_H
