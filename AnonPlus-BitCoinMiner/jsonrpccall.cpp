/*
 * Copyright 2011 bnight <bnigt at hushmail.com>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option)
 * any later version.  See COPYING for more details.
 */

#include "jsonrpccall.h"

JsonRpcCall::JsonRpcCall(QObject *parent) :
    QObject(parent),
    manager(NULL),
    has_longpool(false)

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

    netRec.setHeader(QNetworkRequest::ContentTypeHeader,  "application/json");
    netRec.setRawHeader("Expect", "");
    netRec.setRawHeader("User-Agent", "cpuminer 1.0.2");

    netRec.setHeader(QNetworkRequest::ContentLengthHeader, RCP_REQ.size());

    QList<QByteArray> headersPairs =   netRec.rawHeaderList();
    qDebug() << "++++++++++++++++++++++++++++++++++++++++";
    qDebug() << "+           REQUEST HEADERS            +";
    qDebug() << "++++++++++++++++++++++++++++++++++++++++";
    for(int i=0; i < headersPairs.size(); ++i )
    {
        QString tmp("");
        tmp += headersPairs.at(i);
        tmp += " : ";
        tmp += netRec.rawHeader(headersPairs.at(i));
        qDebug() << tmp;
    }
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
    qDebug() << "++++++++++++++++++++++++++++++++++++++++";
    qDebug() << "+           RESPONSE HEADERS           +";
    qDebug() << "++++++++++++++++++++++++++++++++++++++++";
    QList<QNetworkReply::RawHeaderPair> headersPairs =   reply->rawHeaderPairs();

    for(int i=0; i < headersPairs.size(); ++i )
    {
        QString tmp("");
        tmp += headersPairs.at(i).first;
        tmp += " : ";
        tmp += headersPairs.at(i).second;
        qDebug() << tmp;
    }
    if(reply->hasRawHeader("X-Long-Polling"))
    {
        has_longpool = true;
        longpool_path = reply->rawHeader("X-Long-Polling");
    }

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
