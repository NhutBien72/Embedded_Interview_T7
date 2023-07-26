#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
 int main()
 {
    uint16_t *ptr = (uint16_t *)malloc(2*5);                    //uint16_t 2byte
    uint16_t *ptr1 = (uint16_t*)malloc(sizeof(uint16_t)*5);     //cach 2
     for(int i=0; i<5; i++)
    {
        ptr[i]= 2*i;
    }
    for(int i=0; i<5; i++)
    {
        printf("i= %d\n", ptr[i]);
    }
    ptr = (uint16_t *)realloc(ptr, sizeof(uint16_t)*7); //thay doi 5 thanh 7 o nho
    return 0;
    free(ptr);  //thu hoi vung nho
 }