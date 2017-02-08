#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void student_average(int **array);
void subject_average(int **array);
void highest(int **array);
int main(int argc, char const *argv[])
{

	int **array;   
	int i,j;
	int ele_row =10,ele_col=5,nee_byte;  
	nee_byte = ele_row * sizeof(int*); 
	array = (int**)malloc(nee_byte);   
	if (array==NULL)
	{
		printf("Cannot allocate memory\n");
		return EXIT_FAILURE;
	}
	for(i=0;i<ele_row;i++)
	{
		array[i] = (int*)malloc(ele_col * sizeof(int));
		if (array[i]==NULL)
		{
			printf("Cannot allocate memory\n");
			return EXIT_FAILURE;
		} 
	}
	for(i=0;i<ele_row;i++)
	{
		for(j=0;j<ele_col;j++)
		{
			scanf("%d",&array[i][j]);
		}
	}
	

    student_average(array);

	subject_average(array);

	highest(array);
	for(i=0;i<ele_row;i++)
	{
		free(array[i]);
	}
	free(array);
	return 0;
}
void student_average(int **array)
{
	int i,j;
	double sum=0,average,a[10];
	printf("Part 1: the averages of every student\n");
	for(i=0;i<10;i++)
	{
		for(j=0;j<5;j++)
		{
			sum += array[i][j];
		}
		average = sum/5;
		printf("%lf\n",average );
		sum = 0;
	}

}
void subject_average(int **array)
{
	int i,j;
	double sum=0,average;
	printf("Part 2: the averages of every course score\n");
	for(i=0;i<5;i++)
	{
		for(j=0;j<10;j++)
		{
			sum += array[j][i];
		}
		average = sum/10;
		printf("%lf\n",average );
		sum = 0;
	}
}
void highest(int **array)
{
	int i,j, b=0;
	double sum=0,average[10];
	for(i=0;i<10;i++)
	{
		for(j=0;j<5;j++)
		{
			sum += array[i][j];
		}
		average[i]= sum/5;
		sum = 0;
	}
	for(i=0;i<10;i++)
	{
		if(average[i]<average[i+1]) b=i+1;
	//or:
		//int a[0];
		//j = a[0]
		//if(a[i]>j)
		//{
			//j=a[i];
			//b=i;
		//}
		//to find the largest
	}
	printf("Part 3: a student  and  course scores of the student whose average is the highest\n");
	printf("%d\n",b+1);
	for(i=0;i<5;i++)
	{
        printf("%d", array[b][i]);
        if(i<=3)
        	printf(" ");
        if(i==4)
        	printf("\n");

	}
}
// 定义了三个函数来完成这个功能。
// 使用malloc函数目的是给我所创建的二维数组动态分配内存空间。首先给二维数组分配，再给每一行都分配内存空间
// 使用双层循环来输入数据
// 求平均分时，要注意sum和average都要是double才行，否则结果精度将不正确
// 在计算每一科的平均分的时候，我注意到sum经过每次循环之后必须重置为0，否则没经过一次循环sum就越来越大造成结果出错
// 最后一个函数，给每个学生的平均分放置到一维数组里，比较出大小之后再打印下标和值
// 为了养成好习惯，要将内存释放运用(free)


