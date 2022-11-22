#include <klib.h>
void c(void);

int main(){
asm volatile("li a2,0xffffffff81d8ffc0");
asm volatile("li a4,0x0200000000000000");
asm volatile("sc.d.rl a6,a4,(a2)");
}