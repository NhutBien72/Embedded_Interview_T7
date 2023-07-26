#include <stdio.h>
#include <stdint.h>
 typedef struct
 {
    uint8_t x;
    uint16_t y;
    uint32_t z;
 }toado;
 typedef struct
 {
   
    uint8_t x[13];      // 13*1         13 -> 16 du 3
    uint16_t y[15];     //(15-1)*2 =    28 -> 32 du 4
    uint32_t z[10];     //(10-1)*4 =    36 -> 40 du 4
     uint64_t k[3];     // 3*8 = 24 => tong la 16 + 32 + 40 + 24 = 112
 }toado1;
 int main()
 {
    printf("size la %d\n", sizeof(toado1));
 }