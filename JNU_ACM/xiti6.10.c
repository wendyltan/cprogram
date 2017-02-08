#include <stdio.h>
int main(int argc, char const *argv[])
{
    int i, sum = 1,n;
    scanf("%d",&n);
    for ( i = 1; i <n; i++)
    {
 
        sum = (sum+1)*2;
    }
    printf("%d", sum);
 
    return 0;
}