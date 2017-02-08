#include <stdio.h>
int main(int argc, char const *argv[])
{
    int a[10];
    int i;
    for ( i = 0; i < 10; i++)
    {
        scanf("%d",&a[i]);
    }
    for (i=0;i<10;i++)
    {
        printf("%d",a[9-i]);
        if(i!=9) putchar(' ');
    }
    return 0;
}