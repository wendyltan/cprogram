#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
	int **p;
	int row,col,i,j;
	puts("please enter the row of array:");
	scanf("%d",&row);
	puts("please enter the col of array:");
	scanf("%d",&col);
	p = (int**)malloc(row * sizeof(int*));
	for ( i = 0; i < row; i++)
	{
		*(p+i)=(int*)malloc(col * sizeof(int));
		for ( j = 0; j < col; j++)
		{
			
			scanf("%d",&p[i][j]);
		}
		
	}
	printf("the datas are:\n" );
	for ( i = 0; i < row; i++)
	{
		for ( j = 0; j < col; j++)
		{
			printf("%d ",p[i][j]);
		}
		printf("\n");
		
	}
	for ( i = 0; i < col; i++)
	{
		free(*p);	
	}
	free(p);
	return 0;
}