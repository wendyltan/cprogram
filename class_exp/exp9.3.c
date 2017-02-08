#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
	int i,j;
	FILE *A;
	FILE *B;
	FILE *C;
	char str1[100];
	char str2[100];
	scanf("%s",&str1);
	scanf("%s",&str2);	A = fopen("A","w+");
	fgets(str1,20,A);
	printf("the content of file A:%s\n",str1 );
	fclose(A);
	B = fopen("B","w+");
	fgets(str2,20,B);
	fclose(B);
	printf("the content of file B:%s\n",str2 );
	strcat(str1,str2);
	for(j = 0;j<strlen(str1)-1;j++)//选择排序
	{
		
		for (i = j; i < strlen(str1); i++)
		{
			if (str1[j]>str1[i])
			{
				char ch = str1[j];
				str1[j] = str1[i];
				str1[i] = ch;
			}
			
		}

	}
	C = fopen("C","w+");

	fprintf(C,"%s",str1);
	printf("the content of file C:%s\n",str1);
	fclose(C);


	return 0;
}