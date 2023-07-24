#include <rvp_intrinsic.h>

struct uint16x4x1_t{
    uint16x4_t data0;
};   
struct uint8x8x1_t{
    uint8x8_t data0;
};   
struct uint32x2x1_t{
    uint32x2_t data0;
};   
struct uint64x1x1_t{
    uint64_t data0;
};   

//16 64
void rv_slr_1664_t3(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x41, t3, %0, %1" //使用add指令，一个目标操作数（命名为dest），
		:                //将add指令的目标操作数dest和C程序中的sum变量绑定。
		:"r"(address),"r"(offset)//将add指令的源操作数srec1和C程序中的add1变量绑定
        :
);
}

void rv_slr_1664(uint64_t address,uint64_t offset,struct uint16x4x1_t data){
__asm__ __volatile__(
		"mv t3, %0"
		:                
		:"r"(data.data0)
        :
);
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x41, t3, %0, %1" //使用add指令，一个目标操作数（命名为dest），
		:                //将add指令的目标操作数dest和C程序中的sum变量绑定。
		:"r"(address),"r"(offset)//将add指令的源操作数srec1和C程序中的add1变量绑定
        :
);
}
void rv_llr_1664_t0(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x1, t0, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t0"
);
}
void rv_llr_1664_t1(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x1, t1, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t1"
);
}
void rv_llr_1664_t2(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x1, t2, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t2"
);
}
void rv_llr_1664_t3(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x1, t3, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t3"
);
}
void rv_llr_1664_t4(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x1, t4, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t4"
);
}
void rv_llr_1664_t5(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x1, t5, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t5"
);
}
void rv_llr_1664_t6(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x1, t6, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t6"
);
}

struct uint16x4x1_t rv_llr_1664(uint64_t address,uint64_t offset){
struct uint16x4x1_t data;
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x1, t3, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t3"
);
__asm__ __volatile__(
		"mv %0, t3"
		:"=r"(data.data0)           
		:
        :
);
return data;
}

void rv_svr_1664_t3(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x61, t3, %0, %1" //使用add指令，一个目标操作数（命名为dest），
		:                //将add指令的目标操作数dest和C程序中的sum变量绑定。
		:"r"(address),"r"(offset)//将add指令的源操作数srec1和C程序中的add1变量绑定
        :
);
}

void rv_svr_1664(uint64_t address,uint64_t offset,struct uint16x4x1_t data){
__asm__ __volatile__(
		"mv t3, %0;"
		:                
		:"r"(data.data0)
        :
);
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x61, t3, %0, %1" //使用add指令，一个目标操作数（命名为dest），
		:                //将add指令的目标操作数dest和C程序中的sum变量绑定。
		:"r"(address),"r"(offset)//将add指令的源操作数srec1和C程序中的add1变量绑定
        :
);
}

void rv_lvr_1664_t0(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x21, t0, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t0"
);
}
void rv_lvr_1664_t1(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x21, t1, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t1"
);
}
void rv_lvr_1664_t2(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x21, t2, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t2"
);
}
void rv_lvr_1664_t3(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x21, t3, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t3"
);
}
void rv_lvr_1664_t4(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x21, t4, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t4"
);
}
void rv_lvr_1664_t5(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x21, t5, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t5"
);
}
void rv_lvr_1664_t6(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x21, t6, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t6"
);
}

struct uint16x4x1_t rv_lvr_1664(uint64_t address,uint64_t offset){
struct uint16x4x1_t data;
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x21, t3, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t3"
);
__asm__ __volatile__(
		"mv %0, t3"
		:"=r"(data.data0)       
		:
        :
);
return data;
}

//8 64
void rv_slr_0864_t3(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x40, t3, %0, %1" //使用add指令，一个目标操作数（命名为dest），
		:                //将add指令的目标操作数dest和C程序中的sum变量绑定。
		:"r"(address),"r"(offset)//将add指令的源操作数srec1和C程序中的add1变量绑定
        :
);
}

void rv_slr_0864(uint64_t address,uint64_t offset,struct uint8x8x1_t data){
__asm__ __volatile__(
		"mv t3, %0"
		:                
		:"r"(data.data0)
        :
);
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x40, t3, %0, %1" //使用add指令，一个目标操作数（命名为dest），
		:                //将add指令的目标操作数dest和C程序中的sum变量绑定。
		:"r"(address),"r"(offset)//将add指令的源操作数srec1和C程序中的add1变量绑定
        :
);
}
void rv_llr_0864_t0(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x0, t0, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t0"
);
}
void rv_llr_0864_t1(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x0, t1, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t1"
);
}
void rv_llr_0864_t2(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x0, t2, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t2"
);
}
void rv_llr_0864_t3(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x0, t3, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t3"
);
}
void rv_llr_0864_t4(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x0, t4, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t4"
);
}
void rv_llr_0864_t5(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x0, t5, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t5"
);
}
void rv_llr_0864_t6(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x0, t6, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t6"
);
}

struct uint8x8x1_t rv_llr_0864(uint64_t address,uint64_t offset){
struct uint8x8x1_t data;
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x0, t3, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t3"
);
__asm__ __volatile__(
		"mv %0, t3"
		:"=r"(data.data0)           
		:
        :
);
return data;
}

void rv_svr_0864_t3(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x60, t3, %0, %1" //使用add指令，一个目标操作数（命名为dest），
		:                //将add指令的目标操作数dest和C程序中的sum变量绑定。
		:"r"(address),"r"(offset)//将add指令的源操作数srec1和C程序中的add1变量绑定
        :
);
}

void rv_svr_0864(uint64_t address,uint64_t offset,struct uint8x8x1_t data){
__asm__ __volatile__(
		"mv t3, %0;"
		:                
		:"r"(data.data0)
        :
);
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x60, t3, %0, %1" //使用add指令，一个目标操作数（命名为dest），
		:                //将add指令的目标操作数dest和C程序中的sum变量绑定。
		:"r"(address),"r"(offset)//将add指令的源操作数srec1和C程序中的add1变量绑定
        :
);
}

void rv_lvr_0864_t0(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x20, t0, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t0"
);
}
void rv_lvr_0864_t1(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x20, t1, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t1"
);
}
void rv_lvr_0864_t2(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x20, t2, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t2"
);
}
void rv_lvr_0864_t3(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x20, t3, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t3"
);
}
void rv_lvr_0864_t4(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x20, t4, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t4"
);
}
void rv_lvr_0864_t5(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x20, t5, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t5"
);
}
void rv_lvr_0864_t6(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x20, t6, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t6"
);
}

struct uint8x8x1_t rv_lvr_0864(uint64_t address,uint64_t offset){
struct uint8x8x1_t data;
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x20, t3, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t3"
);
__asm__ __volatile__(
		"mv %0, t3"
		:"=r"(data.data0)       
		:
        :
);
return data;
}

//32 64
void rv_slr_3264_t3(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x42, t3, %0, %1" //使用add指令，一个目标操作数（命名为dest），
		:                //将add指令的目标操作数dest和C程序中的sum变量绑定。
		:"r"(address),"r"(offset)//将add指令的源操作数srec1和C程序中的add1变量绑定
        :
);
}

void rv_slr_3264(uint64_t address,uint64_t offset,struct uint32x2x1_t data){
__asm__ __volatile__(
		"mv t3, %0"
		:                
		:"r"(data.data0)
        :
);
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x42, t3, %0, %1" //使用add指令，一个目标操作数（命名为dest），
		:                //将add指令的目标操作数dest和C程序中的sum变量绑定。
		:"r"(address),"r"(offset)//将add指令的源操作数srec1和C程序中的add1变量绑定
        :
);
}
void rv_llr_3264_t0(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x2, t0, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t0"
);
}
void rv_llr_3264_t1(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x2, t1, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t1"
);
}
void rv_llr_3264_t2(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x2, t2, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t2"
);
}
void rv_llr_3264_t3(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x2, t3, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t3"
);
}
void rv_llr_3264_t4(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x2, t4, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t4"
);
}
void rv_llr_3264_t5(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x2, t5, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t5"
);
}
void rv_llr_3264_t6(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x2, t6, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t6"
);
}

struct uint32x2x1_t rv_llr_3264(uint64_t address,uint64_t offset){
struct uint32x2x1_t data;
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x2, t3, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t3"
);
__asm__ __volatile__(
		"mv %0, t3"
		:"=r"(data.data0)           
		:
        :
);
return data;
}

void rv_svr_3264_t3(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x62, t3, %0, %1" //使用add指令，一个目标操作数（命名为dest），
		:                //将add指令的目标操作数dest和C程序中的sum变量绑定。
		:"r"(address),"r"(offset)//将add指令的源操作数srec1和C程序中的add1变量绑定
        :
);
}

void rv_svr_3264(uint64_t address,uint64_t offset,struct uint32x2x1_t data){
__asm__ __volatile__(
		"mv t3, %0;"
		:                
		:"r"(data.data0)
        :
);
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x62, t3, %0, %1" //使用add指令，一个目标操作数（命名为dest），
		:                //将add指令的目标操作数dest和C程序中的sum变量绑定。
		:"r"(address),"r"(offset)//将add指令的源操作数srec1和C程序中的add1变量绑定
        :
);
}

void rv_lvr_3264_t0(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x22, t0, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t0"
);
}
void rv_lvr_3264_t1(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x22, t1, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t1"
);
}
void rv_lvr_3264_t2(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x22, t2, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t2"
);
}
void rv_lvr_3264_t3(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x22, t3, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t3"
);
}
void rv_lvr_3264_t4(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x22, t4, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t4"
);
}
void rv_lvr_3264_t5(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x22, t5, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t5"
);
}
void rv_lvr_3264_t6(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x22, t6, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t6"
);
}

struct uint32x2x1_t rv_lvr_3264(uint64_t address,uint64_t offset){
struct uint32x2x1_t data;
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x22, t3, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t3"
);
__asm__ __volatile__(
		"mv %0, t3"
		:"=r"(data.data0)       
		:
        :
);
return data;
}

//64 64
void rv_slr_6464_t3(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x43, t3, %0, %1" //使用add指令，一个目标操作数（命名为dest），
		:                //将add指令的目标操作数dest和C程序中的sum变量绑定。
		:"r"(address),"r"(offset)//将add指令的源操作数srec1和C程序中的add1变量绑定
        :
);
}

void rv_slr_6464(uint64_t address,uint64_t offset,struct uint64x1x1_t data){
__asm__ __volatile__(
		"mv t3, %0"
		:                
		:"r"(data.data0)
        :
);
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x43, t3, %0, %1" //使用add指令，一个目标操作数（命名为dest），
		:                //将add指令的目标操作数dest和C程序中的sum变量绑定。
		:"r"(address),"r"(offset)//将add指令的源操作数srec1和C程序中的add1变量绑定
        :
);
}
void rv_llr_6464_t0(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x3, t0, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t0"
);
}
void rv_llr_6464_t1(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x3, t1, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t1"
);
}
void rv_llr_6464_t2(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x3, t2, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t2"
);
}
void rv_llr_6464_t3(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x3, t3, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t3"
);
}
void rv_llr_6464_t4(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x3, t4, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t4"
);
}
void rv_llr_6464_t5(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x3, t5, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t5"
);
}
void rv_llr_6464_t6(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x3, t6, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t6"
);
}

struct uint64x1x1_t rv_llr_6464(uint64_t address,uint64_t offset){
struct uint64x1x1_t data;
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x3, t3, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t3"
);
__asm__ __volatile__(
		"mv %0, t3"
		:"=r"(data.data0)           
		:
        :
);
return data;
}

void rv_svr_6464_t3(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x63, t3, %0, %1" //使用add指令，一个目标操作数（命名为dest），
		:                //将add指令的目标操作数dest和C程序中的sum变量绑定。
		:"r"(address),"r"(offset)//将add指令的源操作数srec1和C程序中的add1变量绑定
        :
);
}

void rv_svr_6464(uint64_t address,uint64_t offset,struct uint64x1x1_t data){
__asm__ __volatile__(
		"mv t3, %0;"
		:                
		:"r"(data.data0)
        :
);
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x63, t3, %0, %1" //使用add指令，一个目标操作数（命名为dest），
		:                //将add指令的目标操作数dest和C程序中的sum变量绑定。
		:"r"(address),"r"(offset)//将add指令的源操作数srec1和C程序中的add1变量绑定
        :
);
}

void rv_lvr_6464_t0(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x23, t0, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t0"
);
}
void rv_lvr_6464_t1(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x23, t1, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t1"
);
}
void rv_lvr_6464_t2(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x23, t2, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t2"
);
}
void rv_lvr_6464_t3(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x23, t3, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t3"
);
}
void rv_lvr_6464_t4(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x23, t4, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t4"
);
}
void rv_lvr_6464_t5(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x23, t5, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t5"
);
}
void rv_lvr_6464_t6(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x23, t6, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t6"
);
}

struct uint64x1x1_t rv_lvr_6464(uint64_t address,uint64_t offset){
struct uint64x1x1_t data;
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x23, t3, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t3"
);
__asm__ __volatile__(
		"mv %0, t3"
		:"=r"(data.data0)       
		:
        :
);
return data;
}

