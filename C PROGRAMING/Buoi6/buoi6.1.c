#include <stdio.h>
#include <stdint.h>
 typedef union
 {
    uint8_t x[5];
    uint8_t y[3]; 
    uint8_t z[6];
 }huhu;
 int main()
 {
   huhu var;
    for (int i=0; i<5;i++)
    {
        var.x[i]=i;
    }
    for (int i=0; i<3; i++)
    {
        var.y[i] = i*2; 
    }
    /* for (int i=0; i<6; i++)
    {
        var.z[i]= i*3;
    } */
    for(int i=0; i<5;i++)
    {
    printf("%d\n", var.y[i]);
    }
    return 0;
 }