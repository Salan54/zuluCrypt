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

#include "runinthread.h"
#include <QProcess>
#include <QDebug>

runInThread::runInThread( QString exe )
{
	m_exe = exe ;
	m_status = -1 ;
}

void runInThread::start()
{
	QThreadPool::globalInstance()->start( this );
}

void runInThread::run()
{
	QProcess p ;
	p.start( m_exe );
	p.waitForFinished( -1 ) ;
	m_status = p.exitCode() ;
	m_output = QString( p.readAllStandardOutput() ) ;
	p.close();
}

runInThread::~runInThread()
{
	emit finished( m_status );
	emit finished( m_status,m_output ) ;
}
