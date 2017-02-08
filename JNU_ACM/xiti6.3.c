#include <stdio.h>
#include <math.h>
int main(int argc, char const *argv[])
{
	int a=2, n; 
	double sum =0, creat = 0;
	int i;
	scanf("%d", &n);
	for ( i = 0; i < n; i++)
	{
		creat = creat + a * pow(10, i);
		sum += creat;
	}
	printf("%.0f", sum);
	return 0;
}