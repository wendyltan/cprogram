#include <stdio.h>
int main()
{
    int a,b,c,sum1=0,sum2=0;
    float i,sum3=0,sum4 ;
    scanf("%d %d %d",&a,&b,&c);
    for (i = 1; i <=a; i++)
    {
        sum1 += i;
    }
    for (i = 1; i <=b; i++)
    {
        sum2 += (i*i);
    }
    for ( i = 1; i <=c; i++)
    {
        sum3 += (1/i);
    }
    sum4 = sum1+sum2+sum3;
    printf("%.2f",sum4 );
 
    return 0;
}