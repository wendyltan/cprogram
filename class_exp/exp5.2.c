# include <stdio.h>
# include <stdlib.h>
int binarysearch(int j,int array[]);
int main(int argc, char const *argv[])
{
	int array[15];
	int i,j,p;
	for (i=0; i < 15; i++)
	{
		scanf("%d",&array[i]);
	}
	scanf("%d",&j);
	p=binarysearch(j,array);
	if(p==-1)
	    printf("the number is not in the list\n");
	else
		printf("%d",p);
	return 0;
}
int binarysearch(int j,int array[])
{
    int low=0,high=14,mid;
    while(low<=high)
    {
        int mid= (low + high)/2;  //this is the middle of low and high
        int midVal = array[mid];  //the middle's number
        if(midVal<j)          //if it less than j:
            low = mid + 1;       //low count from the right one of the middle
        else if(midVal>j)     //else:
            high = mid - 1;      //high count from the left one of the middle
    	else				  //else:
    		return mid;			  //mid is the one.
    }
	return -1;
}
实验二：
1.一开始没有看明白题目，以为题目要求打印出数字所在位置，其实是在数组中的索引。把p+1改为p后没有问题
2.一开始不了解折半查找的算法导致没有进展，与同学讨论后明白其原理，并且注意对初始小和大赋值
3.发现，在自定义函数的末尾，返回值可以是任意的。于是我便借用这个特点作为返回后条件的判断