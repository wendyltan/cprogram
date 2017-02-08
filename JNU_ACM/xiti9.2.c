#include<stdio.h>
#define YUSHU(a,b) a%b;
int main(int argc, char const *argv[])
{
    int a,b,c;
    scanf("%d %d",&a,&b);
    c = YUSHU(a,b);
    printf("%d",c );
    return 0;
}