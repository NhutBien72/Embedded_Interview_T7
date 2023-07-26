#include <stdio.h>
void test()
{
    static int a =10;       // bien static cuc bo van giu nguyen gia tri, khong bi thu hoi vung nho
    printf("a= %d\n", a);
    a++;
}

int *ptr()
{
    static int b = 10;  //tham so tra ve dia chi tuong dung static
    return &b;
}

int main()
{
    test();
    test();
    printf("%d\n", *ptr());
}