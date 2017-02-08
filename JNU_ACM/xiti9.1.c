#include<stdio.h>
#define SWITCH(a,b,t) t = b; b = a; a =t;
int main(int argc, char const *argv[])
{
    int a,b,t=1;
    scanf("%d %d",&a,&b);
    SWITCH(a,b,t);
    printf("%d %d",a,b );
    return 0;
}