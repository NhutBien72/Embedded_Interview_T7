#include "date.h"
#include <stdio.h>

extern const char *days[];

int main(){
    int day, month, year;

    printf("Enter day: ");
    scanf("%d", &day);

    printf("Enter month: ");
    scanf("%d", &month);

    printf("Enter year: ");
    scanf("%d", &year);

    if (!validDate(day, month, year)){
        printf("The entered date is not valid.\n");
        return 1;
    }

    int dayWeek = dayOfWeek(day, month, year);
    printf("The date %d/%d/%d falls on a %s.\n", day, month, year, days[dayWeek]);
    return 0;
}