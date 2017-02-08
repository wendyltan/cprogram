#include <stdio.h>
#define SIZE 10
int main(int argc, char const *argv[])
{
	int array[SIZE];
	// {14,22,67,31,89,11,42,35,65,49}
	int sorted_array[SIZE],min_array[SIZE];
	/*char *description[11]={"start","first pass","second pass","third pass",
	"fourth pass","fifth pass","sixth pass","seventh pass","eighth pass","nine pass","ten pass"};*/
	int i,j,p,k;
	for (i = 0; i < SIZE; i++)
	{
		scanf("%d",&array[i]);
	}
	for (i=0;i<SIZE+1;i++)
	{
		/*printf("Unsorted at the %s:\n",description[i]);*/
		if (i==0)
		{
			for (j = 0; j < SIZE; j++)
			{
				printf("%d ",array[j]);
			}
			printf("\n");
		}
		else
		{
			for (j = 0; j < SIZE; j++)
			{
				if (j==p)
				{
					printf("%d ",sorted_array[p]);
					p = 0;
					continue;
				}
				else{
					sorted_array[j]=array[j];
				}
				printf("%d ",sorted_array[j]);
			}
			printf("\n");
		}
		if (i==0)
		{
			/*printf("Sorted at the start:\n");*/
			printf("\n");
		}
		else
		{
			/*printf("Sorted after the %s\n",description[i]);*/
			for (k = 0; k < i; k++)
			{
				printf("%d\t",min_array[k]);
			}
			printf("\n");
			
		}
		int min=array[0];	
		for (k = 0; k <SIZE; k++)
		{
			for(j = k;j<SIZE-1;j++)
			{
				if (min<array[k+1])
				{
					continue;
				}
				else
				{
					min = array[k+1];
					p =k+1;
				}
			}
				
		}
		
		sorted_array[p] = 9999;
		array[p] = 9999;
		min_array[i] = min;

			
		
	}
	return 0;
}