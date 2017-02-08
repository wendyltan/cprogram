#include <stdio.h>
int main(int argc, char const *argv[])
{
	float litres[] = { 11.5,11.21,12.7,12.6,12.4};
	float miles[] = { 471.5,358.72,495.3,453.6,421.6};
	int mpl[5];
	int i;
	for ( i = 0; i < 5; i++)
	{
		*(mpl+i) = *(miles+i)/ *(litres+i);
	}
	for ( i = 0; i < 5; i++)
	{
		printf("%d ", *(mpl+i) );
	}
}