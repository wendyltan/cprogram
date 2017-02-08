#include <stdio.h>
#include <stdlib.h>
#define SWAP(m,n,t) {(t=m);(m=n);(n=t);}
int main(int argc, char const *argv[])
{
	int m,n,t=0;
	scanf("%d %d",&m,&n);
    SWAP(m,n,t);
	printf("%d %d",m,n);
	
	return 0;
}
// 初步了解定义宏，在main函数之前对他进行预处理
// 总体没什么大问题
