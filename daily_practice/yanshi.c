#include "stdio.h"
#include "stdlib.h"
int main(int argc, char const *argv[])
{
	//sorting method:
	int s[10];
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10 - j - 1; j++)
		{
			if (s[j] < s[j + 1])
			{
				swap(&s[j], &s[j + 1]);//i haven't define function "swap" yet..
			}
		}

	}//mao pao pai xu
	for (int i = 0; i < 10; i++)
	{
		min = i;
		for (int j = i + 1; j < 10; j++)
		{
			if (s[j] < s[min])
			{
				min = j;//put the smaller ahead
			}
		}
		temp = s[min];
		s[min] = s[i];
		s[i] = temp;
	}//xuan ze pai xu

	//here is a kind of method i made to sort but have no specific meaning:
	for ( i = 0; i < num-1; i++)
	{
		for ( j = i + 1; j < num; j++)
		{
			if (/* condition */)
			{
				//switch sth;
			}
		}
	}//self-made sorting
	

	


	//pointer & array:
	char a[10][20];
	char *p[10] = {a[0], a[1], a[2]...}; //define an array holding 10 pointer ,each of them point to an oned array


	int (*p)[10];//dinfine a pointer pointing to twod arrays which hold oned array that hold 10 int
	a[10][20];
	p = &a[0];
	//or:
	int *pp = {"hello!", "how are u?", "i'm fine,thank you."};

	

	return 0;
}