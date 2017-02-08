#include <stdio.h>
int main()
{
	int i,j,max;
	int a[10];
	int *p;
	p = a;
	for (i= 0; i < 10; i++)
	{
		scanf("%d",p+i);
	}
	for (i = 0; i < 9; i++)
	{
		for ( j= i+1; j<10; j++)
		{
			if (*(p+i)>*(p+j))
			{
				max = *(p+i);
			}
			else
			{
				max = *(p+j);
			}
		}
	}
	printf("the max is %d\n",max);
	return 0;
}