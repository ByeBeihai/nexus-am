CROSS_COMPILE := riscv64-linux-gnu-
COMMON_FLAGS  := -fno-pic -march=rv64gcp0p96_zpsfoperand0p96_zpn0p96_zbp0p93_zbt0p93_zbb  -mcmodel=medany -menable-experimental-extensions -mno-relax
CFLAGS        += $(COMMON_FLAGS) -static
ASFLAGS       += $(COMMON_FLAGS) -O0
LDFLAGS       += -melf64lriscv 
