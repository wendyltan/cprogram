#include <stdio.h>
int main(int argc, char const *argv[])
{
	char c1,c2,c3,c4,c5;
	c1=getchar();
	if (c1 >= 'w')
	{
		c1 = c1-26;
	}
	c2=getchar();
	if (c2 >= 'w')
	{
		c2 = c2-26;
	}
	c3=getchar();
	if (c3 >= 'w')
	{
		c3 = c3-26;
	}
	c4=getchar();
	if (c4 >= 'w')
	{
		c4 = c4-26;
	}
	c5=getchar();
	if (c5 >= 'w')
	{
		c5 = c5-26;
	}
	printf("%c", c1+4);
	printf("%c", c2+4);
	printf("%c", c3+4);
	printf("%c", c4+4);
	printf("%c", c5+4);
	return 0;
}