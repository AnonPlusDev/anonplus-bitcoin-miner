#include "jsonrpccall.h"

JsonRpcCall::JsonRpcCall(QObject *parent) :
    QObject(parent),
    manager(NULL)

{
   qDebug("Constructer");
}

JsonRpcCall::~JsonRpcCall()
{

}


void JsonRpcCall::rpcCall(const QUrl& _url,
                          bool _longpool_scan,
                          bool _longpool){
    qDebug("rpcCall reached");
    longpool_scan = _longpool_scan;
    longbpool = _longpool;


    qDebug("Run()");
    manager = new QNetworkAccessManager(this);
    //this->json_rpc_call("localhost", QString(), "TEST", false, false);
//    this->setPriority(QThread::LowestPriority);
//    exec();

    int rc;
    bool lp_scanning = false;

    connect(this->manager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(networkReplyFinished(QNetworkReply*)));




    qDebug() << "Url: " << _url.toString();
    QNetworkRequest netRec;
    netRec.setUrl(_url);

    netRec.setHeader(QNetworkRequest::ContentTypeHeader,  'application/json');
    netRec.setRawHeader("Expect", "");
    netRec.setRawHeader("User-Agent", PROGRAM_NAME);

    netRec.setHeader(QNetworkRequest::ContentLengthHeader, RCP_REQ.size());
/*
    if(lp_scanning)
    {
        // TODO: SET LPSCANNING RAW HEADER
    }
 */

    this->manager->put(netRec, RCP_REQ);

}

void JsonRpcCall::networkReplyFinished ( QNetworkReply * reply )
{

    qDebug("Reply Reached!");
    bool ok = false;
    QJson::Parser* parser = new QJson::Parser();
    QVariant v(parser->parse(reply, &ok));
    if(ok)
    {
        qDebug("QJson OK");
        emit rcpCallReply(this, v);
    } else
    {
        qDebug("QJson Not OK");
        emit rcpCallReply(this, QVariant());
    }
    reply->deleteLater();
}
