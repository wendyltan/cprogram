#include<stdio.h>
int main(int argc, char const *argv[])
{
    int i,j,temp,min;
    int a[10];
    for ( i = 0; i < 9; i++)
    {
        scanf(" %d",&a[i]);
    }
    scanf("%d",&a[9]);
    for ( i = 0; i < 10; i++)
    {
        min = i;
        for ( j = i+1; j < 10; j++)
        {
            if (a[j]<a[min])
            {
                min = j;
            }
        }
        temp = a[min];
        a[min]= a[i];
        a[i] = temp;
    }
    for ( i = 0; i < 10; i++)
    {
        printf("%d\n",a[i] );
    }
 
    return 0;
}