#include <stdio.h>
int main(int argc, char const *argv[])
{
    int i = 1; 
    long int n; 
    double t, x = 1, y = 2, s, sum = 0;
    scanf("%ld", &n);
    while (i <= n)
    {
        s = y / x;
        sum = sum + s;
        t = y;
        y = y + x;
        x = t;
        i++;
    }
    printf("%.2f", sum);
    return 0;
}