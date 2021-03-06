/*
 *
 *  Copyright (c) 2012
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


#include "checkvolumetype.h"

checkvolumetype::checkvolumetype( QString path )
{
	m_device = path.replace( "\"","\"\"\"" ) ;
}

void checkvolumetype::start()
{
	QThreadPool::globalInstance()->start( this ) ;
}

void checkvolumetype::run()
{
	if( utility::isLuks( m_device ) ){
		m_type = tr( "luks" ) ;
	}else{
		m_type = tr( "plain" ) ;
	}
}

checkvolumetype::~checkvolumetype()
{
	emit complete( m_type );
}
