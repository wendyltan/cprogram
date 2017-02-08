#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
	int a[3],t,i,j;
	scanf("%d %d %d",a,a+1,a+2);
	for (i = 0; i < 2; i++)
	{
		for (j = i; j < 3; j++)
		{
			if (*(a+i)>*(a+j+1))
			{
				t = *(a+j+1);
				*(a+j+1) = *(a+i);
				*(a+i) = t;
			}
		}
		

	}
	printf("%d\n%d\n%d",*a,*(a+1),*(a+2));
	return 0;
}