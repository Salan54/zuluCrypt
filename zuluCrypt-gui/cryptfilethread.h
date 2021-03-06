/*
 *
 *  Copyright ( c ) 2012
 *  name : mhogo mchungu
 *  email: mhogomchungu@gmail.com
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 2 of the License, or
 *  ( at your option ) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef CRYPTFILETHREAD_H
#define CRYPTFILETHREAD_H

#include <QObject>
#include <QRunnable>
#include <QProcess>
#include <QString>
#include <QThreadPool>
#include <QFile>
#include <QTextStream>

#include "utility.h"
#include "../zuluCrypt-cli/constants.h"
#include "../zuluCrypt-cli/bin/bash_special_chars.h"
#include "md5/md5.h"
#include <sys/mman.h>

#include <string.h>

class cryptfilethread : public QObject,public QRunnable
{
	Q_OBJECT
public:
	explicit cryptfilethread( QString source,QString dest,QString keySource,QString key,QString task );
	~cryptfilethread() ;
signals:
	void progressUpdate( int );
	void titleUpdate( QString );
	void complete( int ) ;
	void md5mismach( void ) ;
	void enableCancel( void ) ;
	void disableCancel( void ) ;
public slots:
	void terminate( void );
	void start( void );
private:
	void calculateMd5( QString path,char * result ) ;
	void run( void );
	int encrypt( void );
	int decrypt( void );
	int openMapper( QString path );
	int closeMapper( QString path );
	QString m_source ;
	QString m_dest ;
	QString m_keySource ;
	QString m_key ;
	QString m_task ;
	QString m_mapperPath ;
	int m_status ;
};

#endif // CRYPTFILETHREAD_H
