#include<stdio.h>
#include<math.h>
void func1(float a, float b, float c);
void func3(float a, float b, float c);
int main(int argc, char const *argv[])
{
    float a,b,c;
    scanf("%f %f %f",&a,&b,&c);
    if (b*b-4*a*c>=0)
    {
        func1(a,b,c);
    }
    else
    {
        func3(a,b,c);
    }
    return 0;
}
void func1(float a, float b, float c)
{
    float x1,x2;
    x1 = ((-b)+sqrt(b*b-4*a*c))/(2*a);
    x2 = ((-b)-sqrt(b*b-4*a*c))/(2*a);
    printf("x1=%.3f+0.000i x2=%.3f-0.000i",x1,x2 );
}
void func3(float a,float b,float c)
{
    float h1,imar;
    h1 = -b/(2*a);
    imar = sqrt(-(b*b-4*a*c))/(2*a);
    printf("x1=%.3f+%.3fi x2=%.3f-%.3fi",h1,imar,h1,imar);
}