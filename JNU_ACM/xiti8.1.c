#include <stdio.h>
int gongyueshu(int a,int  b);
void gongbeishu(int m);
 
int main(int argc, char const *argv[])
{
    int a, b, m;
    scanf("%d %d", &a, &b);
    m = gongyueshu(a, b);
    gongbeishu(m);
 
    return 0;
}
int gongyueshu(int a, int b)
{
    int m, n,c;
    m = a;
    n = b;
    while (b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    printf("%d ", a);
 
    return (m * n) / a;
}
void gongbeishu(int m)
{
    printf("%d", m);
}