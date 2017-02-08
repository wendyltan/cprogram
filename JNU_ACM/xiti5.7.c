#include <stdio.h>
#include<string.h>
int main(int argc, char const *argv[])
{
	// char num[6];
	// gets(num);
	// printf("%d\n", strlen(num));
	// int i;
	// for(i=0;num[i]!='\0';i++)
	// {
	// 	printf("%c", num[i]);
	// 	if(num[i+1]!='\0') printf(" ");
	// }
	// puts("");
	// for(i=strlen(num)-1;i>=0;i--) printf("%c", num[i]);
	int i ;
	int k = 0;
	int counter = 0;
	char number[6];
	char temp;
	// while (( number[k] = getchar()) != '\n')
	// {
	// 	k++;
	// 	counter++;
	// }???why doesn't work?
	gets(number);
	counter = strlen(number);
	printf("%d\n", counter );
	for ( i = 0; i < counter; i++)
	{
		if (i == counter-1)
		{
			printf("%c", number[i] );
			break;
		}
		printf("%c ", number[i]);
	}
	printf("\n");
	for ( i = counter-1; i>=0; i--)
		printf("%c",number[i]);
	return 0;
}