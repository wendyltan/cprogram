#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void sorting(int *a,int n);
int main()
{
	int i;
	int n;
	int a[10];
    for(i = 0;i < 10;i++)
    {
     	scanf("%d",&a[i]);
    }
    sorting(a,10);
    for(i = 0; i < 10; i++)
    {
	     printf("%d ", a[i]);    
    }
    printf("\n");
	return 0;
}
void sorting(int *a,int n)
{
	int i; 
	int j; 
	int lock,tem; 
	for(i = 0;i<n-1;i++)
	{
		lock = 0;
		for(j = n-1;j>i;j--)
		{
			if(a[j]<a[j-1])
			{
				tem = a[j];
				a[j] = a[j-1];
				a[j-1] = tem;
				lock = 1; 
			}
		}
		if (lock ==0)
			break;
	}
}
实验报告：
	实验一：
	1.一开始定义数组时，使用a[]这样的形式，出现错误“请声明数组大小”经查书得知，初始化数组要声明元素个数
	改为a[10]即可；
	2.定义排序的函数时，定义为int sorting时出错，应该定义为void，因为所设定函数并没有返回值故声明为void型
	3.比较数组元素大小并交换时，不能直接交换；一开始我使用的是a[j-1]=a[j],a[j]=a[j-1],这样会出现错误，原因
	在于我没有赋予一个中间变量给他们进行间接交换从而使得交换失去了意义；
	