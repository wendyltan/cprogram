#include <stdio.h>
int main(int argc, char const *argv[])
{
    int m, i, j, s,n;
    scanf("%d",&n);
    for (m = 6; m < n; m++)
    {   
        s = 1;
        for (i = 2; i < m; i++)
            if (m % i == 0) s = s + i;
        if (m - s == 0)
        {
            printf("%d its factors are", m);
            for (j = 1; j < m; j++)
            {
                 
                if (m % j == 0)
                    printf(" %d", j);
 
            }
            printf("\n");
        }
    }
    return 0;
}