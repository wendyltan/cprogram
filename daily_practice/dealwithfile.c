#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
	
	char name[10],job[10];
	FILE * fp,*fp2;
	puts("please enter your name:");
	gets(name);
	printf("enter your job:\n");
	gets(job);
	fp = fopen("test.txt","w+");
	fputs(name,fp);
	fputs("\n",fp);
	fputs(job,fp);
	fclose(fp);
	fp = fopen("text.txt","r+");
	fp2 = fopen("copy.txt","w+");
	fgets(name,10,fp);
	fgets(job,10,fp);
	fputs(name,fp2);
	fputs("\n",fp2);
	fputs(job,fp2);
	
	fclose(fp);
	fclose(fp2);
	puts("program run success!");

	char *p = "you are A fool!";
	int i = 0;
	while(p[i]!= '\0')
	{
		printf("%c",p[i]);
		i++;
	}

	return 0;
}