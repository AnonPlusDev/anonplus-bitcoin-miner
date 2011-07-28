#include "minerclass.h"

QString MinerClass::rpc_url = DEF_RPC_URL;

MinerClass::MinerClass(QObject *parent) :
    QObject(parent),
    have_longpool(false),
    want_longpool(false)
{
    manager = new QNetworkAccessManager(this);

    this->json_rpc_call("localhost", QString(), "TEST", false, false);
}


bool MinerClass::getWork(workio_cmd *wc)
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

QJson::Parser MinerClass::json_rpc_call(const QString& _url,
                     const QString & _userpass , const QByteArray & _rpc_req,
                     bool _longpool_scan,
                     bool _longpool
                     )
{
    QJson::Parser val, err_val, res_val;
    int rc;
    bool lp_scanning = false;




    QUrl url = QUrl(_url);
    url.setScheme("http");
    if(!_userpass.isNull())
        url.setUserInfo(_userpass);
    if (_longpool_scan)
       lp_scanning = want_longpool && !have_longpool;

    QNetworkRequest netRec(url);
    netRec.setHeader(QNetworkRequest::ContentTypeHeader,  "application/json");
    //netRec.setRawHeader("Expect", "");
    //netRec.setRawHeader("User-Agent", PROGRAM_NAME);
    //netRec.setHeader(QNetworkRequest::ContentLengthHeader, net);

    if(lp_scanning)
    {
        // TODO: SET LPSCANNING RAW HEADER
    }

    QNetworkReply *reply = this->manager->put(netRec, _rpc_req);


}

void MinerClass::networkReplyFinished ( QNetworkReply * reply )
{
    qDebug("reply reache");
    reply->deleteLater();
}

bool MinerClass::submitWork(workio_cmd *wc)
{

}

bool MinerClass::get_upstream_work(work* work)
{
    QJson::Parser parser;


}
