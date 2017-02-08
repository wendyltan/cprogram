#include <stdio.h>
void compare(float n1,float n2);
int main(int argc, char const *argv[])
{
	float n1,n2;
	printf("please enter two number:\n");
	scanf("%f %f",&n1,&n2);
	compare(n1,n2);

	return 0;
}

void compare(float n1,float n2)
{
	
	if(n1>n2)
		printf("number1 is larger than number 2\n");
	else if (n1==n2)
		printf("number1 equal to number 2\n");
	else 
		printf("number1 is less than number 2\n");
}