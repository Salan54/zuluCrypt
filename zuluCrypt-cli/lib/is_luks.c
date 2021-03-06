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

#include "includes.h"

static int _is_luks( const char * dev )
{
	struct crypt_device * cd;
	int st ;
	
	if( crypt_init( &cd,dev ) != 0 ){
		return 0 ;
	}
	
	st = crypt_load( cd,NULL,NULL ) ;
	
	crypt_free( cd );
	
	return st == 0 ;
}

int zuluCryptVolumeIsLuks( const char * dev )
{		
	string_t st ;
	int fd ;
	int r ;
	if( StringPrefixMatch( dev,"/dev/",5 ) ){
		return _is_luks( dev ) ;
	}else{
		/*
		 * zuluCryptAttachLoopDeviceToFile() is defined in ./create_loop.c
		 */
		if( zuluCryptAttachLoopDeviceToFile( dev,O_RDWR,&fd,&st ) ){
			r = _is_luks( StringContent( st ) ) ;
			StringDelete( &st ) ;
			close( fd ) ;
			return r ;
		}else{
			return 0 ;
		}
	}
}

int zuluCryptVolumeIsNotLuks( const char * dev )
{		
	return !zuluCryptVolumeIsLuks( dev ) ;
}
