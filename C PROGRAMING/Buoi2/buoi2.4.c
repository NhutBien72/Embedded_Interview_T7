#include <stdio.h>

void tong (int a, int b)
{
    printf("tong cua %d va %d la %d\n", a, b, a+b);
}


void hieu (int c, int d)
{
    printf("hieu cua %d va %d la %d\n", c, d, c-d);
}

void tich (int a, int b)
{
    printf("tich cua %d va %d la %d\n", a, b, a*b);
}
//su dung ham con tro
void tinhtoan(void (*func)(int, int), int a, int b) 
{
    printf("tinhtoan\n");
     func(a,b);
}

int main()
{
    tinhtoan(&tong, 5, 6);
    tinhtoan(&tich, 5, 6);
    
//ep kieu con tro ham
    void *ptr = &tong; 
    ((void(*)(int, int))ptr)(3,4);
    ptr = &tich;
    ((void(*)(int, int))ptr)(7,7);

    void *ptr1[] = {&tong, &hieu, &tich};
    ((void(*)(int,int))ptr1[2])(4,5);    

    return 0;
}