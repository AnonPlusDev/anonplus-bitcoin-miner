/*
 * Copyright 2011 bnight <bnigt at hushmail.com>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option)
 * any later version.  See COPYING for more details.
 */

#ifndef JSONRPCCALL_H
#define JSONRPCCALL_H

#include <QtNetwork>
#include <QWaitCondition>
#include <qjson/parser.h>
#include "global.h"

class JsonRpcCall : public QObject
{
    Q_OBJECT
public:
    explicit JsonRpcCall(QObject *parent = 0);
    ~JsonRpcCall();
    void rpcCall(const QUrl& _url,
                 bool _longpool_scan,
                 bool _longpool);

private:
    QUrl url;
    bool longpool_scan;
    bool longbpool;
    QNetworkAccessManager *manager;

signals:

public slots:
    void networkReplyFinished ( QNetworkReply * reply );
signals:
    void rcpCallReply(JsonRpcCall*, QVariant );

};

#endif // JSONRPCCALL_H
