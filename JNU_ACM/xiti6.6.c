#include <stdio.h>
#include <math.h>
 
int main(int argc, char const *argv[])
{
    int i;
    for (i = 100; i < 1000; i++)
    {
        int a = i%10;//ge wei
        int b = i%100/10;//shi wei
        int c = i/100;//baiwei
        if (pow(a,3)+pow(b,3)+pow(c,3)==i)
        {
            printf("%d\n",i );
        }
    }
    return 0;
}