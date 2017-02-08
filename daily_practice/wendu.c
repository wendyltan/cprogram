#include<stdio.h>
int main()
{
	float f,c;
	printf("please enter a Fahrenheit degree:\n");
	scanf("%f",&f);
	c=5*(f - 32)/9;
	printf("so we can know that the degree is %.2f degree Celsius \n",c);

	return 0;
}