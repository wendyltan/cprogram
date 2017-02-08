#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//n stands for number that you type in
//a is an array
//this fuction use bubble sorting to sort number
void sorting(int *a,int n)
{
	int i; 
	int j; 
	int lock,tem; //just like a lock to control the sorting
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
				lock = 1; //open the lock
			}
		}
		if (lock ==0)
			break;

	}
}

void sorting(int *a,int n);
int main()
{
	int i;
	int n;
	int a[10];
	printf("please enter 10 numbers,(end with enter)\n");
    for(i = 0;i < 10;i++)
    {
     	scanf("%d",&a[i]);
    }
    sorting(a,10);
    printf("the array is :\n");
    for(i = 0; i < 10; i++)
    {
	     printf("%d ", a[i]);    
    }
	return 0;
}