#include <stdio.h>
int main(int argc, char const *argv[])
{
    int i, j, k[10],temp,min;
    for (i = 0; i < 10; i++)
    {
        scanf("%d", &k[i]);
    }
     
    for (i = 0; i < 10; i++)
    {
 
        min = i;
        for ( j = i + 1; j < 10; j++)
        {
            if (k[j]<k[min])
            {
                min = j;
            }
        }
        temp = k[min];
        k[min] = k[i];
        k[i] = temp;
    }
    for ( i = 0; i < 10; i++)
    {
        printf("%d\n",k[i] );
    }
    return 0;
}