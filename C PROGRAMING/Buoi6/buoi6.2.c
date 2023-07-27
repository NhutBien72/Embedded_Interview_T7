#include <stdio.h>
#include <stdint.h>

typedef union 
{
    struct 
    {
        uint8_t ID[1];
        uint8_t data[3];
        uint8_t checksum[1];
        
    }object;
    uint8_t array[5];
    
}data;

int main()
{
    data test;
    test.object.ID[0]=0x02;
    test.object.data[0]=0x03;
    test.object.data[1]=0x04;
    test.object.data[2]=0x05;
    test.object.checksum[0]=0x06;

}