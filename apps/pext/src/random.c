#include <klib.h>
#include <rvp_intrinsic.h>
int main() {

    int16x4_t a = {1,2,3,4};
    uint16x4_t b = {5,6,7,8};
    uint16x4_t c = __rv_v_uadd16(a,b);
    printf("src00 %d src10 %d src20 %d res30 %d\n",a[0],a[1],a[2],a[3]);
    printf("src01 %d res11 %d res21 %d res31 %d\n",b[0],b[1],b[2],b[3]);
    printf("res0  %d res1  %d res2 %d res3 %d\n"  ,c[0],c[1],c[2],c[3]);
    printf("P-EXT ADD16 PASS!!!\n");
}