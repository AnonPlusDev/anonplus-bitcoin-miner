#include "miningthread.h"


QString MiningThread::rpc_url = DEF_RPC_URL;

MiningThread::MiningThread(QObject *parent) :
    QThread(parent)
{
}


void MiningThread::run()
{
    this->setPriority(QThread::LowestPriority);

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

bool MiningThread::submitWork(workio_cmd *wc)
{

}

bool MiningThread::get_upstream_work(work* work)
{
    QJson::Parser parser;

}



