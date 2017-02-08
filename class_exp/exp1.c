#include <stdio.h>
int main()
{
	int a,b,c,max;
	scanf("%d %d %d",&a,&b,&c); ;
	if (a > b)
	{	max = a;
		if (a > c)
			max = a;
		else
			max = c;
	}
	else
	{
		max =b;
		if (b > c)
			max = b;
		else
			max = c;
	}
	printf("%d",max);
	return 0;
}
