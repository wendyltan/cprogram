#include <stdio.h>
int main(int argc, char const *argv[])
{
    float M,N,sum=0;
    int n;
    scanf("%f %d",&M,&n);
    int i = 1;
    while(i<=n)
    {
        N = 0.5*M;
        sum = M+N+sum;
        M = N;
        i++;
    }
    printf("%.2f %.2f",N,sum-N );
    return 0;   
}