#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char const *argv[])
{
	char array[3][15];
	char *a[3] = {array[0],array[1],array[2]},t[500];
	int i,j;
	for (i = 0; i < 3; i++)
    {
        gets(*(a+i));
    }
	for (i = 0; i < 2; i++)
	{
		for (j = i; j < 3; j++)
		{
			if (strcmp(*(a+i),*(a+j))>0)
			{
				strcpy(t,*(a+j));
				strcpy(*(a+j),*(a+i));
				strcpy(*(a+i),t);
			}
		}
	}
	printf("%s\n%s\n%s\n",*a,*(a+1),*(a+2));
	return 0;
}
