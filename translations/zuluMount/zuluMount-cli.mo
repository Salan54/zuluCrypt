��    +      t  ;   �      �  �   �    P    i  H   m  6   �  M   �  *   ;  �   f     '  ;   C  [     \   �  '   8	     `	     ~	  +   �	     �	  0   �	  k   
  S   �
  $   �
  &   �
  ;   #  L   _  !   �  3   �  �     J   �  6     2   N  +   �  W   �  >     +   D  l   p  ;   �  %        ?     X  �   p  !  .  6   P  \  �  �   �    {    �  H   �  6   �  M     *   f  �   �     R  ;   n  [   �  \     '   c     �     �  +   �     �  0     k   B  S   �  $     &   '  ;   N  L   �  !   �  3   �  �   -  J   �  6   B  2   y  +   �  W   �  >   0  +   o  l   �  ;     %   D     j     �  �   �  !  Y  6   {      $   )                        +      %                        #                 '                           (                   !   	   *      "                                    
                    &    -A -- print a list of all volumes
-S -- print a list of system volumes
-N -- print a list of non system volumes
-E -- print a list of mounted volumes
 -l -- print expanded list of all volumes
-L -- must be used with -d,print properties of a volume specified by d option
-P -- print a list of all volumes
-D -- get a device node address from its mapper path( mapper paths are usually located in /dev/mapper ). Required argument: -d
 -u -- unmount a volume: arguments: -d volume_path
-s -- print properties of an encrypted volume: arguments: -d partition_path
-M -- this option will create a mount point in "/run/media/private/$USER" and a publicly accessible "mirror" in "/run/media/public/'
 ERROR: "/etc/fstab" entry for this volume does not allow you to mount it ERROR: "/etc/fstab" entry for this volume is malformed ERROR: "/etc/fstab" entry for this volume requires it to be mounted read only ERROR: a file can have only one hard link
 ERROR: a non supported device encountered,device is missing or permission denied
Possible reasons for getting the error are:
1.Device path is invalid.
2.The device has LVM or MDRAID signature
 ERROR: action not specified ERROR: could not create mount point path,path already taken ERROR: could not get volume properties,volume is not open or was opened by a different user ERROR: could not get volume properties,volume is not open or was opened by a different user
 ERROR: could not resolve path to device ERROR: device already mounted ERROR: device argument missing ERROR: device does not appear to be mounted ERROR: device does not exist ERROR: devices in /dev/shm path is not suppored
 ERROR: failed to mount a filesystem:invalid/unsupported mount option or unsupported file system encountered ERROR: failed to mount ntfs file system using ntfs-3g,is ntfs-3g package installed? ERROR: failed to mount the partition ERROR: failed to unmount the partition ERROR: failed to unmount,could not get a lock on /etc/mtab~ ERROR: failed to unmount,the mount point and/or one or more files are in use ERROR: given path is a directory
 ERROR: insufficient privilges to access the device
 ERROR: insuffienct privilege to manage a system volume.
necessary privileges can be acquired by:
1. adding an entry for the volume in fstab with "user" mount option
2. add yourself to "zulumount" group ERROR: insuffienct privileges to mount the volume with given mount options ERROR: mount failed,could not get a lock on /etc/mtab~ ERROR: mount failed,no or unrecognized file system ERROR: shared mount point appear to be busy ERROR: shared mount point appear to be in an ambiguous state,advice to unmount manually ERROR: shared mount point appear to belong to a different user ERROR: shared mount point path aleady taken ERROR: you can not umount volumes out of "%s" since you are not root and do not belong to group "zulumount"
 SUCCESS: mount complete successfully
volume mounted at: %s
 SUCCESS: umount complete successfully could not resolve LABEL
 could not resolve UUID
 examples:
mount a volume  : zuluMount-cli -m -d /dev/sdc1
unmount a volume: zuluMount-cli -u -d /dev/sdc1
mount and encrypted volume with a key "xyz" : zuluMount-cli -m -d /dev/sdc2 -p xyz
 options:
-m -- mount a volume : arguments: -d volume_path -z mount_point -e mode(rw/ro)
      -- additional arguments for crypto_LUKS,crypto_PLAIN,crypto_TCRYPT volumes, -p passphrase/-f keyfile
-z -- mount point component to append to "/run/media/private/$USER/
-Y -- file system options
 unexpected exiting because you have run out of memory
 Project-Id-Version: PACKAGE VERSION
Report-Msgid-Bugs-To: 
POT-Creation-Date: 2013-07-15 02:53-0400
PO-Revision-Date: 2013-07-15 06:08-0400
Last-Translator: ink <ink@mtz>
Language-Team: English
Language: en_US
MIME-Version: 1.0
Content-Type: text/plain; charset=ISO-8859-1
Content-Transfer-Encoding: 8bit
Plural-Forms: nplurals=2; plural=(n != 1);
 -A -- print a list of all volumes
-S -- print a list of system volumes
-N -- print a list of non system volumes
-E -- print a list of mounted volumes
 -l -- print expanded list of all volumes
-L -- must be used with -d,print properties of a volume specified by d option
-P -- print a list of all volumes
-D -- get a device node address from its mapper path( mapper paths are usually located in /dev/mapper ). Required argument: -d
 -u -- unmount a volume: arguments: -d volume_path
-s -- print properties of an encrypted volume: arguments: -d partition_path
-M -- this option will create a mount point in "/run/media/private/$USER" and a publicly accessible "mirror" in "/run/media/public/'
 ERROR: "/etc/fstab" entry for this volume does not allow you to mount it ERROR: "/etc/fstab" entry for this volume is malformed ERROR: "/etc/fstab" entry for this volume requires it to be mounted read only ERROR: a file can have only one hard link
 ERROR: a non supported device encountered,device is missing or permission denied
Possible reasons for getting the error are:
1.Device path is invalid.
2.The device has LVM or MDRAID signature
 ERROR: action not specified ERROR: could not create mount point path,path already taken ERROR: could not get volume properties,volume is not open or was opened by a different user ERROR: could not get volume properties,volume is not open or was opened by a different user
 ERROR: could not resolve path to device ERROR: device already mounted ERROR: device argument missing ERROR: device does not appear to be mounted ERROR: device does not exist ERROR: devices in /dev/shm path is not suppored
 ERROR: failed to mount a filesystem:invalid/unsupported mount option or unsupported file system encountered ERROR: failed to mount ntfs file system using ntfs-3g,is ntfs-3g package installed? ERROR: failed to mount the partition ERROR: failed to unmount the partition ERROR: failed to unmount,could not get a lock on /etc/mtab~ ERROR: failed to unmount,the mount point and/or one or more files are in use ERROR: given path is a directory
 ERROR: insufficient privilges to access the device
 ERROR: insuffienct privilege to manage a system volume.
necessary privileges can be acquired by:
1. adding an entry for the volume in fstab with "user" mount option
2. add yourself to "zulumount" group ERROR: insuffienct privileges to mount the volume with given mount options ERROR: mount failed,could not get a lock on /etc/mtab~ ERROR: mount failed,no or unrecognized file system ERROR: shared mount point appear to be busy ERROR: shared mount point appear to be in an ambiguous state,advice to unmount manually ERROR: shared mount point appear to belong to a different user ERROR: shared mount point path aleady taken ERROR: you can not umount volumes out of "%s" since you are not root and do not belong to group "zulumount"
 SUCCESS: mount complete successfully
volume mounted at: %s
 SUCCESS: umount complete successfully could not resolve LABEL
 could not resolve UUID
 examples:
mount a volume  : zuluMount-cli -m -d /dev/sdc1
unmount a volume: zuluMount-cli -u -d /dev/sdc1
mount and encrypted volume with a key "xyz" : zuluMount-cli -m -d /dev/sdc2 -p xyz
 options:
-m -- mount a volume : arguments: -d volume_path -z mount_point -e mode(rw/ro)
      -- additional arguments for crypto_LUKS,crypto_PLAIN,crypto_TCRYPT volumes, -p passphrase/-f keyfile
-z -- mount point component to append to "/run/media/private/$USER/
-Y -- file system options
 unexpected exiting because you have run out of memory
 