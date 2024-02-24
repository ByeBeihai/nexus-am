CROSS_COMPILE := riscv64-linux-gnu-
COMMON_FLAGS  := -fno-pic -march=rv64imc -mcmodel=medany  -mno-relax -flax-vector-conversions 
CFLAGS        += $(COMMON_FLAGS) -static 
ASFLAGS       += $(COMMON_FLAGS) -O3
LDFLAGS       += -melf64lriscv