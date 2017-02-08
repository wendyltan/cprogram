#include <stdio.h>
#define I 5
struct stu
{
	int num;
	char name1[10];
	char name2[10];
	float score[3];
}students[5];
int main(int argc, char const *argv[])
{
	int i,j;
	float sum[3];
	float average[4];
	float average3;
	float sum_two[6],average_one[5];
	int b=0;
	for ( i = 0; i < I; i++)
	{
		scanf("%d",&students[i].num);
		scanf("%s %s",&students[i].name1,&students[i].name2);
		for (j = 0; j < 3; j++)
		{
			scanf("%f",&students[i].score[j]);
		}
	}
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < I; j++)
		{
			sum[i] += students[j].score[i];
		}
		average[i] = sum[i]/5.0;
	}
   

	for (i = 0; i < I; i++)
	{
		for ( j = 0; j < 3; j++)
		{
			sum_two[i] += students[i].score[j];
		}
		average_one[i] = sum_two[i]/3.0;
	}
	j=0;
	for ( i = 0; i < I; i++)
	{
		if (average_one[i]>j)
		{
			j = average_one[i];
			b = i;
		}
	}
	average3 = (average[0]+average[1]+average[2])/3.0;
	printf("%.2f\n",average3);
	printf("%d\n",students[b].num);
	printf("%s %s\n",students[b].name1,students[b].name2);
	printf("%.2f\n%.2f\n%.2f\n%.2f\n",students[b].score[0],students[b].score[1],
		students[b].score[2],average_one[b]);
	return 0;
}

