#include <stdio.h>
int a=10;
void test()
{
    printf("this is test\n");
}
int main()
{
    int *ptr = &a; // con tro ptr tro toi dia chi cua a
    printf("dia chi test %p\n", &test);
    printf("dia chi cua a la %p\n", ptr); //gia tri cua ptr la dia chi cua a
    printf("gia tri cua a la %d\n", *ptr);//*ptr la gia tri cua dia chi con tro ptr tro toi
    return 0;
}