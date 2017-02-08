#include <stdio.h>
struct time {
    int year;
    int month;
    int day;
};
void tell_the_day( int a, int b, int c);
int main(int argc, char const *argv[])
{
    struct time shijian;
    scanf("%d %d %d", &shijian.year, &shijian.month, &shijian.day);
    tell_the_day(shijian.year,shijian.month,shijian.day);
    return 0;
}
void tell_the_day( int a,int b,int c)
{
 
     
    struct time shijian;
    shijian.year = a;
    shijian.month = b;
    shijian.day = c;
    int counter = 0, i, j, flag, flag1 = 0,count,sum;
    if ((shijian.year % 4 == 0 && shijian.year % 100 != 0) || (shijian.year % 400 == 0)) 
        {flag = 1;sum=366;}
    else {flag = 0;sum = 365;}
 
    for ( i = shijian.month; i <= 12; i++)
    {
        if (i % 2 == 0 && i >= 8)
        {
            count = 31;
            if (flag1 == 1) {counter += count; continue;}
 
            for (j = shijian.day; j <=count; j++)
            {
                counter++;
                flag1 = 1;
            }
 
        }
        if (i % 2 == 0 && i < 8)
        {
            if (i == 2)
            {
                count = flag + 28;
            }
            else
                count = 30;
            if (flag1 == 1) {counter += count; continue;}
            for (j = shijian.day; j <=count; j++)
            {
                counter++;
                flag1 = 1;
            }
 
        }
        if (i % 2 != 0 && i <= 7)
        {
            count = 31;
            if (flag1 == 1) {counter += count; continue;}
            for (j = shijian.day; j <=count; j++)
            {
                counter++;;
                flag1 = 1;
            }
        }
        if (i % 2 != 0 && i > 7)
        {
            count = 30;
            if (flag1 == 1) {counter += count; continue;}
            for (j = shijian.day; j <=count; j++)
            {
                counter++;
                flag1 = 1;
            }
        }
 
    }
    printf("%d", sum-counter+1);
 
}