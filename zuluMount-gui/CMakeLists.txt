cmake_minimum_required(VERSION 2.6)

add_definitions( -D_FILE_OFFSET_BITS=64 -Wextra -Wall -pedantic -std=c++0x -I${PROJECT_BINARY_DIR}/zuluMount-gui/ -I${PROJECT_BINARY_DIR}) 

set (UI_FILES 	../zuluCrypt-gui/dialogmsg.ui
		mainwindow.ui
		keydialog.ui
		mountpartition.ui
)

set(MOC_FILES 	mainwindow.h
		keydialog.h
		managepartitionthread.h
		mountpartition.h
		oneinstance.h
		auto_mount.h
		auto_mount_helper.h
		monitor_mountinfo.h
		../zuluCrypt-gui/dialogmsg.h
		../zuluCrypt-gui/socketsendkey.h 
		../zuluCrypt-gui/openmountpointinfilemanager.h
 )
	
set (SRC 	main.cpp
		auto_mount.cpp
		auto_mount_helper.cpp
		mainwindow.cpp
		keydialog.cpp
		managepartitionthread.cpp
		mountpartition.cpp
		oneinstance.cpp
		monitor_mountinfo.cpp
		../zuluCrypt-gui/dialogmsg.cpp
		../zuluCrypt-gui/userfont.cpp
		../zuluCrypt-gui/tablewidget.cpp
		../zuluCrypt-gui/socketsendkey.cpp 
		../zuluCrypt-gui/openvolumereadonly.cpp 
		../zuluCrypt-gui/openmountpointinfilemanager.cpp
		../zuluCrypt-gui/savemountpointpath.cpp
		../zuluCrypt-gui/utility.cpp
)

INCLUDE( ${QT_USE_FILE} )

QT4_WRAP_UI( UI ${UI_FILES} )

QT4_WRAP_CPP(MOC ${MOC_FILES} )

QT4_ADD_RESOURCES( TRAY_RC_SRCS icon.qrc )

INCLUDE_DIRECTORIES( ${CMAKE_BINARY_DIR} )

add_executable( zuluMount-gui ${MOC} ${UI} ${SRC} ${TRAY_RC_SRCS} )

TARGET_LINK_LIBRARIES( zuluMount-gui ${QT_LIBRARIES} ${blkid} zuluCryptPluginManager -lQtNetwork )

set_target_properties( zuluMount-gui PROPERTIES INSTALL_RPATH "${LIB_PATH}" )

install( TARGETS zuluMount-gui RUNTIME DESTINATION bin )

install ( FILES zuluMount.desktop 
DESTINATION share/applications

PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE 
)

install ( FILES zuluMount.png DESTINATION share/icons )
#install ( FILES zuluMount.png DESTINATION share/icons/hicolor/32x32/apps )

# desktop file section
file( WRITE zuluMount.desktop

"#!/usr/bin/env xdg-open
[Desktop Entry]
Comment[en_US]=
Comment=
Exec=${CMAKE_INSTALL_PREFIX}/bin/zuluMount-gui -d %U
GenericName[en_US]=Encrypted volume and Partition mounter
GenericName=Encrypted volumes and partition mounter
Icon=${CMAKE_INSTALL_PREFIX}/share/icons/zuluMount.png
MimeType=
Name[en_US]=ZuluMount
Name=ZuluMount
NoDisplay=false
Path=
StartupNotify=true
Terminal=false
TerminalOptions=
Type=Application
X-DBUS-ServiceName=
X-DBUS-StartupType=
X-KDE-SubstituteUID=false
X-KDE-Username=
Categories=Security;Utility;Qt;X-MandrivaLinux-System-FileTools;\n")
