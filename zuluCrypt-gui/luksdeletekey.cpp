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

#include "luksdeletekey.h"
#include "zulucrypt.h"
#include "../zuluCrypt-cli/constants.h"
#include "utility.h"

#include <QObject>
#include <Qt>
#include <QObject>
#include <QFileDialog>
#include <QRadioButton>
#include <QPushButton>
#include <QMessageBox>
#include <QCloseEvent>
#include <QIcon>
#include <QKeyEvent>

namespace Ui {
    class luksdeletekey;
}

luksdeletekey::luksdeletekey( QWidget * parent ) :
	QDialog( parent ),
	m_ui( new Ui::luksdeletekey )
{
	m_isWindowClosable = true ;
	m_ui->setupUi( this );

	this->setFixedSize( this->size() );
	this->setFont( parent->font() );

	m_ui->lineEditVolumePath->clear();

	connect( m_ui->pushButtonDelete,SIGNAL( clicked() ),this,SLOT( pbDelete() ) ) ;
	connect( m_ui->pushButtonCancel,SIGNAL( clicked() ),this,SLOT( pbCancel() ) ) ;
	connect( m_ui->rbPassphrase,SIGNAL( toggled( bool ) ),this,SLOT( rbPassphrase() ) ) ;
	connect( m_ui->rbPassphraseFromFile,SIGNAL( toggled( bool ) ),this,SLOT( rbPassphraseFromFile() ) ) ;
	connect( m_ui->pushButtonOpenKeyFile,SIGNAL( clicked() ),this,SLOT( pbOpenKeyFile() ) ) ;
	connect( m_ui->pushButtonOpenVolume,SIGNAL( clicked() ),this,SLOT( pbOpenVolume() ) );
	connect( m_ui->pushButtonOpenPartition,SIGNAL( clicked() ),this,SLOT( pbOpenPartition() ) ) ;
}

void luksdeletekey::closeEvent( QCloseEvent * e )
{
	e->ignore();
	if(  m_isWindowClosable ){
		pbCancel();
	}
}

void luksdeletekey::rbPassphrase()
{
	m_ui->lineEditPassphrase->setToolTip( tr( "enter a key" ) );
	m_ui->labelPassphrase->setText( tr( "key" ) );
	m_ui->lineEditPassphrase->setEchoMode( QLineEdit::Password );
	m_ui->lineEditPassphrase->clear();
	m_ui->pushButtonOpenKeyFile->setEnabled( false );
	m_ui->pushButtonOpenKeyFile->setIcon( QIcon( QString( ":/passphrase.png" ) ) );
	m_ui->lineEditPassphrase->setFocus();
}

void luksdeletekey::rbPassphraseFromFile()
{
	m_ui->lineEditPassphrase->setToolTip( tr( "enter a path to a keyfile location" ) );
	m_ui->labelPassphrase->setText( tr( "keyfile path" ) );
	m_ui->lineEditPassphrase->setEchoMode( QLineEdit::Normal );
	m_ui->lineEditPassphrase->clear();
	m_ui->pushButtonOpenKeyFile->setEnabled( true );
	m_ui->pushButtonOpenKeyFile->setIcon( QIcon( QString( ":/keyfile.png" ) ) );
}

void luksdeletekey::pbOpenKeyFile()
{
	QString Z = QFileDialog::getOpenFileName( this,tr( "key file with a passphrase to delete" ),QDir::homePath(),0 );
	m_ui->lineEditPassphrase->setText( Z );
	if( m_ui->lineEditVolumePath->text().isEmpty() ){
		m_ui->lineEditVolumePath->setFocus();
	}else{
		m_ui->pushButtonDelete->setFocus();
	}
}

void luksdeletekey::ShowUI()
{
	enableAll();
	m_ui->rbPassphrase->setEnabled( true );
	m_ui->labelPassphrase->setText( tr( "key" ) );
	m_ui->rbPassphrase->setChecked( true );

	if( m_ui->lineEditVolumePath->text().isEmpty() ){
		m_ui->lineEditVolumePath->setFocus();
	}else{
		m_ui->lineEditPassphrase->setFocus();
	}
	m_ui->pushButtonOpenPartition->setIcon( QIcon( QString( ":/partition.png" ) ) );
	m_ui->pushButtonOpenVolume->setIcon( QIcon( QString( ":/file.png" ) ) );
	this->show();
}

void luksdeletekey::ShowUI( QString path )
{
	m_ui->lineEditVolumePath->setText( path );
	ShowUI() ;
}

void luksdeletekey::disableAll()
{
	m_ui->groupBox->setEnabled( false );
	m_ui->label->setEnabled( false );
	m_ui->labelPassphrase->setEnabled( false );
	m_ui->lineEditPassphrase->setEnabled( false );
	m_ui->lineEditVolumePath->setEnabled( false );
	m_ui->pushButtonCancel->setEnabled( false );
	m_ui->pushButtonDelete->setEnabled( false );
	m_ui->pushButtonOpenKeyFile->setEnabled( false );
	m_ui->pushButtonOpenPartition->setEnabled( false );
	m_ui->pushButtonOpenVolume->setEnabled( false );
	m_ui->rbPassphrase->setEnabled( false );
	m_ui->rbPassphraseFromFile->setEnabled( false );
}

void luksdeletekey::enableAll()
{
	m_ui->groupBox->setEnabled( true );
	m_ui->label->setEnabled( true );
	m_ui->labelPassphrase->setEnabled( true );
	m_ui->lineEditPassphrase->setEnabled( true );
	m_ui->lineEditVolumePath->setEnabled( true );
	m_ui->pushButtonCancel->setEnabled( true );
	m_ui->pushButtonDelete->setEnabled( true );
	m_ui->pushButtonOpenKeyFile->setEnabled( true );
	m_ui->pushButtonOpenPartition->setEnabled( true );
	m_ui->pushButtonOpenVolume->setEnabled( true );
	m_ui->rbPassphrase->setEnabled( true );
	m_ui->rbPassphraseFromFile->setEnabled( true );
}

void luksdeletekey::pbCancel()
{
	HideUI() ;
}

void luksdeletekey::pbOpenPartition()
{
	openvolume * op = new openvolume( this );
	op->showLuksOnly();
	connect( op,SIGNAL( clickedPartition( QString ) ),this,SLOT( ShowUI( QString ) ) );
	connect( op,SIGNAL( HideUISignal() ),op,SLOT( deleteLater() ) );
	op->ShowAllPartitions();
}

void luksdeletekey::pbDelete()
{
	DialogMsg msg( this ) ;

	QString path = m_ui->lineEditVolumePath->text() ;
	m_volumePath = utility::resolvePath( path ) ;

	QString passphrase = m_ui->lineEditPassphrase->text() ;

	if(  m_volumePath.isEmpty() || passphrase.isEmpty() ){
		return msg.ShowUIOK( tr( "ERROR!" ),tr( "atleast one required field is empty" ) );
	}
	m_volumePath.replace( "\"","\"\"\"" ) ;
	passphrase.replace( "\"","\"\"\"" ) ;

	QStringList l = utility::luksEmptySlots( m_volumePath ) ;
	if( l.isEmpty() ){
		return msg.ShowUIOK( tr( "ERROR!" ),tr( "volume is not a luks volume" ) );
	}else if( l.at( 0 ) == QString( "1" ) ){
		QString s = tr( "There is only one last key in the volume." );
		s = s + tr( "\nDeleting it will make the volume unopenable and lost forever." ) ;
		s = s + tr( "\nAre you sure you want to delete this key?" );

		if(  msg.ShowUIYesNoDefaultNo( tr( "WARNING" ),s ) == QMessageBox::No ){
			return ;
		}
	}else{
		QString s = tr( "are you sure you want to delete a key from this volume?" ) ;
		if(  msg.ShowUIYesNoDefaultNo( tr( "WARNING" ),s ) == QMessageBox::No ){
			return ;
		}
	}

	QString passType ;
	if (  m_ui->rbPassphraseFromFile->isChecked() == true ){
		passphrase = utility::resolvePath( passphrase ) ;
		passType = QString( "-f" ) ;
	}else{
		passType = QString( "-f" ) ;
		passphrase = socketSendKey::getSocketPath() ;

		socketSendKey * s = new socketSendKey( this,passphrase,m_ui->lineEditPassphrase->text().toAscii() ) ;
		s->sendKey();
	}

	QString exe = QString( "%1 -k -r -d \"%2\" %3 \"%4\"" ).arg( QString( ZULUCRYPTzuluCrypt ) ).arg( m_volumePath ).arg( passType ).arg( passphrase );

	m_isWindowClosable = false ;

	disableAll();

	runInThread * ldk = new runInThread( exe ) ;
	connect( ldk,SIGNAL( finished( int ) ),this,SLOT( threadfinished( int ) ) ) ;
	ldk->start();
}

void luksdeletekey::threadfinished( int status )
{
	DialogMsg msg( this ) ;
	m_isWindowClosable = true ;
	QStringList l ;
	QString success;
	switch(  status ){
		case 0 :
			l = utility::luksEmptySlots( m_volumePath ) ;
			if( l.isEmpty() ){
				success = tr( "key removed successfully." ) ;
			}else{
				success = tr( "key removed successfully.\n%1 / %2 slots are now in use" ).arg( l.at( 0 ) ).arg( l.at( 1 ) );
			}
			msg.ShowUIOK( tr( "SUCCESS!" ),success );
			return HideUI() ;
		case 2 : msg.ShowUIOK( tr( "ERROR!" ),tr( "there is no key in the volume that match the presented key" ) ) ;				break ;
		case 3 : msg.ShowUIOK( tr( "ERROR!" ),tr( "could not open the volume" ) ) ;								break ;
		case 4 : msg.ShowUIOK( tr( "ERROR!" ),tr( "insufficient privilege to open a system device,\
only root user or members of group zulucrypt-system can do that" ) ) ;											break ;
		case 5 : msg.ShowUIOK( tr( "ERROR!" ),tr( "could not open the volume in write mode" ) ) ;						break ;
		case 6 : msg.ShowUIOK( tr( "ERROR!" ),tr( "insufficient memory to hold your response" ) ) ;						break ;
		case 7 : msg.ShowUIOK( tr( "ERROR!" ),tr( "operation terminated per user request" ) ) ;							break ;
		case 8 : msg.ShowUIOK( tr( "ERROR!" ),tr( "can not get passphrase in silent mode" ) ) ;							break ;
		case 9 : msg.ShowUIOK( tr( "ERROR!" ),tr( "insufficient memory to hold passphrase" ) ) ;						break ;
		case 10: msg.ShowUIOK( tr( "ERROR!" ),tr( "one or more required argument(s) for this operation is missing" ) );				break ;
		case 11: msg.ShowUIOK( tr( "ERROR!" ),tr( "keyfile does not exist" ) );									break;
		case 12: msg.ShowUIOK( tr( "ERROR!" ),tr( "could not get enough memory to open the key file") );					break ;
		case 13: msg.ShowUIOK( tr( "ERROR!" ),tr( "insufficient privilege to open key file for reading" ) );					break ;
		case 14: msg.ShowUIOK( tr( "ERROR!" ),tr( "could not get a key from a socket" ) );							break ;
		case 110:msg.ShowUIOK( tr( "ERROR!" ),tr( "can not find a partition that match presented UUID" ) );					break ;
		default :msg.ShowUIOK( tr( "ERROR!" ),tr( "unrecognized ERROR! with status number %1 encountered" ).arg( status ) );
	}

	enableAll();

	if( status == 2 ){
		m_ui->lineEditPassphrase->clear();
		m_ui->lineEditPassphrase->setFocus();
	}
}

void luksdeletekey::pbOpenVolume()
{
	QString Z = QFileDialog::getOpenFileName( this,tr( "volume path" ),QDir::homePath(),0 );
	m_ui->lineEditVolumePath->setText( Z );
	if( m_ui->lineEditPassphrase->text().isEmpty() ){
		m_ui->lineEditPassphrase->setFocus();
	}else{
		m_ui->pushButtonDelete->setFocus() ;
	}
}

void luksdeletekey::HideUI()
{
	this->hide();
	emit HideUISignal();
}

luksdeletekey::~luksdeletekey()
{
	delete m_ui ;
}
