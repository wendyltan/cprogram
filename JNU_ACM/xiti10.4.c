#include <stdio.h>
int main(int argc, char const *argv[])
{
    int i, j, n;
     
    scanf("%d", &n);
    int a[n], m;
    for ( i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    scanf("%d", &m);
    for ( i = n-m; i <=n-1; i++)
    {
        printf("%d ",a[i] );
    }
    for ( i = 0; i <n-m; i++)
    {
        printf("%d",a[i]);
 
        putchar(' ');
 
    }
 
    return 0;
}