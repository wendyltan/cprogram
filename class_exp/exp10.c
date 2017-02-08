#include <stdio.h>
#include <stdlib.h>
#define STUDENT 10
#define GRADE 5
struct information
{
	int number;
	char name[16];
	char sex[5];
	int score[GRADE];
	int average;
} students[STUDENT];
void stu_average(struct information *p);
void grade_average(struct information *p, int k[]);
int main(int argc, char const *argv[])
{
	int i, j;
	int grade_a[11];
	struct information *p;
	FILE *file, *new_file;
	FILE *insert_file;
	struct information another_data[11];
	struct information tempor;
	int temp = 0;
	p = students;
	//read in information
	printf("Please enter 10 students'information(number,name,sex and 5 grades)\n");
	for ( i = 0; i < STUDENT; i++)
	{
		scanf("%d", &students[i].number);
		getchar();
		gets(students[i].name);
		gets(students[i].sex);
		for ( j = 0; j < GRADE; j++)
		{
			scanf("%d", &students[i].score[j]);
		}

	}
	printf("Enter success!\n");

	//use this to caculate the students'average
	stu_average(p);
	printf("\n");
	//use this to caculate the subject's average
	grade_average(p, grade_a);
	//use file method to put them in file"stu.c"

	file = fopen("stu.c", "w");
	for ( i = 0; i < STUDENT; i++)
	{
		fprintf(file, "Number:%d\n", students[i].number);
		fputs(students[i].name, file);
		fputs("\n", file);
		fprintf(file, "%s", students[i].sex );
		fputs("\n", file);
		for (j = 0; j < GRADE; j++)
		{
			fprintf(file, "%d ", students[i].score[j]);

		}
		fprintf(file, "\n%d\n", students[i].average);
	}
	for ( i = 0; i < GRADE; i++)
	{
		fprintf(file, "Subject %d average:%d\n",i+1, grade_a[i]);
	}
	fclose(file);

	//get data,sort them and put them in stu-sort
	if ((new_file = fopen("stu-sort", "w+")) == NULL)
	{
		printf("Can't open file!\n");
		exit(1);
	}
	struct information new_data[10];
	for ( i = 0; i < STUDENT - 1; i++)
	{
		for ( j = i + 1; j < STUDENT; j++)
		{
			if (students[i].average < students[j].average)
			{
				new_data[j] = students[j];
				students[j] = students[i];
				students[i] = new_data[j];
			}
		}
	}
	for ( i = 0; i < STUDENT; i++)
	{
		fprintf(new_file, "Number:%d\n", students[i].number);
		fputs(students[i].name, new_file);
		fputs("\n", new_file);
		fprintf(new_file, "Sex:%s", students[i].sex);
		fputs("\n", new_file);
		for (j = 0; j < GRADE; j++)
		{
			fprintf(new_file, "%d ", students[i].score[j]);

		}
		fprintf(new_file, "\n%d\n", students[i].average);
	}
	fclose(new_file);
	//insert new students'information:
	printf("Please enter another students' information:\n");

	if ((insert_file = fopen("stu-new-file", "w")) == NULL)
	{
		printf("Can't open file!\n");
		exit(1);
	}

	for (i = 0; i < 11; i++)
	{
		another_data[i] = students[i];
		if (i == 10)
		{
			scanf("%d", &another_data[i].number);
			getchar();
			gets(another_data[i].name);
			gets(another_data[i].sex);
			for ( j = 0; j < GRADE; j++)
			{
				scanf("%d", &another_data[i].score[j]);
				temp += another_data[i].score[j];
			}
			another_data[i].average = temp / 5;
		}
	}

	//sort it :
	for ( i = 0; i < 10; i++)
	{
		for ( j = i + 1; j < 11; j++)
		{
			if (another_data[i].average < another_data[j].average)
			{
				tempor = another_data[j];
				another_data[j] = another_data[i];
				another_data[i] = tempor;
			}
		}
	}
	for ( i = 0; i < 11; i++)
	{
		fprintf(insert_file, "Number:%d\n", another_data[i].number);
		fputs(another_data[i].name, insert_file);
		fputs("\n", insert_file);
		fprintf(insert_file, "Sex:%s", another_data[i].sex);
		fputs("\n", insert_file);
		for (j = 0; j < GRADE; j++)
		{
			fprintf(insert_file, "%d ", another_data[i].score[j]);

		}
		fprintf(insert_file, "\n%d\n", another_data[i].average);
	}
	fclose(insert_file);
	printf("Enter success!\n\n");

	//print out those grade which are under 60 or higher than 90:

	for (i = 0; i < 11; i++)
	{

		if (another_data[i].average < 60)
		{
			printf("The one less than 60:\n");
			printf("Number:%d\nName:%s\nSex:%s\n", another_data[i].number, another_data[i].name, another_data[i].sex);
			for ( j = 0; j < GRADE; j++)
			{
				printf("%d ", another_data[i].score[j]);
			}
			printf("\n");
			printf("Average:%d\n", another_data[i].average);
			continue;
		}
		if (another_data[i].average >=90)
		{
			printf("The one higher than 90:\n");
			printf("Number:%d\nName:%s\nSex:%s\n", another_data[i].number, another_data[i].name, another_data[i].sex);
			for ( j = 0; j < GRADE; j++)
			{
				printf("%d ", another_data[i].score[j]);
			}
			printf("\n");
			printf("Average:%d\n", another_data[i].average);
			continue;
		}
	}
	printf("Program run successfully!exit now...\n");

	return 0;
}

void stu_average(struct information *p)
{
	int i, j;
	int sum = 0;
	for (i = 0; i < STUDENT; i++)
	{
		for (j = 0; j < GRADE; j++)
		{
			sum += p[i].score[j];
		}
		p[i].average = sum / 5;
		sum = 0;
	}

}

void grade_average(struct information *p, int k[])
{
	int i, j;
	int sum = 0;
	for (i = 0; i < GRADE; i++)
	{
		for ( j = 0; j < STUDENT; j++)
		{
			sum += p[j].score[i];
		}
		k[i] = sum / 10;
		sum = 0;
	}
	for ( i = 0; i < GRADE; i++)
	{
		printf("Average%d:%d\n", i + 1, k[i]);
	}
}