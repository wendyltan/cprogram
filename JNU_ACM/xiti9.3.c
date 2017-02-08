#include<stdio.h>
#include <math.h>
 
#define S(a,b,c) (a+b+c)/2;
#define AREA(S,a,b,c) sqrt(S*(S-a)*(S-b)*(S-c))
int main(int argc, char const *argv[])
{
    float a,b,c,s,area;
    scanf("%f %f %f",&a,&b,&c);
    s = S(a,b,c);
    area = AREA(s,a,b,c);
    printf("%.3f",area );
    return 0;
}