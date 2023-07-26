#include <stdio.h>
#include <stdint.h>
int main()
{
    uint16_t array[] = {1,3,5,7,9};
    uint16_t *ptr = array;
    printf("dia chi cua mang %p\n", array);
    for(int i=0;i<5;i++)
    {
        printf("dia chi cua phan tu thu %d la %p\n", i, array+i);
    }
    for(int j=0; j<5; j++)
    {
        printf("gia tri cua phan tu %d la %p\n", j, *(ptr+j));
    }
    return 0;
}