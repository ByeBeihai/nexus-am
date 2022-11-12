#include <klib.h>
int main() {
    for (int i = 0; i < 1; ++i) {
        int a = 6;
        int b = 5;
        int c = __rv_add16(a,b); //CALL Add16 instr
        if(c == 11)
            printf("c = %d add16 test pass!\n",c);
        else
            printf("c = %d error！\n",c);
    }
}