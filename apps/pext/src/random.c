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
    printf("src00 %d src10 %d src20 %d res30 %d\n",a.src0,a.src1,a.src2,a.src3);
    printf("src01 %d res11 %d res21 %d res31 %d\n",b.src0,b.src1,b.src2,b.src3);
    printf("res0  %d res1  %d res2 %d res3 %d\n",((uint16x4_t*)(&c))->src0,((uint16x4_t*)(&c))->src1,((uint16x4_t*)(&c))->src2,((uint16x4_t*)(&c))->src3);
    printf("P-EXT ADD16 PASS!!!\n");
}