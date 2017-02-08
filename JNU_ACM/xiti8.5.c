#include<stdio.h>
#include<string.h>
int main(int argc, char const *argv[])
{
    char a[100];
    int i,j;
    scanf("%s",a);
    i = strlen(a);
    for ( j = 0; j < i; j++)
    {
        printf("%c",a[i-j-1] );
    }
    return 0;
}