#include<stdio.h>
#include<string.h>
void cat(char a[],char b[]);
int main(int argc, char const *argv[])
{
    char a[100],b[100];
    scanf("%s",a);
    scanf("%s",b);
    cat(a,b);
    return 0;
}
void cat(char a[],char b[])
{
    strcat(a,b);
    printf("%s", a);
}