#include<stdio.h>
#define LEAP_YEAR(y) if((y%4==0&&y%100!=0)||(y%400==0)) printf("L");else printf("N");
int main(int argc, char const *argv[])
{
    int year;
    scanf("%d",&year);
    LEAP_YEAR(year);
    return 0;
}