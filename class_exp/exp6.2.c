#include <stdio.h>
#include <string.h>
int letters_counting(char string[]);
int digits_counting(char string[]);
int space_counting(char string[]);
int other_counting(char string[]);
int main()
{
	int letters=0,digits=0,space=0,other=0;
	char string[100];
	gets(string);
	letters = letters_counting(string);
	digits = digits_counting(string);
	space = space_counting(string);
	other = other_counting(string);
	printf("%d %d %d %d",letters,digits,space,other);

	return 0;
}

int letters_counting(char string[])
{
	int letters=0;
	char ch;
	int i;
	for(i = 0;i<strlen(string);i++)
	{
		while ((ch = string[i])!=EOF)
		{
			if (ch >='a'&&ch<='z'||ch>='A'&&ch<='Z')
			{
				letters++;
				break;	
			}
			else
				break;
		}

	}
	return letters;
}

int digits_counting(char string[])
{
	int digits=0;
	char ch;
	int i;
	for(i = 0;i<strlen(string);i++)
	{
		while ((ch= string[i])!=EOF)
		{
			if(ch>='0'&&ch<='9')
			{
				digits++;
				break;	
			}
			else
				break;
		}

	}
	return digits;
}

int space_counting(char string[])
{
	int space=0;
	char ch;
	int i;
	for(i = 0;i<strlen(string);i++)
	{
		while ((ch=string[i])!=EOF)
		{
			if(ch ==' ')
			{
				space++;
				break;
				
			}
			else
				break;
		}
	}
	return space; 	
}

int other_counting(char string[])
{
	int other=0;
	char ch;
	int i;
	for(i = 0;i<strlen(string);i++)
	{
		while ((ch= string[i])!=EOF)
		{
			if (ch >='a'&&ch<='z'||ch>='A'&&ch<='Z')
			{
				break;
			}
			else if(ch ==' ')
			{
				break;
			}
			else if(ch>='0'&&ch<='9')
			{
				break;
			}
			else
			{
				other++;
				break;	
			}
		}
	}
	return other; 
}

// 学会使用string头文件中的strlen函数，对测量字符串长度很有帮助
// 定义字符串为一个数组，通过循环使ch移动位置，判断每一位是字母还是空格还是别的然后马上跳出
// 循环，我设置了四个相似的函数分别对这几样东西进行计数
// 判断ch位置不再移动的条件是当检测到分非为EOF时




