#include <stdio.h>
#include <stdint.h>
struct ToaDo
{
    uint8_t x;
    uint8_t y;
};
struct KetQua
{
    float x1;
    float x2;
};
typedef struct KetQua KetQua;
KetQua Hept(int a, int b, int c)
{
    KetQua DapAn;
    return DapAn;
}
int main()
{
    struct ToaDo diemM;
    diemM.x = 10;
    diemM.y = 3;
    printf("toa do diem M la %d, %d\n", diemM.x, diemM.y);
    KetQua DapAn = {.x1=10, .x2=20};
    printf("test=%f %f\n", DapAn.x1, DapAn.x2);
    return 0;
}