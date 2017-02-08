#include <stdio.h>
#include <stdlib.h>
int main()
{

	int **array;    //if the array is erwei 
	int i,j,ele_row,ele_col,nee_byte;   //need to define not only row but col

	//caculate the byte needed
	printf("please enter the row amounts:\n");
	scanf("%d",&ele_row);
	printf("please enter the col amounts:\n");
	scanf("%d",&ele_col);
	nee_byte = ele_row * sizeof(int*); //if yiwei,should be (int)
	array = (int**)malloc(nee_byte);   //if yiwei,should be (int*)

	//just to judge whether the memo allocation is successful
	if (array==NULL)
	{
		printf("Cannot allocate memory\n");
		return EXIT_FAILURE;
	}

	//caculate how much memo should be allocate on  one row(just like yiwei)
	for(i=0;i<ele_row;i++)
	{
		array[i] = (int*)malloc(ele_col * sizeof(int));
		if (array[i]==NULL)
	{
		printf("Cannot allocate memory\n");
		return EXIT_FAILURE;
	} 
	}



	//ask user enter elements
	for(i=0;i<ele_row;i++)
	{
		for(j=0;j<ele_col;j++)
		{
			printf("enter the number [%d,%d]\n",i,j );
			scanf("%d",&array[i][j]);
		}
	}

	//print out the array with \t
	printf("now let's print out the array.\n");
	for(i=0;i<ele_row;i++)
	{
		for(j=0;j<ele_col;j++)
		{
			if(j<ele_col-1)
				printf("%d\t",array[i][j]);
			else
				printf("%d\n",array[i][j]);
		}
	}
	
	//remember to free the memory,erwei should free the one row first then the whole array's memo
	for(i=0;i<ele_row;i++)
	{
		free(array[i]);
	}
	free(array);


	printf("nice work!\n");
	return 0;
}