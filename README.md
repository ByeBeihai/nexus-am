# P扩展编程手册 V0.2
作者：宗吉祥

本手册基于Ubuntu 20.04环境编写，推荐您使用此版本系统进行环境部署
## 一、部署编译器：LLVM
### 0.使用已经编译安装好的llvm
为了简化同学们部署llvm的流程，我们提供了llvm的免编译安装版压缩包，你可以通过以下链接下载：
```
链接: https://pan.baidu.com/s/13pCz92tRSaOw3w1bEFIQSA 
提取码: llvm 
```
如果你对手动编译部署llvm并不感兴趣，在下载完成后就可以直接跳转到第二部分进行阅读

#### 如果llvm编译器后续需要更新，可以参照第一部分的余下内容进行部署。

### 1.从github上部署plctlab维护的LLVM项目，并切换至p-extension-andes-v1分支。命令参考如下：
```shell
git clone https://github.com/plctlab/llvm-project.git
cd <path of llvm project>
git checkout p-extension-andes-v1

<path of llvm project>为你选择的llvm项目所在的路径
```

### 2.编译并安装llvm
在“path of llvm project”中打开命令行并输入如下命令
```shell
mkdir build
cd build

cmake -G "Unix Makefiles" -DCMAKE_INSTALL_PREFIX=<path of llvm install> -DLLVM_ENABLE_PROJECTS="clang;lld" -DCMAKE_BUILD_TYPE=Release -DLLVM_TARGETS_TO_BUILD="RISCV" -DLLVM_DEFAULT_TARGET_TRIPLE="riscv64-unknown-linux-gnu" ../llvm

make -jn //n为编译调用的线程数，n越大编译越快，但是内存占用也越多，有编译失败的风险。建议内存小于8G的同学直接使用-j1即可。
make install

<path of llvm install>为你选择的llvm安装的目标路径
```

### 3.检查安装是否成功
执行以下命令
```shell
cd <path of llvm install>
./bin/clang --version
./bin/ld.lld --version
```
会得到以下版本信息
```shell
clang version 15.0.0 (https://github.com/plctlab/llvm-project.git bb4bd8ac400633a3e2f4c51a0508ac51cb8c9cf7)
Target: riscv64-unknown-linux-gnu
Thread model: posix
InstalledDir: /media/stu/diskb/llvm-install/./bin

LLD 15.0.0 (compatible with GNU linkers)
```
如果顺利得到了以上的输出结果（安装位置信息可能有不同），那么第一步：部署编译器 就已经完成了。

## 二、部署裸机运行环境
#### 直接使用llvm的clang和链接器ld是无法将代码转换为可以运行的程序的。因为你的linux是X86架构，无法运行llvm编译出来的riscv架构程序。另一方面，我们的P扩展CPU也无法直接运行这些程序，这是因为你使用的库函数与CPU的外设以及内存寻址等机制并不兼容。
#### 因此，我们需要使用一个裸机运行环境为我们的编译提供定制好的库函数和内存映射机制，它将调用我们在第一步中得到的clang和lld，将代码编译为可以在我们的CPU上运行的二进制文件。
### 这个裸机运行环境就是：Nexus-AM
### 1. 从github上部署为P扩展定制的 Nexus-AM
运行以下命令：
```shell
git clone https://github.com/ByeBeihai/nexus-am.git

记你部署的Nexus-AM的路径为<path of Nexus-AM>
```
Nexus-AM原本使用的是GNU作为工具链，我们需要使用GCC对Nexus-AM的基础库做编译，这里使用apt命令安装默认的GNU工具链
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

### 3.修改llvm的路径参数
如果你的llvm是手动编译部署得到的，请参照（a）

如果你的llvm是下载压缩包得到的，请参照（b）

（a）进入Nexus-AM所在文件夹，打开Makefile.compile文件，将文件前4-7行修改为如下内容并保存。
```
AS        = <path of llvm install>/bin/clang
CC        = <path of llvm install>/bin/clang
CXX       = <path of llvm install>/bin/clang++
LD        = <path of llvm install>/bin/ld.lld
```
（b）将llvm压缩包解压至“path of Nexus-AM”下即可，解压后目录的结构应该如下：
```
-nexus-am
--llvm-p
--其他文件和文件夹
```

### 4.检查Nexus-AM是否安装正确
在命令行中输入以下命令：
```shell
cd $AM_HOME/apps/pext
make ARCH=riscv64-nutshell
cd build
ls 
```
若得到以下信息，则编译成功
```
pext-riscv64-nutshell.bin  pext-riscv64-nutshell.elf  pext-riscv64-nutshell.txt  riscv64-nutshell
```
pext-riscv64-nutshell.bin为我们得到的可以在P扩展CPU上运行的二进制文件

在命令行中继续输入以下命令
```shell
$AM_HOME/emu -b 0 -e 0 -i $AM_HOME/apps/pext/build/pext-riscv64-nutshell.bin --no-diff

emu为准备好的P扩展cpu模拟器 -i后输入的是给模拟器执行的程序的路径
可以使用$AM_HOME/emu -help命令来获取更多参数上的信息

有同学反映执行该步骤会报错：
error while loading shared libraries: libSDL2-2.0.so.0: cannot open shared object file: No such file or directory
使用如下命令安装对应的lib即可解决
sudo apt-get install git curl libsdl2-mixer-2.0-0 libsdl2-image-2.0-0 libsdl2-2.0-0
如果遇到其他类似的缺库错误，可以自行查询对应库并安装。如果无法解决请联系本文档作者
```
若得到以下输出（时间、路径等信息可能不同），则程序执行无误：
```shell
Emu compiled at Nov 22 2022, 11:46:16
The image is /home/stu/nexus-am/apps/pext/build/pext-riscv64-nutshell.bin
Using simulated 8192MB RAM
Using simulated 32768B flash
[warning]no valid flash bin path, use preset flash instead
src00 1 src10 2 src20 3 res30 4
src01 5 res11 6 res21 7 res31 8
res0  6 res1  8 res2 10 res3 12
P-EXT ADD16 PASS!!!
Core 0: HIT GOOD TRAP at pc = 0x800000f0
total guest instructions = 8,116
instrCnt = 8,116, cycleCnt = 16,042, IPC = 0.505922
Seed=0 Guest cycle spent: 16,044 (this will be different from cycleCnt if emu loads a snapshot)
Host time spent: 840ms
======== PerfCnt =========
               16042 <- Mcycle
                8116 <- Minstret
                5551 <- MultiCommit
                2425 <- MimemStall
                   0 <- MaluInstr
                   0 <- MbruInstr
                   0 <- MlsuInstr
                   0 <- MmduInstr
                   0 <- McsrInstr
                1528 <- MloadInstr
                 245 <- MmmioInstr
                   0 <- MicacheHit
                   0 <- MdcacheHit
                   0 <- MmulInstr
                 385 <- MifuFlush
                1247 <- MbpBRight
                  93 <- MbpBWrong
                 374 <- MbpJRight
                 137 <- MbpJWrong
                  72 <- MbpIRight
                  58 <- MbpIWrong
                 242 <- MbpRRight
                 281 <- MbpRWrong
                   0 <- Ml2cacheHit
                1365 <- MultiCommit2
                 600 <- MultiCommit3
                   0 <- MultiCommit4
                   0 <- CsrOps
                   0 <- MultiCommit5
                   0 <- MultiCommit6
                   0 <- Custom7
                   0 <- Custom8
                   0 <- MrawStall
                   0 <- MexuBusy
                3644 <- MloadStall
                3162 <- MstoreStall
                   0 <- ISUIssue
======== PerfCntCSV =========

Mcycle, Minstret, MultiCommit, MimemStall, MaluInstr, MbruInstr, MlsuInstr, MmduInstr, McsrInstr, MloadInstr, MmmioInstr, MicacheHit, MdcacheHit, MmulInstr, MifuFlush, MbpBRight, MbpBWrong, MbpJRight, MbpJWrong, MbpIRight, MbpIWrong, MbpRRight, MbpRWrong, Ml2cacheHit, MultiCommit2, MultiCommit3, MultiCommit4, CsrOps, MultiCommit5, MultiCommit6, Custom7, Custom8, MrawStall, MexuBusy, MloadStall, MstoreStall, ISUIssue, 


               16042,                 8116,                 5551,                 2425,                    0,                    0,                    0,                    0,                    0,                 1528,                  245,                    0,                    0,                    0,                  385,                 1247,                   93,                  374,                  137,                   72,                   58,                  242,                  281,                    0,                 1365,                  600,                    0,                    0,                    0,                    0,                    0,                    0,                    0,                    0,                 3644,                 3162,                    0, 
```

## 三、编写你的P扩展程序并运行它
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
如果想要调用P扩展的指令，你可以直接使用P扩展手册中规定的C函数而无须引入头文件（编译器会帮你识别）

例如你可以编写如下的程序：
```C
#include <klib.h>
typedef struct uint16x4
{
   uint16_t src0;
   uint16_t src1;
   uint16_t src2;
   uint16_t src3;
} uint16x4_t;
int main() {

    uint16x4_t a = {1,2,3,4};
    uint16x4_t b = {5,6,7,8};
    unsigned long long c = __rv_add16(*(unsigned long long *)(&a),*(unsigned long long *)(&b));
    printf("src00 %d src10 %d src20 %d res30 %d\n",
            a.src0,  a.src1,  a.src2,  a.src3);
    printf("src01 %d res11 %d res21 %d res31 %d\n",
            b.src0,  b.src1,  b.src2,  b.src3);
    printf("res0  %d res1  %d res2 %d res3 %d\n",
           ((uint16x4_t*)(&c))->src0,((uint16x4_t*)(&c))->src1,
           ((uint16x4_t*)(&c))->src2,((uint16x4_t*)(&c))->src3);
    printf("P-EXT ADD16 PASS!!!\n");
}
```
klib.h为Nexus-AM为你准备的标准库之一，内含printf等你熟悉的函数，它们被重新编写为可以在我们的CPU上正常运行的形式。

如你所见，__rv_add16函数被我们调用以使用P扩展中的add16指令来加速我们的计算。

类似__rv_add16的函数你可以在P扩展手册中每条指令的详情里找到，例如sub8指令的详情中有如下内容：
```
Intrinsic functions:

Required:

uintXLEN_t __rv_sub8(uintXLEN_t a, uintXLEN_t b);
```
你可以使用__rv_sub8函数来调用sub8指令进行计算。

P扩展手册的地址为：
```
https://github.com/riscv/riscv-p-spec/blob/master/P-ext-proposal.adoc
```

LLVM目前不支持uintXLEN_t这样的P扩展变量类型，请使用uint64_t（unsigned long long）这样的等效类型去代替它。

为了方便我们单独操作每个16位数，在程序开头我们定义了如下的结构体
```C
typedef struct uint16x4
{  uint16_t src0;
   uint16_t src1;
   uint16_t src2;
   uint16_t src3;
} uint16x4_t;
```
uint16x4_t在物理上占据的长度就是64位，其内容为4个16位数，由此以来，你可以使用该结构体类型对需要并行运算的数据进行装载（或者是取出），例如在上述程序的打印部分，我们将整型转换为uint16x4_t来取出add16指令的四个运算结果。当然，你也可以使用移位运算符来获得每个结果。
```C
printf("res0  %d res1  %d res2 %d res3 %d\n",((uint16x4_t*)(&c))->src0,((uint16x4_t*)(&c))->src1,
                                             ((uint16x4_t*)(&c))->src2,((uint16x4_t*)(&c))->src3);
```
类似的，如果我们想方便地操作sub8指令的8对操作数（在64位环境下），我们可以自行定义这样的结构体：
```C
typedef struct uint8x8
{  uint8_t src0;
   uint8_t src1;
   uint8_t src2;
   uint8_t src3;
   uint8_t src4;
   uint8_t src5;
   uint8_t src6;
   uint8_t src7;
} uint8x8_t;
```
P扩展还支持32位的操作数和64位的操作数，支持加、减、乘、移位、乘加、乘减、交叉乘加减等多种并行运算，详情可见上文已给出地址的P扩展官方手册。
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
$AM_HOME/emu -b 0 -e 0 -i $AM_HOME/apps/myprj/build/myprj-riscv64-nutshell.bin --no-diff
```
其中$AM_HOME/emu为CPU模拟器，-i后输入的是myprj-riscv64-nutshell.bin的路径，其余的参数对于软件开发者来说并不重要。

你会得到类似于第二节中第四点的结果，第一部分为emu运行的log，如下：
```
Emu compiled at Nov 22 2022, 11:46:16
The image is /home/stu/nexus-am/apps/pext/build/pext-riscv64-nutshell.bin
Using simulated 8192MB RAM
Using simulated 32768B flash
[warning]no valid flash bin path, use preset flash instead
```
第二部分为程序运行的输出，也是软件开发者（诸位读者）所需要关心的内容，例如第二节中编写的程序的输出如下：
```
src00 1 src10 2 src20 3 res30 4
src01 5 res11 6 res21 7 res31 8
res0  6 res1  8 res2 10 res3 12
P-EXT ADD16 PASS!!!
```
第三部分为CPU的性能统计数据，如果你有兴趣，可以看一看
```
Core 0: HIT GOOD TRAP at pc = 0x800000f0
total guest instructions = 8,116
instrCnt = 8,116, cycleCnt = 16,042, IPC = 0.505922
Seed=0 Guest cycle spent: 16,044 (this will be different from cycleCnt if emu loads a snapshot)
Host time spent: 840ms
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
```