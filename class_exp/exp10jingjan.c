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
} a[STUDENT];
void stu_average(struct information *p);
void grade_average(struct information *p, int k[]);
int main(int argc, char const *argv[])
{
	int i, j;
	int grade_a[11];
	struct information *p;
	FILE *file, *file1;
	FILE *file2;
	struct information data1[10];
	struct information data2[11];
	struct information tempor;
	int temp = 0;
	p = a;
	//read in information
	printf("������ʮ��ѧ������Ϣ�����룬���֣��Ա���Ƴɼ���\n");
	for ( i = 0; i < STUDENT; i++)
	{
		scanf("%d", &a[i].number);
		getchar();
		gets(a[i].name);
		gets(a[i].sex);
		for ( j = 0; j < GRADE; j++)
		{
			scanf("%d", &a[i].score[j]);
		}

	}
	printf("����ɹ���\n");

	//use this to caculate the a'average
	stu_average(p);
	printf("\n");
	//use this to caculate the subject's average
	grade_average(p, grade_a);
	//use file method to put them in file"stu.c"

	file = fopen("stu.c", "w");
	for ( i = 0; i < STUDENT; i++)
	{
		fprintf(file, "���룺%d\n", a[i].number);
		fputs(a[i].name, file);
		fputs("\n", file);
		fprintf(file, "%s", a[i].sex );
		fputs("\n", file);
		for (j = 0; j < GRADE; j++)
		{
			fprintf(file, "%d ", a[i].score[j]);

		}
		fprintf(file, "\n%d\n", a[i].average);
	}
	for ( i = 0; i < GRADE; i++)
	{
		fprintf(file, "��Ŀ%dƽ���֣�%d\n",i+1, grade_a[i]);
	}
	fclose(file);

	//get data,sort them and put them in stu-sort
	if ((file1 = fopen("stu-sort", "w+")) == NULL)
	{
		printf("�޷����ļ���\n");
		exit(1);
	}
	for ( i = 0; i < STUDENT - 1; i++)
	{
		for ( j = i + 1; j < STUDENT; j++)
		{
			if (a[i].average < a[j].average)
			{
				data1[j] = a[j];
				a[j] = a[i];
				a[i] = data1[j];
			}
		}
	}
	for ( i = 0; i < STUDENT; i++)
	{
		fprintf(file1, "����:%d\n", a[i].number);
		fputs(a[i].name, file1);
		fputs("\n", file1);
		fprintf(file1, "�Ա�:%s", a[i].sex);
		fputs("\n", file1);
		for (j = 0; j < GRADE; j++)
		{
			fprintf(file1, "%d ", a[i].score[j]);

		}
		fprintf(file1, "\n%d\n", a[i].average);
	}
	fclose(file1);
	//insert new a'information:
	printf("���������µ�һλѧ������Ϣ��\n");

	if ((file2 = fopen("stu-new", "w")) == NULL)
	{
		printf("�޷����ļ���\n");
		exit(1);
	}

	for (i = 0; i < 11; i++)
	{
		data2[i] = a[i];
		if (i == 10)
		{
			scanf("%d", &data2[i].number);
			getchar();
			gets(data2[i].name);
			gets(data2[i].sex);
			for ( j = 0; j < GRADE; j++)
			{
				scanf("%d", &data2[i].score[j]);
				temp += data2[i].score[j];
			}
			data2[i].average = temp / 5;
		}
	}

	//sort it :
	for ( i = 0; i < 10; i++)
	{
		for ( j = i + 1; j < 11; j++)
		{
			if (data2[i].average < data2[j].average)
			{
				tempor = data2[j];
				data2[j] = data2[i];
				data2[i] = tempor;
			}
		}
	}
	for ( i = 0; i < 11; i++)
	{
		fprintf(file2, "����:%d\n", data2[i].number);
		fputs(data2[i].name, file2);
		fputs("\n", file2);
		fprintf(file2, "�Ա�:%s", data2[i].sex);
		fputs("\n", file2);
		for (j = 0; j < GRADE; j++)
		{
			fprintf(file2, "%d ", data2[i].score[j]);

		}
		fprintf(file2, "\n%d\n", data2[i].average);
	}
	fclose(file2);
	printf("������Ϣ�ɹ���\n\n");

	//print out those grade which are under 60 or higher than 90:

	for (i = 0; i < 11; i++)
	{

		if (data2[i].average < 60)
		{
			printf("����60�ֵ��ˣ�\n");
			printf("���룺%d\n���֣�%s\n�Ա�%s\n", data2[i].number, data2[i].name, data2[i].sex);
			for ( j = 0; j < GRADE; j++)
			{
				printf("%d ", data2[i].score[j]);
			}
			printf("\n");
			printf("ƽ���֣�%d\n", data2[i].average);
			continue;
		}
		if (data2[i].average >=90)
		{
			printf("����90�ֵ��ˣ�\n");
			printf("���룺%d\nn���֣�%s\n�Ա�%s\n", data2[i].number, data2[i].name, data2[i].sex);
			for ( j = 0; j < GRADE; j++)
			{
				printf("%d ", data2[i].score[j]);
			}
			printf("\n");
			printf("ƽ���֣�%d\n", data2[i].average);
			continue;
		}
	}
	printf("���������˳�����лʹ�ã�\n");

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
		printf("ƽ���� %d:%d\n", i + 1, k[i]);
	}
}