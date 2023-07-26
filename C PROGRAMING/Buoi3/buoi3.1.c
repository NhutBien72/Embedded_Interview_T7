#include <stdio.h>
const i =10; //const phan vung text chi doc chu khong doi duoc gia tri
static  int b=20; //bien static lu o phan vung data
void tong(int a, int b)
{
    int c=a+b;                  //a, b la input parameter luu o phan vung stack
    printf("tong %d ", a+b);    // c la bien cuc bo luu o phan vung stack
}
int main()
{
    tong(4,5);
}