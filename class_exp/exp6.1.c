#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void prime(int num,int status);
int main()
{
	int num,status;
	
	status = scanf("%d",&num);
	prime(num,status);
	return 0;
}
void prime(int num,int status)
{	
	int i,j;
	while(status ==1)
	{
		for(i=2;i<=sqrt(num);i++)
		{

		    j = num % i;
		    if (j == 0)
		    {
		    	printf("The number %d is not a prime number",num );
		    	exit(0);
		    }
		    else if(j != 0)
		    {
		    	if(i==floor(sqrt(num)))
		    	{
		    		printf("The number %d is a prime number",num );
		    		exit(0);
		    	}
		    }
		    else
		    {
		    	exit(0);
		    }
		
		}
	}
}

// 从网上得知找素数的算法如下：素数：除了1和它本身外没有别的因子。
// 也可以理解为：除了1和它本身，其他数来除它余数都不是0。
// 所以内层循环用从2开始到i的平方根（取整）依次求余，
// 因为到了平方根以后，再增加除数，得到的商是小于平方根的，等于以前取过的除数。
// 所以平方根以后不用再算了。
// floor函数可以返回不大于x的最大整数值
// 我使用循环来判断素数，当他不是输入数的平方根时，循环继续否则跳出
// 查书得知，可以通过scanf返回值status（为1则代表输入正确，否则则没有输入整数）来判断是否执行函数。
// 使用exit（0）正常运行程序并退出程序
