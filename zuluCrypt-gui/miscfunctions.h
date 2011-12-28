/*
 * 
 *  Copyright (c) 2011
 *  name : mhogo mchungu
 *  email: mhogomchungu@gmail.com
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef MISCFUNCTIONS_H
#define MISCFUNCTIONS_H

#include <QString>
#include <QStringList>
#include <blkid/blkid.h>
#include <QProcess>
#include <QFile>
#include <QFile>
#include <QDir>

#include "../zuluCrypt-cli/executables.h"

class miscfunctions
{
public:
	miscfunctions();
	static QStringList luksEmptySlots(QString volumePath) ;
	static bool isLuks(QString volumePath) ;
	static QString mtab(QString) ;
	static QString readMtab(QByteArray * mtab,QString entry);
	static bool isUUIDvalid(QString);
	static QStringList deviceProperties(QString device) ;
	static void addToFavorite(QString dev, QString m_point);
	static QStringList readFavorites(void);
	static void removeFavoriteEntry(QString);
};

#endif // MISCFUNCTIONS_H