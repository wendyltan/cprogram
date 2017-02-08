#include <stdio.h>
#include <stdlib.h>
void average_course1 (int **a);
void count_grade (int **a);
void score_greater (int **a);
int **a;
int main(int argc, char const *argv[])
{
	int i,j;
	int ele_row =4,ele_col=5,nee_byte;  
	nee_byte = ele_row * sizeof(int*); 
	a = (int**)malloc(nee_byte);   
	if (a==NULL)
	{
		printf("Cannot allocate memory\n");
		return EXIT_FAILURE;
	}
	for(i=0;i<ele_row;i++)
	{
		a[i] = (int*)malloc(ele_col * sizeof(int));
		if (a[i]==NULL)
		{
			printf("Cannot allocate memory\n");
			return EXIT_FAILURE;
		} 
	}
	for (i = 0; i < 4; i++)
	{
		for ( j = 0; j < 6; j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	average_course1 (a);
	printf("\n");
	count_grade (a);
	printf("\n");
	score_greater (a);
	for(i=0;i<ele_row;i++)
	{
		free(a[i]);
	}
	free(a);
	return 0;
}


void average_course1 (int **a)
{
	int i;
	float sum=0.0,average=0.0;
	for ( i = 0; i < 4; i++)
	{
		sum += a[i][0];
		average = sum/4;
	}
	printf("The average score of course 1 is:%.2f\n",average );
}


void count_grade (int **a)
{
	int i,j;
	int count = 0;
	float sum = 0.0,average = 0.0;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 5; j++)
		{
			sum += a[i][j];
			if (a[i][j]<60)
			{
				count +=1;
			}	

		}
		average = sum/5;
		if (count>=2)
		{
			printf("The student number is:  %d\n",i+1);
			printf("The student's every course score are:%.2f,%.2f,%.2f,%.2f,%.2f,\n",(float)a[i][0]
				,(float)a[i][1],(float)a[i][2],(float)a[i][3],(float)a[i][4]);
			printf("The student's average score is:%.2f\n",average );
		}
		sum = 0.0;
		average = 0.0;
		count = 0;
	}
}


void score_greater (int **a)
{
	int i,j;
	float sum1 = 0.0;
	int counter[100],average[100];
	int count;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 5; j++)
		{
			sum1 += a[i][j];
		}
		average[i] = sum1/5;
		sum1 = 0.0;
	}
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (a[i][j]>=85)
			{
				count += 1;
			}
		}
		counter[i] = count;
		count = 0;
	}
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (average[i]>=90 && counter[i]==5)
			{
				printf("student %d average score is above 90\n",i+1);
				printf("student %d every score is above 85\n",i+1);
				break;
			}
		}

	}
}