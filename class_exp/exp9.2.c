#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(int argc, char const *argv[])
{
	char string[100];
	char ch;
	int i = 0;
	int counter = 0;
	FILE *fp;
	while((ch = getchar())!= '!')
	{
		string[i] = ch;
		if (islower(string[i]) != 0)
		{
			string[i] = toupper(string[i]);
		}
		i++;
		counter++;
	}
	i = 0;
	while(i<counter)
	{
		printf("%c",string[i]);
		i++;
	}
	fp = fopen("test","w+");
	i = 0;
	while(i<counter)
	{
		fprintf(fp,"%c",string[i]);
		i++;
	}
	fclose(fp);
	return 0;
}