#include "miningthread.h"


QString MiningThread::rpc_url = DEF_RPC_URL;

MiningThread::MiningThread(QObject *parent) :
    QThread(parent)

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
                     const QString & _userpass , const QString & _rpc_req,
                     bool _longpool_scan,
                     bool _longpool
                     )
{
    QJson::Parser val, err_val, res_val;
    int rc;
    connect(this->manager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(networkReplyFinished(QNetworkReply*)));

    QUrl url = QUrl(_url);
    if(!_userpass.isEmpty())
        url.setUserInfo(_userpass);
    QNetworkRequest netRec;
    netRec.setUrl(url);

    this->manager->get(netRec);
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



