#include <stdio.h>
#include <stdint.h>
//bien
uint32_t var; // có 2^32 giá trị từ 0 -> 2^32 - 1
int16_t var2; // có giá trị từ -(2^16)/2 -> (2^16)/2 - 1
void tong(int a, int b)
{
    printf("Tong cua %d va %d = %d\n", a, b, a+b);
}
int main()
{
    tong(1,2);
    return 0;
}