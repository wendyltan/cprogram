#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    int n,m;
    int i,j;
    scanf("%d",&n);
    char a[n+1];
    getchar();
    gets(a);
    scanf("%d",&m);
    char b[n-m+1];
    i = 0 ;
    j = m-1;
    while(a[j]!='\0')
    {
        b[i] = a[j];
        j++;
        i++;
    }
    for ( i = 0; i < n-m+1; i++)
    {
        printf("%c",b[i] );
    }
    return 0;
}