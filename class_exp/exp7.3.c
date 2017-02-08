#include <stdio.h>
#include <stdlib.h>
void transpositon (int a[3][3]);
int main(int argc, char const *argv[])
{
	int i,j;
	int a[3][3];
	for (i = 0; i < 3; i++)
	{
		for (j= 0; j < 3; j++)
		{
			scanf("%d",(*(a+i)+j));
		}
	}
	transpositon (a);
	return 0;
}

void transpositon (int a[3][3])
{
	int i,j;
	int b[3][3];
	for (i = 0; i < 3; i++)
	{
		for (j= 0; j < 3; j++)
		{
			*(*(b+j)+i) = *(*(a+i)+j);
			*(*(b+i)+j) = *(*(a+j)+i);
		}
	}
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j< 3; j++)
		{
			
			if (j == 2)
			{
				printf("%d\n",*(*(b+i)+j));
				break;
			}
			printf("%d ",*(*(b+i)+j));
		}
	}
}
