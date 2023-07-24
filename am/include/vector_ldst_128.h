#include <rvp_intrinsic.h>

struct uint16x4x2_t{
    uint16x4_t data0;
    uint16x4_t data1;
};      
struct uint8x8x2_t{
    uint8x8_t data0;
    uint8x8_t data1;
};   
struct uint32x2x2_t{
    uint8x8_t data0;
    uint8x8_t data1;
}; 
struct uint64x1x2_t{
    uint64_t data0;
    uint64_t data1;
};        

//16 128 
void rv_slr_16128_t3(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x45, t3, %0, %1" //使用add指令，一个目标操作数（命名为dest），
		:                //将add指令的目标操作数dest和C程序中的sum变量绑定。
		:"r"(address),"r"(offset)//将add指令的源操作数srec1和C程序中的add1变量绑定
        :
);
}

void rv_slr_16128(uint64_t address,uint64_t offset,struct uint16x4x2_t data){
__asm__ __volatile__(
		"mv t3, %0;\
         mv t4, %1"
		:                
		:"r"(data.data0),"r"(data.data1)
        :
);
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x45, t3, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :
);
}
void rv_llr_16128_t1(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x5, t1, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t1","t2"
);
}
void rv_llr_16128_t3(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x5, t3, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t3","t4"
);
}
void rv_llr_16128_t5(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x5, t5, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t5","t6"
);
}
void rv_llr_16128_s2(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x5, s2, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"s2","s3"
);
}
void rv_llr_16128_s4(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x5, s4, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"s4","s5"
);
}

struct uint16x4x2_t rv_llr_16128(uint64_t address,uint64_t offset){
struct uint16x4x2_t data;
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x5, t3, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t3","t4"
);
__asm__ __volatile__(
		"mv %0, t3;\
         mv %1, t4;"
		:"=r"(data.data0),"=r"(data.data1)           
		:
        :
);
return data;
}

void rv_svr_16128_t3(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x65, t3, %0, %1" //使用add指令，一个目标操作数（命名为dest），
		:                //将add指令的目标操作数dest和C程序中的sum变量绑定。
		:"r"(address),"r"(offset)//将add指令的源操作数srec1和C程序中的add1变量绑定
        :
);
}

void rv_svr_16128(uint64_t address,uint64_t offset,struct uint16x4x2_t data){
__asm__ __volatile__(
		"mv t3, %0;\
         mv t4, %1"
		:                
		:"r"(data.data0),"r"(data.data1)
        :
);
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x65, t3, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :
);
}
void rv_lvr_16128_t1(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x25, t1, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t1","t2"
);
}
void rv_lvr_16128_t3(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x25, t3, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t3","t4"
);
}
void rv_lvr_16128_t5(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x25, t5, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t5","t6"
);
}
void rv_lvr_16128_s2(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x25, s2, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"s2","s3"
);
}
void rv_lvr_16128_s4(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x25, s4, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"s4","s5"
);
}

struct uint16x4x2_t rv_lvr_16128(uint64_t address,uint64_t offset){
struct uint16x4x2_t data;
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x25, t3, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t3","t4"
);
__asm__ __volatile__(
		"mv %0, t3;\
         mv %1, t4;"
		:"=r"(data.data0),"=r"(data.data1)           
		:
        :
);
return data;
}

//8 128 
void rv_slr_08128_t3(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x44, t3, %0, %1" //使用add指令，一个目标操作数（命名为dest），
		:                //将add指令的目标操作数dest和C程序中的sum变量绑定。
		:"r"(address),"r"(offset)//将add指令的源操作数srec1和C程序中的add1变量绑定
        :
);
}

void rv_slr_08128(uint64_t address,uint64_t offset,struct uint8x8x2_t data){
__asm__ __volatile__(
		"mv t3, %0;\
         mv t4, %1"
		:                
		:"r"(data.data0),"r"(data.data1)
        :
);
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x44, t3, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :
);
}
void rv_llr_08128_t1(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x4, t1, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t1","t2"
);
}
void rv_llr_08128_t3(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x4, t3, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t3","t4"
);
}
void rv_llr_08128_t5(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x4, t5, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t5","t6"
);
}
void rv_llr_08128_s2(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x4, s2, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"s2","s3"
);
}
void rv_llr_08128_s4(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x4, s4, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"s4","s5"
);
}

struct uint8x8x2_t rv_llr_08128(uint64_t address,uint64_t offset){
struct uint8x8x2_t data;
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x4, t3, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t3","t4"
);
__asm__ __volatile__(
		"mv %0, t3;\
         mv %1, t4;"
		:"=r"(data.data0),"=r"(data.data1)           
		:
        :
);
return data;
}

void rv_svr_08128_t3(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x64, t3, %0, %1" //使用add指令，一个目标操作数（命名为dest），
		:                //将add指令的目标操作数dest和C程序中的sum变量绑定。
		:"r"(address),"r"(offset)//将add指令的源操作数srec1和C程序中的add1变量绑定
        :
);
}

void rv_svr_08128(uint64_t address,uint64_t offset,struct uint8x8x2_t data){
__asm__ __volatile__(
		"mv t3, %0;\
         mv t4, %1"
		:                
		:"r"(data.data0),"r"(data.data1)
        :
);
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x64, t3, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :
);
}
void rv_lvr_08128_t1(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x24, t1, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t1","t2"
);
}
void rv_lvr_08128_t3(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x24, t3, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t3","t4"
);
}
void rv_lvr_08128_t5(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x24, t5, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t5","t6"
);
}
void rv_lvr_08128_s2(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x24, s2, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"s2","s3"
);
}
void rv_lvr_08128_s4(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x24, s4, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"s4","s5"
);
}

struct uint8x8x2_t rv_lvr_08128(uint64_t address,uint64_t offset){
struct uint8x8x2_t data;
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x24, t3, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t3","t4"
);
__asm__ __volatile__(
		"mv %0, t3;\
         mv %1, t4;"
		:"=r"(data.data0),"=r"(data.data1)           
		:
        :
);
return data;
}

//32 128 
void rv_slr_32128_t3(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x46, t3, %0, %1" //使用add指令，一个目标操作数（命名为dest），
		:                //将add指令的目标操作数dest和C程序中的sum变量绑定。
		:"r"(address),"r"(offset)//将add指令的源操作数srec1和C程序中的add1变量绑定
        :
);
}

void rv_slr_32128(uint64_t address,uint64_t offset,struct uint32x2x2_t data){
__asm__ __volatile__(
		"mv t3, %0;\
         mv t4, %1"
		:                
		:"r"(data.data0),"r"(data.data1)
        :
);
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x46, t3, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :
);
}
void rv_llr_32128_t1(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x6, t1, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t1","t2"
);
}
void rv_llr_32128_t3(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x6, t3, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t3","t4"
);
}
void rv_llr_32128_t5(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x6, t5, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t5","t6"
);
}
void rv_llr_32128_s2(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x6, s2, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"s2","s3"
);
}
void rv_llr_32128_s4(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x6, s4, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"s4","s5"
);
}

struct uint32x2x2_t rv_llr_32128(uint64_t address,uint64_t offset){
struct uint32x2x2_t data;
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x6, t3, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t3","t4"
);
__asm__ __volatile__(
		"mv %0, t3;\
         mv %1, t4;"
		:"=r"(data.data0),"=r"(data.data1)           
		:
        :
);
return data;
}

void rv_svr_32128_t3(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x66, t3, %0, %1" //使用add指令，一个目标操作数（命名为dest），
		:                //将add指令的目标操作数dest和C程序中的sum变量绑定。
		:"r"(address),"r"(offset)//将add指令的源操作数srec1和C程序中的add1变量绑定
        :
);
}

void rv_svr_32128(uint64_t address,uint64_t offset,struct uint32x2x2_t data){
__asm__ __volatile__(
		"mv t3, %0;\
         mv t4, %1"
		:                
		:"r"(data.data0),"r"(data.data1)
        :
);
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x66, t3, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :
);
}
void rv_lvr_32128_t1(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x26, t1, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t1","t2"
);
}
void rv_lvr_32128_t3(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x26, t3, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t3","t4"
);
}
void rv_lvr_32128_t5(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x26, t5, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t5","t6"
);
}
void rv_lvr_32128_s2(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x26, s2, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"s2","s3"
);
}
void rv_lvr_32128_s4(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x26, s4, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"s4","s5"
);
}

struct uint32x2x2_t rv_lvr_32128(uint64_t address,uint64_t offset){
struct uint32x2x2_t data;
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x26, t3, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t3","t4"
);
__asm__ __volatile__(
		"mv %0, t3;\
         mv %1, t4;"
		:"=r"(data.data0),"=r"(data.data1)           
		:
        :
);
return data;
}

//64 128 
void rv_slr_64128_t3(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x47, t3, %0, %1" //使用add指令，一个目标操作数（命名为dest），
		:                //将add指令的目标操作数dest和C程序中的sum变量绑定。
		:"r"(address),"r"(offset)//将add指令的源操作数srec1和C程序中的add1变量绑定
        :
);
}

void rv_slr_64128(uint64_t address,uint64_t offset,struct uint64x1x2_t data){
__asm__ __volatile__(
		"mv t3, %0;\
         mv t4, %1"
		:                
		:"r"(data.data0),"r"(data.data1)
        :
);
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x47, t3, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :
);
}
void rv_llr_64128_t1(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x7, t1, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t1","t2"
);
}
void rv_llr_64128_t3(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x7, t3, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t3","t4"
);
}
void rv_llr_64128_t5(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x7, t5, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t5","t6"
);
}
void rv_llr_64128_s2(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x7, s2, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"s2","s3"
);
}
void rv_llr_64128_s4(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x7, s4, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"s4","s5"
);
}

struct uint64x1x2_t rv_llr_64128(uint64_t address,uint64_t offset){
struct uint64x1x2_t data;
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x7, t3, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t3","t4"
);
__asm__ __volatile__(
		"mv %0, t3;\
         mv %1, t4;"
		:"=r"(data.data0),"=r"(data.data1)           
		:
        :
);
return data;
}

void rv_svr_64128_t3(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x67, t3, %0, %1" //使用add指令，一个目标操作数（命名为dest），
		:                //将add指令的目标操作数dest和C程序中的sum变量绑定。
		:"r"(address),"r"(offset)//将add指令的源操作数srec1和C程序中的add1变量绑定
        :
);
}

void rv_svr_64128(uint64_t address,uint64_t offset,struct uint64x1x2_t data){
__asm__ __volatile__(
		"mv t3, %0;\
         mv t4, %1"
		:                
		:"r"(data.data0),"r"(data.data1)
        :
);
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x67, t3, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :
);
}
void rv_lvr_64128_t1(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x27, t1, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t1","t2"
);
}
void rv_lvr_64128_t3(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x27, t3, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t3","t4"
);
}
void rv_lvr_64128_t5(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x27, t5, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t5","t6"
);
}
void rv_lvr_64128_s2(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x27, s2, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"s2","s3"
);
}
void rv_lvr_64128_s4(uint64_t address,uint64_t offset){
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x27, s4, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"s4","s5"
);
}

struct uint64x1x2_t rv_lvr_64128(uint64_t address,uint64_t offset){
struct uint64x1x2_t data;
__asm__ __volatile__(
		".insn r 0x77, 0x3, 0x27, t3, %0, %1" 
		:                
		:"r"(address),"r"(offset)
        :"t3","t4"
);
__asm__ __volatile__(
		"mv %0, t3;\
         mv %1, t4;"
		:"=r"(data.data0),"=r"(data.data1)           
		:
        :
);
return data;
}

