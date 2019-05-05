## 文件系统
$file arm-linux-gcc

## 操作系统
$uname -a

## 更换编译器
sudo apt-get install gcc-arm-linux-gnueabi

## 启用i386软件包安装支持
$sudo dpkg --add-architecture i386
$sudo apt-get update

## 安装包需要在系统上构建源代码
$sudo apt-get install git build-essential fakeroot

## gcc-multilib是允许在64位（amd64 / x86_64）系统上运行32位（x86）二进制文件的软件包
$sudo apt-get install gcc-multilib
$sudo apt-get install zlib1g:i386

## u-boot-tools - 用于mkimage工具; lzop压缩
$sudo apt-get install u-boot-tools lzop
