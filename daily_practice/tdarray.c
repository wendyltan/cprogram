#include <stdio.h>
#define MAGICR 5
#define MAGICC 5
int main()
{
	int magic[MAGICR][MAGICC] = {{17,24,1,8,15},
								{23,5,7,14,16},
								{4,6,13,20,22},
								{10,12,19,21,3},
								{11,18,25,2,9}};
	
	
	int i,j;

	//print out the table
	for ( i = 0; i < 5; i++)
	{
		for ( j = 0; j < 5; j++)
		{
			if (j!=4)
			{
				printf("%d\t", magic[i][j]);
			}
			else
				printf("%d\n", magic[i][j]);
		}
	}
	
	int row,col,rsum=0,csum=0;
	/*caculate the sum and compare them*/
	printf("let's caculate row sum first\n");
	


	for(col=0;col<MAGICC;col++)
	{
		for(row=0;row<MAGICR;row++)
		{
			
			rsum += magic[row][col];
		}
		printf("row sum is :%d\n",rsum );
		if(col<MAGICC)
			rsum = 0;
	}
	printf("now lt's caculate the col sum\n");
	

	for(row=0;row<MAGICR;row++)
	{
		for(col=0;col<MAGICC;col++)
		{
			csum += magic[row][col];
		}
		printf("col sum is :%d\n",csum );
		if(row<MAGICR)
			csum = 0;
	}
	
	printf("what about the diagonals?\n");
    
	//caculate the dia sum to see if they match
    int dsum = 0;
	
	for(row=0;row<MAGICR;row++)
	{
		dsum += magic[row][row];
		if(row==MAGICR-1)
			printf("dia sum is :%d\n",dsum );
	}
	dsum = 0;
	for(col=0;col<MAGICC;col++)
	{
		dsum += magic[col][col];
		if(col==MAGICC-1)
			printf("dia sum is :%d\n",dsum );
	}



	if(rsum==csum&&csum==dsum)
		printf("this is a magic squre.\n");
	else
		printf("sorry.this isn't a magic squre.\n");
	
	return 0;
}