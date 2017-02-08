#include <stdio.h>
int main(int argc, char const *argv[])
{
	int a,b,c;
	scanf("%d %d",&a,&b);
	if (a>=0&&b<=10)
	{
		c = a+b;
	}
	printf("%d",c );
	return 0;
}