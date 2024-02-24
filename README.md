# Polaris编程手册 V0.3
作者：宗吉祥

本手册基于Ubuntu 20.04环境编写，推荐您使用此版本系统进行环境部署
## 一、部署编译器：GCC
### 0.使用已经编译安装好的gcc
为了简化同学们部署gcc的流程，我们提供了gcc的免编译安装版压缩包，你可以通过以下链接下载：
```
链接: https://pan.baidu.com/s/10qhtXk5bn2AQF-8MKeMvnQ
提取码: PEXT
```
如果你对手动编译部署gcc并不感兴趣，在下载完成后就可以直接跳转到第二部分进行阅读

#### 如果gcc编译器后续需要更新，可以参照第一部分的余下内容进行部署。

### 1.从github上部署整合好的p扩展版riscv-toolchain项目（内含gcc等工具的源码）
```shell
git clone https://github.com/ByeBeihai/riscv-toolchain-rvp.git

<path of gcc project>为你选择的gcc项目所在的路径，建议磁盘空间预留1G
```

### 2.编译并安装gcc
在任一路径（建议磁盘空间预留1G）下打开命令行，输入以下命令：
```shell
mkdir rvp-build
cd rvp-build

<path of gcc project>/configure --prefix=<path of gcc install> --target=riscv64-unknown-linux --with-arch=rv64imacp --with-abi=lp64

make linux -jn //n为编译调用的线程数，n越大编译越快，但是内存占用也越多，有编译失败的风险。建议内存小于8G的同学直接使用-j1即可。

<path of gcc install>为你选择的gcc安装的目标路径，建议磁盘空间预留2G
```

### 3.检查安装是否成功
执行以下命令
```shell
cd <path of gcc install>
./bin/riscv64-unknown-linux-gcc -v
./bin/riscv64-unknown-linux-ld -v
```
会得到以下版本信息
```shell
Using built-in specs.
COLLECT_GCC=./bin/riscv64-unknown-linux-gcc
COLLECT_LTO_WRAPPER=/media/stu/diska/rv-tool/install/libexec/gcc/riscv64-unknown-linux/10.2.0/lto-wrapper
Target: riscv64-unknown-linux
Configured with: /media/stu/diska/rv-tool/build/../riscv-gnu-toolchain/gcc/configure --target=riscv64-unknown-linux --prefix=/media/stu/diska/rv-tool/install --disable-shared --disable-threads --enable-languages=c,c++ --with-pkgversion=g2ee5e430018-dirty --with-system-zlib --enable-tls --with-newlib --with-sysroot=/media/stu/diska/rv-tool/install/riscv64-unknown-linux --with-native-system-header-dir=/include --disable-libmudflap --disable-libssp --disable-libquadmath --disable-libgomp --disable-nls --disable-tm-clone-registry --src=/media/stu/diska/rv-tool/riscv-gnu-toolchain/gcc --disable-multilib --with-abi=lp64 --with-arch=rv64imacp --with-tune=rocket --with-isa-spec=2.2 'CFLAGS_FOR_TARGET=-Os   -mcmodel=medlow' 'CXXFLAGS_FOR_TARGET=-Os   -mcmodel=medlow'
Thread model: single
Supported LTO compression algorithms: zlib
gcc version 10.2.0 (g2ee5e430018-dirty)

GNU ld (GNU Binutils) 2.36.1
```
如果顺利得到了以上的输出结果（安装位置信息可能有不同），那么第一步：部署编译器 就已经完成了。

## 二、部署裸机运行环境
#### 直接使用gcc和链接器ld是无法将代码转换为可以运行的程序的。因为你的linux是X86架构，无法运行gcc编译出来的riscv架构程序。另一方面，我们的P扩展CPU也无法直接运行这些程序，这是因为你使用的库函数与CPU的外设以及内存寻址等机制并不兼容。
#### 因此，我们需要使用一个裸机运行环境为我们的编译提供定制好的库函数和内存映射机制，它将调用我们在第一步中得到的gcc和ld，将代码编译为可以在我们的CPU上运行的二进制文件。
### 这个裸机运行环境就是：Nexus-AM
### 1. 从github上部署为P扩展定制的 Nexus-AM
运行以下命令：
```shell
git clone https://github.com/ByeBeihai/nexus-am.git

记你部署的Nexus-AM的路径为<path of Nexus-AM>
```
Nexus-AM原本使用的是riscv64-linux-gnu作为工具链,为规避可能出现的报错，需要执行如下命令安装gcc-riscv64-linux-gnu
```shell
sudo apt install gcc-riscv64-linux-gnu
```

### 2.添加Nexus-AM的环境变量
运行以下命令打开.bashrc文件
```shell
vim ~/.bashrc 

关于vim的使用知识请自行学习，也可以用其他文本编辑器打开这个文件（例如vscode）
```
在打开的文件末尾添加如下的环境变量并保存文件：
```shell
export AM_HOME=<path of Nexus-AM>

例如：export AM_HOME=/home/stu/nexus-am
```
在任意命令行中执行以下命令：
```shell
source ~/.bashrc
$AM_HOME
```
若输出以下内容，则说明环境变量设置正确
```shell
bash: <path of Nexus-AM>: Is a directory
```

### 3.修改gcc的路径参数
如果你的gcc是手动编译部署得到的，请参照（a）

如果你的gcc是下载压缩包得到的，请参照（b）

（a）进入Nexus-AM所在文件夹，打开Makefile.compile文件，将文件前4-10行修改为如下内容并保存。
```
AS        = <path of gcc install>/bin/riscv64-unknown-linux-gcc
CC        = <path of gcc install>/bin/riscv64-unknown-linux-gcc
CXX       = <path of gcc install>/bin/riscv64-unknown-linux-gcc
LD        = <path of gcc install>/bin/riscv64-unknown-linux-ld
OBJDUMP   = <path of gcc install>/bin/riscv64-unknown-linux-objdump
OBJCOPY   = <path of gcc install>/bin/riscv64-unknown-linux-objcopy
READELF   = <path of gcc install>/bin/riscv64-unknown-linux-readelf
```
随后进入am/arch/riscv64-nutshell.mk文件，将第23行的内容改为
```
SEARCH_DIR :=<path of gcc install>/lib/gcc/riscv64-unknown-linux-gnu/10.2.0
```

（b）将gcc压缩包解压至“path of Nexus-AM”下，解压后目录的结构应该如下：
```
-nexus-am
--gcc
--其他文件和文件夹
```
然后打开Makefile.compile文件，将文件前4-10行修改为如下内容并保存。
```
AS        = $(AM_HOME)/gcc/bin/riscv64-unknown-linux-gcc
CC        = $(AM_HOME)/gcc/bin/riscv64-unknown-linux-gcc
CXX       = $(AM_HOME)/gcc/bin/riscv64-unknown-linux-gcc
LD        = $(AM_HOME)/gcc/bin/riscv64-unknown-linux-ld
OBJDUMP   = $(AM_HOME)/gcc/bin/riscv64-unknown-linux-objdump
OBJCOPY   = $(AM_HOME)/gcc/bin/riscv64-unknown-linux-objcopy
READELF   = $(AM_HOME)/gcc/bin/riscv64-unknown-linux-readelf
```
随后进入am/arch/riscv64-nutshell.mk文件，将第23行的内容改为
```
SEARCH_DIR :=$(AM_HOME)/gcc/lib/gcc/riscv64-unknown-linux-gnu/10.2.0
```

### 4.检查Nexus-AM是否安装正确
在命令行中输入以下命令：
```shell
cd $AM_HOME/apps/coremark
make ARCH=riscv64-nutshell
cd build
ls 
```
若得到以下信息，则编译成功
```
coremark-riscv64-nutshell.bin  
coremark-riscv64-nutshell.txt
coremark-riscv64-nutshell.elf
```
coremark-riscv64-nutshell.bin为我们得到的可以在CPU上运行的二进制文件

在命令行中继续输入以下命令
```shell
$AM_HOME/emu -b 0 -e 0 -i $AM_HOME/apps/coremark/build/coremark-riscv64-nutshell.bin --no-diff

emu为准备好的cpu模拟器 -i后输入的是给模拟器执行的程序的路径
可以使用$AM_HOME/emu -help命令来获取更多参数上的信息

有同学反映执行该步骤会报错：
error while loading shared libraries: libSDL2-2.0.so.0: cannot open shared object file: No such file or directory
使用如下命令安装对应的lib即可解决
sudo apt-get install git curl libsdl2-mixer-2.0-0 libsdl2-image-2.0-0 libsdl2-2.0-0
如果遇到其他类似的缺库错误，可以自行查询对应库并安装。如果无法解决请联系本文档作者
```
若得到以下输出（时间、路径等信息可能不同），则程序执行无误：
```shell
Emu compiled at Feb 22 2024, 03:11:45
The image is /home/stu/nexus-am/apps/coremark/build/coremark-riscv64-nutshell.bin
Using simulated 8192MB RAM
Using simulated 32768B flash
[warning]no valid flash bin path, use preset flash instead
Running CoreMark for 1 iterations
2K performance run parameters for coremark.
CoreMark Size    : 666
Total time (ms)  : 5
Iterations       : 1
Compiler version : GCC10.2.0
seedcrc          : 0xe9f5
[0]crclist       : 0xe714
[0]crcmatrix     : 0x1fd7
[0]crcstate      : 0x8e3a
[0]crcfinal      : 0xe714
Finised in 5 ms.
==================================================
CoreMark PASS       584 Marks
                vs. 100000 Marks (i7-7700K @ 4.20GHz)
Core 0: HIT GOOD TRAP at pc = 0x2cae
total guest instructions = 384,951
instrCnt = 384,951, cycleCnt = 548,424, IPC = 0.701922
Seed=0 Guest cycle spent: 548,426 (this will be different from cycleCnt if emu loads a snapshot)
Host time spent: 2,053ms
======== PerfCnt =========
              548424 <- Mcycle
              384951 <- Minstret
              337923 <- MultiCommit
               25450 <- MimemStall
                   0 <- MaluInstr
                   0 <- MbruInstr
                   0 <- MlsuInstr
                   0 <- MmduInstr
                   0 <- McsrInstr
               58061 <- MloadInstr
                 942 <- MmmioInstr
                   0 <- MicacheHit
                   0 <- MdcacheHit
                9494 <- MmulInstr
               20683 <- MifuFlush
               50021 <- MbpBRight
               17616 <- MbpBWrong
                4267 <- MbpJRight
                2216 <- MbpJWrong
                 927 <- MbpIRight
                  20 <- MbpIWrong
                1648 <- MbpRRight
                 831 <- MbpRWrong
                   0 <- Ml2cacheHit
               47028 <- MultiCommit2
                   0 <- MultiCommit3
                   0 <- MultiCommit4
                   0 <- CsrOps
                   0 <- MultiCommit5
                   0 <- MultiCommit6
                   0 <- csrnotalone
                   0 <- mounotalone
              100476 <- LsuWorking
                 671 <- divtime
                   0 <- MrawStall
                   0 <- MexuBusy
                   0 <- MloadStall
                   0 <- MstoreStall
                   0 <- ISUIssue
======== PerfCntCSV =========

Mcycle, Minstret, MultiCommit, MimemStall, MaluInstr, MbruInstr, MlsuInstr, MmduInstr, McsrInstr, MloadInstr, MmmioInstr, MicacheHit, MdcacheHit, MmulInstr, MifuFlush, MbpBRight, MbpBWrong, MbpJRight, MbpJWrong, MbpIRight, MbpIWrong, MbpRRight, MbpRWrong, Ml2cacheHit, MultiCommit2, MultiCommit3, MultiCommit4, CsrOps, MultiCommit5, MultiCommit6, csrnotalone, mounotalone, LsuWorking, divtime, MrawStall, MexuBusy, MloadStall, MstoreStall, ISUIssue, 


              548424,               384951,               337923,                25450,                    0,                    0,                    0,                    0,                    0,                58061,                  942,                    0,                    0,                 9494,                20683,                50021,                17616,                 4267,                 2216,                  927,                   20,                 1648,                  831,                    0,                47028,                    0,                    0,                    0,                    0,                    0,                    0,                    0,               100476,                  671,                    0,                    0,                    0,                    0,                    0, 
```

## 三、编写你的程序并运行它
### 1.进入“path of Nexus-AM”路径下的apps文件夹，并新建一个文件夹作为你的项目路径（以myprj为例）
```shell
cd $AM_HOME/apps
mkdir myprj
cd myprj
```
### 2.在myprj下创建src文件夹和Makefile文件，在Makefile中写入以下内容：
```txt
NAME = myprj
SRCS = $(shell find -L ./src/ -name "*.c")
include $(AM_HOME)/Makefile.app
```
### 3.在src文件夹中开始你的程序编写
关于标准库的调用的规范详见文件：
```
<path of Nexus-AM>/README_old.md
```

例如你可以编写如下的程序：
```C
#include <klib.h>
int main() {
    printf("Hello Polaris!!!\n");
}
```
klib.h为Nexus-AM为你准备的标准库之一，内含printf等你熟悉的函数，它们被重新编写为可以在我们的CPU上正常运行的形式。

### 4.编译并运行
在编写完程序之后，请回到项目的根目录下（如本例中的myprj），执行如下命令：
```shell
make ARCH=riscv64-nutshell
```
该命令会生成build文件夹，在build文件夹下有如下内容：
```
myprj-riscv64-nutshell.bin  myprj-riscv64-nutshell.elf  myprj-riscv64-nutshell.txt  riscv64-nutshell
```
其中myprj-riscv64-nutshell.bin就是我们所需的供CPU运行的二进制文件，myprj-riscv64-nutshell.txt为反汇编文件。

执行如下命令来运行你编写的程序
```shell
$AM_HOME/emu -b 0 -e 0 -i $AM_HOME/apps/pext/build/myprj-riscv64-nutshell.bin --no-diff
```
其中$AM_HOME/emu为CPU模拟器，-i后输入的是myprj-riscv64-nutshell.bin的路径，其余的参数对于软件开发者来说并不重要。

你会得到类似于第二节中第四点的结果，第一部分为emu运行的log，如下：
```
Emu compiled at Dec 23 2022, 09:06:29
The image is ./ready-to-run/myprj-riscv64-nutshell.bin
Using simulated 8192MB RAM
Using simulated 32768B flash
[warning]no valid flash bin path, use preset flash instead
```
第二部分为程序运行的输出，也是软件开发者（诸位读者）所需要关心的内容：
```
Hello Polaris!!!
```
第三部分为CPU的性能统计数据，如果你有兴趣，可以看一看
```
Core 0: HIT GOOD TRAP at pc = 0x1006
total guest instructions = 511
instrCnt = 511, cycleCnt = 1,818, IPC = 0.281078
Seed=0 Guest cycle spent: 1,820 (this will be different from cycleCnt if emu loads a snapshot)
Host time spent: 17ms
======== PerfCnt =========
以下内容此处省略，可以在第二节第四点中查看。
```

## 关于文档

### 有任何问题可以联系作者：
```
zongjixiang19@mails.ucas.ac.cn
```
### 更新日志
```
V0.1 
完成初版编写

V0.2 
提供了LLVM的免编译安装包
更新了P扩展CPU模拟程序、程序示例
增加了P扩展结构体示例
更新了仓库内容，将手册作为仓库的README

v0.3
使用gcc替换llvm
得益于编译器的替换，用户现在可以对乘法类型指令进行函数式编程
得益于编译器的替换，用户现在无需自行定义复杂的结构体
简化了环境的部署流程

v-mem_base=0x0
为FPGA：70t修改了nexus-am，包含：
去除P扩展的编译支持
将编译的基地址修改为0x0
相应地修改了手册的部分内容
```
