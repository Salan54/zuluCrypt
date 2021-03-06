/*
 *
 *  Copyright ( c ) 2011
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

#ifndef CREATEKEYFILETHREAD_H
#define CREATEKEYFILETHREAD_H

#include <QObject>
#include <QThread>
#include <QProcess>
#include <QFile>
#include <QTextStream>

#include <string.h>

class createkeyfilethread : public QThread
{
	Q_OBJECT
public:
	explicit createkeyfilethread( QString,int );
	~createkeyfilethread();
signals:
	void exitStatus( int );
public slots:
	void cancelOperation( void );
private:
	void run( void );
	QString m_path ;
	int m_rng ;
	int m_cancelled ;
	int m_qfread  ;
	int m_qfwrite ;
};

#endif // CREATEKEYFILETHREAD_H
