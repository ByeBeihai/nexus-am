#include <klib.h>
int main() {
for (int i = 0; i < 1; ++i) {
int a = 6;
int b = 5;
uint64_t c =__rv_add8(a,b);
printf("c = %d add16 test pass!\n",c,i+1);
}
}