#include<stdio.h>
int main(int argc, char const *argv[])
{
    float number;
    scanf("%f",&number);
    printf("%6.2f\n",number );
    printf("%6.2f %6.2f\n",number ,number);
    printf("%6.2f %6.2f %6.2f",number,number,number );
    return 0;
}