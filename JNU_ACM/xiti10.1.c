#include<stdio.h>
int main(int argc, char const *argv[])
{
    int a[3],min,temp;
    int i,j;
    for ( i = 0; i < 3; i++)
    {
        scanf("%d",&a[i]);
    }
     
    for (i = 0; i < 3; i++)
    {
        min = i;
        for ( j = i+1; j < 3; j++)
        {
            if (a[j]<a[min])
            {
                min =j;
            }
        }
        temp = a[min];
        a[min]= a[i];
        a[i] = temp;
    }
    for ( i = 0; i <3; i++)
    {
        printf("%d",a[i] );
        putchar(' ');
    }
    return 0;
}