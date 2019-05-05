## 文件系统
$file arm-linux-gcc
## 操作系统
$uname -a
## 启用i386软件包安装支持
$sudo dpkg --add-architecture i386
$sudo apt-get update
## gcc-multilib是允许在64位（amd64 / x86_64）系统上运行32位（x86）二进制文件的软件包
$sudo apt-get install gcc-multilib
$sudo apt-get install zlib1g:i386
## 安装包需要在系统上构建源代码
$sudo apt-get install git build-essential fakeroot
## u-boot-tools - 用于mkimage工具; lzop压缩
$sudo apt-get install u-boot-tools lzop


## 更换编译器
$sudo apt-get install gcc-arm-linux-gnueabi


## 解决make menuconfig出错
$sudo apt-get insatll ncurses-dev


## __gnu_mcount_nc
$gunzip -dc __gnu_mcount_nc_patch.patch.gz |patch -p1
## Can’t use ‘defined(@array)’
defined has be delete


## 清除原先此目錄下殘留的.config和.o（object）文件
$make mrproper
## 配置內核選項，編譯內核的關鍵步驟
$make menuconfig
## Warning: make dep is unnecessary now.可能是新版內核不需要再執行make dep了
$make dep
## 清除一些不必要的文件，如果不執行有可能會導致在編譯過程中出現錯誤
$make clean
## 根據選擇的內核選項，生成內核文件
$make zImage/bzImage
## 將在make menuconfig時所選擇為M的選項,全部編譯成模塊並放在/usr/src/linux-2.4.24/
$make modules 
	/insmod
	/rmmod 
	/lsmod
## 將編譯生成的模塊安裝到/lib/modules/2.6.24
$make modules_install
	/depmod 
	/modprobe
## /dev
$mknod "name" c"major""minor"
## 2.6.24標識內核的版本，關於System.map參考
$cp System.map System.map-2.6.24
## 如果用的是 SCSI硬碟並且採用的是ext3分區格式的話，一定要製作initrd.img. 2.6.24是/lib/modules/下的2.6.24，是make modules_install生成的
$mkinitrd /boot/initrd-2.6.24.img 2.6.24

vi /boot/grub/grub.conf
## 編輯grub.conf，插入
## title Linux (2.6.24)
## root (hd0,0)
## kernel /boot/vmlinuz-2.6.24 ro root=LABEL=/1
## initrd /boot/initrd-2.6.24.img
/boot/vmlinuz-2.6.24是新內核的路徑
/boot/initrd-2.6.24.img是mkinitrd /boot/initrd-2.6.24.img 2.6.24生成的

## 重啟，在grub啟動時選擇 Linux (2.6.24)即可用新內核啟動系統，如果要修改默認的啟動內核，將/boot/grub/grub.conf中的default=0改為1，具體參考grub.conf的配置。

