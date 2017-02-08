#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	char *name[] = {"paul","john","david","tom","wang"};
	char user[8];
	int i;
	printf("please typein the user's name:\n");
	scanf("%s",&name);
	for(i=0;i<5;i++)
	{
		if (!strcmp(user ,name[i]))
			printf("hello there!\n");
		else
			printf("sorry,goodbye.\n");
	}
	
	
	return 0;
}