/*
 * Copyright 2011 bnight <bnigt at hushmail.com>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option)
 * any later version.  See COPYING for more details.
 */

#ifndef GLOBAL_H
#define GLOBAL_H

#include <iostream>
#include <QString>
#include <QUrl>
#define MAX_POOLS (32)
#define DEF_RPC_URL		"http://127.0.0.1:8332/"

#undef unlikely
#undef likely
#if defined(__GNUC__) && (__GNUC__ > 2) && defined(__OPTIMIZE__)
#define unlikely(expr) (__builtin_expect(!!(expr), 0))
#define likely(expr) (__builtin_expect(!!(expr), 1))
#else
#define unlikely(expr) (expr)
#define likely(expr) (expr)
#endif

void applog(int prio, const char *fmt, ...);

static int opt_n_threads;
static int num_processors;

static const QByteArray RCP_REQ("{\"method\": \"getwork\", \"params\": [], \"id\":0}\r\n");
QUrl convertToUrl(const QString &schema, QString& url, const QString& username, const QString& password, const QString& port );


#define PROGRAM_NAME		"anonplus-bitcoin-miner 0.001"

#define DEF_RPC_URL		"http://127.0.0.1:8332/"
#define DEF_RPC_USERNAME	"rpcuser"
#define DEF_RPC_PASSWORD	"rpcpass"
#define DEF_RPC_USERPASS	DEF_RPC_USERNAME ":" DEF_RPC_PASSWORD


#endif // GLOBAL_H
