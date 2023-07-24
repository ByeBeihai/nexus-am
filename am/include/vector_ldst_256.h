#include <rvp_intrinsic.h>

struct uint16x4x4_t{
    uint16x4_t data0;
    uint16x4_t data1;
    uint16x4_t data2;
    uint16x4_t data3;
};   
struct uint8x8x4_t{
    uint8x8_t data0;
    uint8x8_t data1;
    uint8x8_t data2;
    uint8x8_t data3;
};   
struct uint32x2x4_t{
    uint32x2_t data0;
    uint32x2_t data1;
    uint32x2_t data2;
    uint32x2_t data3;
};   
struct uint64x1x4_t{
    uint64_t data0;
    uint64_t data1;
    uint64_t data2;
    uint64_t data3;
};   

//16 256 vecstep
void rv_slr_16256_t3(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x49, t3, %0, %1" //使用add指令，一个目标操作数（命名为dest），
		:                //将add指令的目标操作数dest和C程序中的sum变量绑定。
		:"r"(address),"r"(offset)//将add指令的源操作数srec1和C程序中的add1变量绑定
        :
);
}

void rv_slr_16256(uint64_t address,uint64_t offset,struct uint16x4x4_t data){
__asm__ __volatile__(
		"mv t3, %0;\
         mv t4, %1;\
         mv t5, %2;\
         mv t6, %3"
		:                
		:"r"(data.data0),"r"(data.data1),"r"(data.data2),"r"(data.data3)
        :
);
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x49, t3, %0, %1" //使用add指令，一个目标操作数（命名为dest），
		:                //将add指令的目标操作数dest和C程序中的sum变量绑定。
		:"r"(address),"r"(offset)//将add指令的源操作数srec1和C程序中的add1变量绑定
        :
);
}

void rv_llr_16256_t3(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x9, t3, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t3","t4","t5","t6"
);
}
void rv_llr_16256_s2(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x9, s2, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"s2","s3","s4","s5"
);
}
void rv_llr_16256_s6(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x9, s6, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"s6","s7","s8","s9"
);
}

struct uint16x4x4_t rv_llr_16256(uint64_t address,uint64_t offset){
struct uint16x4x4_t data;
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x9, t3, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t3","t4","t5","t6"
);
__asm__ __volatile__(
		"mv %0, t3;\
         mv %1, t4;\
         mv %2, t5;\
         mv %3, t6"
		:"=r"(data.data0),"=r"(data.data1),"=r"(data.data2),"=r"(data.data3)                
		:
        :
);
return data;
}

void rv_svr_16256_t3(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x69, t3, %0, %1" //使用add指令，一个目标操作数（命名为dest），
		:                //将add指令的目标操作数dest和C程序中的sum变量绑定。
		:"r"(address),"r"(offset)//将add指令的源操作数srec1和C程序中的add1变量绑定
        :
);
}

void rv_svr_16256(uint64_t address,uint64_t offset,struct uint16x4x4_t data){
__asm__ __volatile__(
		"mv t3, %0;\
         mv t4, %1;\
         mv t5, %2;\
         mv t6, %3"
		:                
		:"r"(data.data0),"r"(data.data1),"r"(data.data2),"r"(data.data3)
        :
);
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x69, t3, %0, %1" //使用add指令，一个目标操作数（命名为dest），
		:                //将add指令的目标操作数dest和C程序中的sum变量绑定。
		:"r"(address),"r"(offset)//将add指令的源操作数srec1和C程序中的add1变量绑定
        :
);
}

void rv_lvr_16256_t3(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x29, t3, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t3","t4","t5","t6"
);
}
void rv_lvr_16256_s2(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x29, s2, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"s2","s3","s4","s5"
);
}
void rv_lvr_16256_s6(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x29, s6, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"s6","s7","s8","s9"
);
}

struct uint16x4x4_t rv_lvr_16256(uint64_t address,uint64_t offset){
struct uint16x4x4_t data;
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x29, t3, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t3","t4","t5","t6"
);
__asm__ __volatile__(
		"mv %0, t3;\
         mv %1, t4;\
         mv %2, t5;\
         mv %3, t6"
		:"=r"(data.data0),"=r"(data.data1),"=r"(data.data2),"=r"(data.data3)                
		:
        :
);
return data;
}

//08 256 vecstep
void rv_slr_08256_t3(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x48, t3, %0, %1" //使用add指令，一个目标操作数（命名为dest），
		:                //将add指令的目标操作数dest和C程序中的sum变量绑定。
		:"r"(address),"r"(offset)//将add指令的源操作数srec1和C程序中的add1变量绑定
        :
);
}

void rv_slr_08256(uint64_t address,uint64_t offset,struct uint8x8x4_t data){
__asm__ __volatile__(
		"mv t3, %0;\
         mv t4, %1;\
         mv t5, %2;\
         mv t6, %3"
		:                
		:"r"(data.data0),"r"(data.data1),"r"(data.data2),"r"(data.data3)
        :
);
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x48, t3, %0, %1" //使用add指令，一个目标操作数（命名为dest），
		:                //将add指令的目标操作数dest和C程序中的sum变量绑定。
		:"r"(address),"r"(offset)//将add指令的源操作数srec1和C程序中的add1变量绑定
        :
);
}

void rv_llr_08256_t3(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x8, t3, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t3","t4","t5","t6"
);
}
void rv_llr_08256_s2(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x8, s2, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"s2","s3","s4","s5"
);
}
void rv_llr_08256_s6(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x8, s6, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"s6","s7","s8","s9"
);
}

struct uint8x8x4_t rv_llr_08256(uint64_t address,uint64_t offset){
struct uint8x8x4_t data;
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x8, t3, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t3","t4","t5","t6"
);
__asm__ __volatile__(
		"mv %0, t3;\
         mv %1, t4;\
         mv %2, t5;\
         mv %3, t6"
		:"=r"(data.data0),"=r"(data.data1),"=r"(data.data2),"=r"(data.data3)                
		:
        :
);
return data;
}

void rv_svr_08256_t3(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x68, t3, %0, %1" //使用add指令，一个目标操作数（命名为dest），
		:                //将add指令的目标操作数dest和C程序中的sum变量绑定。
		:"r"(address),"r"(offset)//将add指令的源操作数srec1和C程序中的add1变量绑定
        :
);
}

void rv_svr_08256(uint64_t address,uint64_t offset,struct uint8x8x4_t data){
__asm__ __volatile__(
		"mv t3, %0;\
         mv t4, %1;\
         mv t5, %2;\
         mv t6, %3"
		:                
		:"r"(data.data0),"r"(data.data1),"r"(data.data2),"r"(data.data3)
        :
);
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x68, t3, %0, %1" //使用add指令，一个目标操作数（命名为dest），
		:                //将add指令的目标操作数dest和C程序中的sum变量绑定。
		:"r"(address),"r"(offset)//将add指令的源操作数srec1和C程序中的add1变量绑定
        :
);
}

void rv_lvr_08256_t3(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x28, t3, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t3","t4","t5","t6"
);
}
void rv_lvr_08256_s2(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x28, s2, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"s2","s3","s4","s5"
);
}
void rv_lvr_08256_s6(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x28, s6, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"s6","s7","s8","s9"
);
}

struct uint8x8x4_t rv_lvr_08256(uint64_t address,uint64_t offset){
struct uint8x8x4_t data;
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x28, t3, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t3","t4","t5","t6"
);
__asm__ __volatile__(
		"mv %0, t3;\
         mv %1, t4;\
         mv %2, t5;\
         mv %3, t6"
		:"=r"(data.data0),"=r"(data.data1),"=r"(data.data2),"=r"(data.data3)                
		:
        :
);
return data;
}

//32 256 vecstep
void rv_slr_32256_t3(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x4A, t3, %0, %1" //使用add指令，一个目标操作数（命名为dest），
		:                //将add指令的目标操作数dest和C程序中的sum变量绑定。
		:"r"(address),"r"(offset)//将add指令的源操作数srec1和C程序中的add1变量绑定
        :
);
}

void rv_slr_32256(uint64_t address,uint64_t offset,struct uint32x2x4_t data){
__asm__ __volatile__(
		"mv t3, %0;\
         mv t4, %1;\
         mv t5, %2;\
         mv t6, %3"
		:                
		:"r"(data.data0),"r"(data.data1),"r"(data.data2),"r"(data.data3)
        :
);
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x4A, t3, %0, %1" //使用add指令，一个目标操作数（命名为dest），
		:                //将add指令的目标操作数dest和C程序中的sum变量绑定。
		:"r"(address),"r"(offset)//将add指令的源操作数srec1和C程序中的add1变量绑定
        :
);
}

void rv_llr_32256_t3(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0xA, t3, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t3","t4","t5","t6"
);
}
void rv_llr_32256_s2(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0xA, s2, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"s2","s3","s4","s5"
);
}
void rv_llr_32256_s6(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0xA, s6, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"s6","s7","s8","s9"
);
}

struct uint32x2x4_t rv_llr_32256(uint64_t address,uint64_t offset){
struct uint32x2x4_t data;
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0xA, t3, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t3","t4","t5","t6"
);
__asm__ __volatile__(
		"mv %0, t3;\
         mv %1, t4;\
         mv %2, t5;\
         mv %3, t6"
		:"=r"(data.data0),"=r"(data.data1),"=r"(data.data2),"=r"(data.data3)                
		:
        :
);
return data;
}

void rv_svr_32256_t3(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x6A, t3, %0, %1" //使用add指令，一个目标操作数（命名为dest），
		:                //将add指令的目标操作数dest和C程序中的sum变量绑定。
		:"r"(address),"r"(offset)//将add指令的源操作数srec1和C程序中的add1变量绑定
        :
);
}

void rv_svr_32256(uint64_t address,uint64_t offset,struct uint32x2x4_t data){
__asm__ __volatile__(
		"mv t3, %0;\
         mv t4, %1;\
         mv t5, %2;\
         mv t6, %3"
		:                
		:"r"(data.data0),"r"(data.data1),"r"(data.data2),"r"(data.data3)
        :
);
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x6A, t3, %0, %1" //使用add指令，一个目标操作数（命名为dest），
		:                //将add指令的目标操作数dest和C程序中的sum变量绑定。
		:"r"(address),"r"(offset)//将add指令的源操作数srec1和C程序中的add1变量绑定
        :
);
}

void rv_lvr_32256_t3(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x2A, t3, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t3","t4","t5","t6"
);
}
void rv_lvr_32256_s2(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x2A, s2, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"s2","s3","s4","s5"
);
}
void rv_lvr_32256_s6(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x2A, s6, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"s6","s7","s8","s9"
);
}

struct uint32x2x4_t rv_lvr_32256(uint64_t address,uint64_t offset){
struct uint32x2x4_t data;
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x2A, t3, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t3","t4","t5","t6"
);
__asm__ __volatile__(
		"mv %0, t3;\
         mv %1, t4;\
         mv %2, t5;\
         mv %3, t6"
		:"=r"(data.data0),"=r"(data.data1),"=r"(data.data2),"=r"(data.data3)                
		:
        :
);
return data;
}


//64 256 vecstep
void rv_slr_64256_t3(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x4B, t3, %0, %1" //使用add指令，一个目标操作数（命名为dest），
		:                //将add指令的目标操作数dest和C程序中的sum变量绑定。
		:"r"(address),"r"(offset)//将add指令的源操作数srec1和C程序中的add1变量绑定
        :
);
}

void rv_slr_64256(uint64_t address,uint64_t offset,struct uint64x1x4_t data){
__asm__ __volatile__(
		"mv t3, %0;\
         mv t4, %1;\
         mv t5, %2;\
         mv t6, %3"
		:                
		:"r"(data.data0),"r"(data.data1),"r"(data.data2),"r"(data.data3)
        :
);
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x4B, t3, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :
);
}

void rv_llr_64256_t3(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0xB, t3, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t3","t4","t5","t6"
);
}
void rv_llr_64256_s2(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0xB, s2, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"s2","s3","s4","s5"
);
}
void rv_llr_64256_s6(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0xB, s6, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"s6","s7","s8","s9"
);
}

struct uint64x1x4_t rv_llr_64256(uint64_t address,uint64_t offset){
struct uint64x1x4_t data;
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0xB, t3, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t3","t4","t5","t6"
);
__asm__ __volatile__(
		"mv %0, t3;\
         mv %1, t4;\
         mv %2, t5;\
         mv %3, t6"
		:"=r"(data.data0),"=r"(data.data1),"=r"(data.data2),"=r"(data.data3)                
		:
        :
);
return data;
}

void rv_svr_64256_t3(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x6B, t3, %0, %1" //使用add指令，一个目标操作数（命名为dest），
		:                //将add指令的目标操作数dest和C程序中的sum变量绑定。
		:"r"(address),"r"(offset)//将add指令的源操作数srec1和C程序中的add1变量绑定
        :
);
}

void rv_svr_64256(uint64_t address,uint64_t offset,struct uint64x1x4_t data){
__asm__ __volatile__(
		"mv t3, %0;\
         mv t4, %1;\
         mv t5, %2;\
         mv t6, %3"
		:                
		:"r"(data.data0),"r"(data.data1),"r"(data.data2),"r"(data.data3)
        :
);
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x6B, t3, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :
);
}

void rv_lvr_64256_t3(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x2B, t3, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t3","t4","t5","t6"
);
}
void rv_lvr_64256_s2(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x2B, s2, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"s2","s3","s4","s5"
);
}
void rv_lvr_64256_s6(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x2B, s6, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"s6","s7","s8","s9"
);
}

struct uint64x1x4_t rv_lvr_64256(uint64_t address,uint64_t offset){
struct uint64x1x4_t data;
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x2B, t3, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t3","t4","t5","t6"
);
__asm__ __volatile__(
		"mv %0, t3;\
         mv %1, t4;\
         mv %2, t5;\
         mv %3, t6"
		:"=r"(data.data0),"=r"(data.data1),"=r"(data.data2),"=r"(data.data3)                
		:
        :
);
return data;
}

