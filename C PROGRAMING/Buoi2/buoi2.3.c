//con tro ham
#include <stdio.h>

void tong (int a, int b)
{
    printf("tong cua %d va %d la %d\n", a, b, a+b);
}

void hieu (int c, int d)
{
    printf("hieu cua %d va %d la %d\n", c, d, c-d);
}

int tich (int a, int b)
{
    return a*b;
}

int main()
{
    void (*ptr) (int, int);
    ptr = &tong;
    ptr(8, 7);
    ptr = &hieu;
    ptr(9, 4);
    
    int (*ptr1)(int, int)= &tich;
    printf("tich la %d\n", ptr1(6, 4));
    printf("tich la %d\n", (*ptr1)(3,4));
    return 0;
}