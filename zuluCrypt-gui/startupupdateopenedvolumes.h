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

#ifndef STARTUPUPDATEOPENEDVOLUMES_H
#define STARTUPUPDATEOPENEDVOLUMES_H

#include <QThreadPool>
#include <QRunnable>
#include <QObject>
#include <QString>

class startupupdateopenedvolumes : public QObject, public QRunnable
{
	Q_OBJECT
public:
	startupupdateopenedvolumes( void );
	void start( void );
	~startupupdateopenedvolumes();
signals:
	void addItemToTable( QString,QString,QString ) ;
	void finished( int );
private:
	void run( void ) ;
	int m_status ;
};

#endif // STARTUPUPDATEOPENEDVOLUMES_H
