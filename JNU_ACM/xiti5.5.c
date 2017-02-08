#include<stdio.h>
int main()
{
    int x,y;
 
    scanf("%d",&x);
    if(x<1)
        printf("%d",y=x);
    if (x>=1 && x<10)
        printf("%d",y=2*x-1);
    if (x>=10)
        printf("%d",y=3*x-11);
    return 0;
}