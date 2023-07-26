// con tro void
#include <stdio.h>
int main()
{
    int i =10;
    double d = 5.1;
    char c = 'A';
    void *ptr;
    ptr = &i;
    printf("test i= %d\n", *(int *)ptr); //ep kieu du lieu con tro void
    ptr = &d;
    printf("test d= %f\n", *(double *)ptr);
    ptr = &c;
    printf("test c= %c\n", *(char *)ptr);
    return 0;
}