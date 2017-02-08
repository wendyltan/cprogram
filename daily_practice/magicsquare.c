#include <stdio.h>
int main(int argc, char const *argv[])
{
	int number;
	printf("enter the lines for array:\n");
	scanf("%d",&number);
	int magic[number][number];
	int row,col,rsum=0,csum=0;

	//enter data and display array:
	for(row=0;row<number;row++)
	{
		for(col=0;col<number;col++)
		{
			printf("enter data the %d row,%d col:\n",row+1,col+1);
			scanf("%d",&magic[row][col]);
		}
	}
	for(row=0;row<number;row++)
	{
		for(col=0;col<number;col++)
		{
			printf("%d ",magic[row][col]);
		}
		printf("\n");
	}

	/*caculate the sum and compare them*/
	printf("Let's caculate row sum first\n");
	for(col=0;col<number;col++)
	{
		for(row=0;row<number;row++)
		{
			
			rsum += magic[row][col];
		}
		printf("row sum is :%d\n",rsum );
		if(col<number-1)
			rsum = 0;
	}
	printf("Now lt's caculate the col sum\n");
	for(row=0;row<number;row++)
	{
		for(col=0;col<number;col++)
		{
			csum += magic[row][col];
		}
		printf("col sum is :%d\n",csum );
		if(row<number-1)
			csum = 0;
	}
	
	printf("What about the diagonals?\n");
	//caculate the diagonals sum to see if they match
    int dsum = 0;
	
	for(row=0;row<number;row++)
	{
		dsum += magic[row][row];
		if(row==number-1)
			printf("diaL sum is :%d\n",dsum );
	}
	dsum = 0;
	for(col=0;col<number;col++)
	{
		dsum += magic[col][col];
		if(col==number-1)
			printf("diaR sum is :%d\n",dsum );
	}

	if(rsum==csum&&csum==dsum)
		printf("This is a magic squre.\n");
	else
		printf("Sorry.this isn't a magic squre.\n");
	
	return 0;
}