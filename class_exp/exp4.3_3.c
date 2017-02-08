#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char const *argv[])
{
	int i,t = 1,eat,n;
	scanf("%d",&n);
	for(i=n;i>=1;i--)
	{
		if (i==n)
		{
			eat = 2*(t+1);
			t = eat;
		}
		else if(i!=n)
		{
			eat = 2*(t+1);
			t = eat;
		}		
	}
	printf("%d",(t/2)-1);
	return 0;
}
