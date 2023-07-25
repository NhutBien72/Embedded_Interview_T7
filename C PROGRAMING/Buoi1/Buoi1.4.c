#include <stdio.h>
#include <stdint.h>
typedef enum {thu2=2, thu3, thu4, thu5, thu6, thu7, cn}thu;
int main()
{
    thu Thu = thu4;
    switch(Thu)
    {
        case 2:
        printf("T2");
        break;
        case 3:
        printf("T3");
        break;
    case 4:
        printf("T4");
        break;
    case 5:
        printf("T5");
        break;
    case 6:
        printf("T6");
        break;
    case 7:
        printf("T7");
        break;
    case 8:
        printf("CN");
        break;
    default:
        printf("thu k hop le");
    }
}