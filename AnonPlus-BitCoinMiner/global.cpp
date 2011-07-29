/*
 * Copyright 2011 bnight <bnigt at hushmail.com>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option)
 * any later version.  See COPYING for more details.
 */

#include "global.h"


void applog(int prio, const char *fmt, ...)
{
    // TODO: Improve this log
    std::cout << fmt << std::endl;
}


QUrl convertToUrl(const QString &schema, QString& url, const QString& username, const QString& password, const QString& port )
{

}
