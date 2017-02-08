#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
	char chars[100];
	int i;
	printf("enter string:\n");
	gets(chars);
	for ( i = 0; i < strlen(chars); i++)
	{
		if (*(chars+i)==' ')
		{
			*(chars+i) = '_';
		}
		else continue;
	}
	printf("%s\n",chars);
	return 0;
}