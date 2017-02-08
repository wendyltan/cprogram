#include <stdio.h>
int main(int argc, char const *argv[])
{
	long int  i;
	char n;
	scanf("%ld", &i);
	int price;
	if (i <= 100000)
	{
		n = 'A';
		price =  0.1 * i;
	}
	else if (i > 100000 && i <= 200000)
	{
		n = 'B';
		price = 0.1 * 100000 + 0.075 * (i - 100000);
	}
	else if (i > 200000 && i <= 400000)
	{
		n = 'C';
		price = 0.1 * 200000 + 0.05 * (i - 200000);
	}
	else if (i > 400000 && i <= 600000)
	{
		n = 'D';
		price = 0.1 * 400000 + 0.03 * (i - 400000);
	}
	else if (i > 600000 && i <= 1000000)
	{
		n = 'E';
		price = 0.1 * 600000 + 0.015 * (i - 600000);
	}
	else if (i > 1000000)
	{
		n = 'F';
		price =  0.1 * 1000000 + 0.001 * (i - 1000000);
	}
	switch (n)
	{
	case 'A': printf("%ld",price ); break;
	case 'B': printf("%ld",price ); break;
	case 'C': printf("%ld",price ); break;
	case 'D': printf("%ld",price ); break;
	case 'E': printf("%ld",price ); break;
	case 'F': printf("%ld",price ); break;
	}

	return 0;
}