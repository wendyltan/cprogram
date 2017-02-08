#include <stdio.h>
int main(int argc, char const *argv[])
{
    int n,i;
    long long sum=0,temp=1;
    scanf("%d", &n);
    for ( i = 0; i <n; i++)
    {
        temp += temp*i;
        sum += temp;
    }
    printf("%lld", sum );
 
    return 0;
}