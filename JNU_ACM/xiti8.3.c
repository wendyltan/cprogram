#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void prime(int num);
int main()
{
    int num;
    scanf("%d", &num);
    if (num>1)
    {
        prime(num);
    }
    else
    {
        printf("not prime");
    } 
    return 0;
}
void prime(int num)
{
    int i, j;
 
    if (num==2||num==3)
    {
        printf("prime");
    }
    for (i = 2; i <= sqrt(num); i++)
    {
 
        j = num % i;
        if (j == 0)
        {
            printf("not prime");
            exit(0);
        }
    }
    if(i==sqrt(num)+1) printf("prime");
 
}