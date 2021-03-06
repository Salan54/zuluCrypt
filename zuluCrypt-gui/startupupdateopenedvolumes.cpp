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

#include <QProcess>
#include <QString>
#include <QStringList>
#include "startupupdateopenedvolumes.h"
#include "../zuluCrypt-cli/constants.h"

startupupdateopenedvolumes::startupupdateopenedvolumes()
{
}

void startupupdateopenedvolumes::start()
{
	QThreadPool::globalInstance()->start( this );
}

void startupupdateopenedvolumes::run()
{
	QProcess p ;
	p.start( QString( ZULUCRYPTzuluCrypt ) + QString( " -L" ) );
	p.waitForFinished();
	m_status = p.exitCode() ;

	QStringList l = QString( p.readAll() ).split( "\n" ) ;

	if( m_status ){
		return ;
	}
	p.close();

	int j = l.size() - 1 ;

	if( j == 0 ){
		return ;
	}
	QStringList entry ;

	for( int i = 0 ; i < j ; i++ ){
		entry = l.at( i ).split( "\t" );
		if( entry.size() >= 3 ){
			emit addItemToTable( entry.at( 0 ),entry.at( 1 ),entry.at( 2 ) ) ;
		}
	}
}

startupupdateopenedvolumes::~startupupdateopenedvolumes()
{
	emit finished( m_status );
}
