#include<stdio.h>
#define MAX(a,b,c,max) a = max;if(a>b) b=max;if(max>c) printf("%.3f\n",max );else printf("%.3f\n",c );
void max(float a,float b,float c);
int main(int argc, char const *argv[])
{
    float a,b,c,d;
    scanf("%f %f %f",&a,&b,&c);
    max(a,b,c);
    MAX(a,b,c,d);
     
    return 0;
}
void max(float a,float b,float c)
{
    float max;
    if (a>b)
    {
        a = max;
    }
    else
        b = max;
    if (max>c)
    {
        printf("%.3f\n",max );
    }
    else
        printf("%.3f\n",c );
}