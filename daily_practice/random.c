#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
	int dice;
	int i;
	for (i = 0; i <5; i++)
	{
		dice = (rand()%6)+1 ;
		printf("%d",dice);
	}
	return 0;
}