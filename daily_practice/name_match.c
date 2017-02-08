#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char *name[6] = {"Wang","Amy","Seven","Wendy","Yanbo","Hengxi"};
    int i;
    char user[10];
    printf("please enter the user's name:\n");
    gets(user); //using gets and scanf is different here.


    for(i=0;i<6;i++)
    {
    	if(strcmp(user,name[i])==0)
    	{
    		printf("Welcome!%s!\n",user );    //why do i have to use ctrl-c to interrupt it?
    		exit(0);
    	}
    	else
    		continue;
    }
    printf("error!have no rights to enter.\n");
	return 0;
}