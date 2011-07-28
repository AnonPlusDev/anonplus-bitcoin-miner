#include "miningthread.h"


QString MiningThread::rpc_url = DEF_RPC_URL;

MiningThread::MiningThread(QObject *parent) :
    QThread(parent),
    have_longpool(false),
    want_longpool(false)
{
}


void MiningThread::run()
{
    this->setPriority(QThread::LowestPriority);
    manager = new QNetworkAccessManager(this);

}

bool MiningThread::getWork(workio_cmd *wc)
{
    work* ret_work;
    int failures = 0;
    try {
        ret_work = new work();
    } catch(...)
    {
        return false;
    }


}

QJson::Parser MiningThread::json_rpc_call(const QString& _url,
                     const QString & _userpass , const QByteArray & _rpc_req,
                     bool _longpool_scan,
                     bool _longpool
                     )
{
    QJson::Parser val, err_val, res_val;
    int rc;
    bool lp_scanning = false;

    connect(this->manager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(networkReplyFinished(QNetworkReply*)));


    QUrl url = QUrl(_url);
    if(!_userpass.isEmpty())
        url.setUserInfo(_userpass);
    if (_longpool_scan)
       lp_scanning = want_longpool && !have_longpool;

    QNetworkRequest netRec;


    netRec.setUrl(url);
    netRec.setHeader(QNetworkRequest::ContentTypeHeader,  'application/json');
    netRec.setRawHeader("Expect", "");
    netRec.setRawHeader("User-Agent", PROGRAM_NAME);
    //netRec.setHeader(QNetworkRequest::ContentLengthHeader, net);

    if(lp_scanning)
    {
        // TODO: SET LPSCANNING RAW HEADER
    }

    this->manager->put(netRec, _rpc_req);
}

void MiningThread::networkReplyFinished ( QNetworkReply * reply )
{

}

bool MiningThread::submitWork(workio_cmd *wc)
{

}

bool MiningThread::get_upstream_work(work* work)
{
    QJson::Parser parser;


}



