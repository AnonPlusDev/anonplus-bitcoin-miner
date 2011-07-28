#include "miningthread.h"




MiningThread::MiningThread(QObject *parent) :
    QThread(parent)
{
}


void MiningThread::run()
{
    qDebug("Running run from minningThread");
    this->setPriority(QThread::LowestPriority);
//    manager = new QNetworkAccessManager(this);
//    this->json_rpc_call("htpp://localhost", QString(), "TEST", true, true);
    MinerClass* mc = new MinerClass();
    this->exec();

}





