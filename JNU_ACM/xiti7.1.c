#include<stdio.h>
#include <math.h>
int main(int argc, char const *argv[])
{
    int i, j, num, k;
    scanf("%d", &num);
    for ( i = 2; i <= num; i++)
    {
        if (i==2||i==3)
        {
            printf("%d\n",i );
            continue;
        }
        for(j=2;j<=sqrt(i);j++)
        {
 
            k = i % j;
            if (k == 0)
            {
                break;
            }
            else if(k != 0)
            {
                if(j==floor(sqrt(i)))
                {
                    printf("%d\n",i);
                }
            }
        }
         
    }
    return 0;
}