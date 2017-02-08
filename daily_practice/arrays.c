#include <stdio.h>
#define CLASS 5
int main()
{
	int money_each[CLASS];
	int i;
	int total_money = 0;
	int money_most;


	printf("please enter each %d people's money\n",CLASS );
	for(i=0;i<5;i++)
	{
		scanf("%d",&money_each[i]);
		total_money += money_each[i];
	}
	printf("so we totally have %d money\n",total_money );
	printf("now let's caculate which money is the most.\n");
	
	money_most = money_each[0];

	for(i=0;i<5;i++)
	{
		if(money_most<money_each[i])
		{
			money_most = money_each[i];	
		}
	}
	printf("the most money is %d\n",money_most);
	return 0;

}
