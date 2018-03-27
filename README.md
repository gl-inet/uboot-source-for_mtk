## 1 Prepare  

### 1.1 Installing Dependency Packages  

```bash
  $ sudo apt-get update
  $ sudo apt-get install g++ libghc-zlib-dev liblzma-dev ncurses-dev git
  $ sudo apt-get install libstdc++5:i386 libgtk2.0-0:i386 libpangoxft-1.0:i386
  libpangox-1.0-0:i386 gtk2-engines-murrine:i386 gtk2-engines-pixbuf:i386
  dos2unix
```
### 1.2 Preparing Toolchain  

Entering u-boot source tree.  

```bash
  $ sudo mv toolchain/buildroot-gcc342 /opt/
```

#####  Install LZMA Utility  

```bash
  $ cd toolchain
  $ tar -zxvf lzma-4.32.7.tar.gz
  $ cd lzma-4.32.7/
  $ ./configure
  $ make
  $ sudo make install
  $ cd ../
```

#####  Install mksquashfs utility  

```bash
  $ cd squashfs4.2/squashfs-tools/
  $ make
  $ sudo cp mksquashfs /opt/buildroot-gcc463/usr/bin/mksquashfs_lzma-4.2		
  $ cd ../../../
```

## 2 Build  

### 2.1 U-boot Configuration  

For mt300n-v2:  

```bash
  $ make menuconfig
     Chip Type ---> ASIC
     Chip ID ---> MT7628
     DRAM Type ---> DDR2
     DDR Component ---> 1024Mb
     Ram/Rom version ---> ROM
```		

For mt300a:  

```bash
  (ASIC) Chip Type
  (MT7620) Chip ID
  (None) Port 5 Connect to
  (None) Port 4 Connect to
  (SPI) Flash Type
  (DDR2) DRAM Type
  (1024Mb) DDR Component
  (16bits) DDR Width
  (ROM) Ram/Rom version
  [ ] Dual Image
  [*] Partition LAN/WAN
  (W/LLLL) LAN/WAN Board Layout
```  

For mt300n:  

```bash
  (ASIC) Chip Type
  (MT7620) Chip ID
  (None) Port 5 Connect to
  (None) Port 4 Connect to
  (SPI) Flash Type
  (DDR2) DRAM Type
  (512Mb) DDR Component
  (16bits) DDR Width
  (ROM) Ram/Rom version
  [ ] Dual Image
  [*] Partition LAN/WAN
  (W/LLLL) LAN/WAN Board Layout
```  

### 2.2 build uboot  

```bash
  $ make
``` 

It will generate uboot.bin image on current directory.
   

