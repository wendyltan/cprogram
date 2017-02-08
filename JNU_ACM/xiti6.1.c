#include <stdio.h>
int main(int argc, char const *argv[])
{
	int a,b,m,n,c;
	scanf("%d %d",&a,&b);
	m =a;
	n = b;
	while(b!=0)
	{
		c = a%b;
		a=b;
		b=c;
	}
	printf("%d %d",a ,(m*n)/a);

	return 0;
}//zhan zhuan xiangchu fa
//dang yushu buwei 0 shi tuichu,cishi a jiushi zuidagongyueshu
//chengji chuyi uidagongyueshu jiushi zuixiao gongbeishu