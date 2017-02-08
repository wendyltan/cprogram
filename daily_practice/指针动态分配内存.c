#include <stdio.h>
#include <stdlib.h>
int main()
{
	int *p,i;     //define pointer and loop's variable
	int num,byte;     //prepare to use malloc()to caculate the needed memory
	printf("enter the number of elements:\n");
	scanf("%d",&num);

	byte = num * sizeof(int);    
	p = (int*)malloc(byte);  //give the memory to array p 
	//or (int*)calloc(num,byte)
	

	/*just to tell if allocating the memory works smoothly*/
	if (p==NULL)
	{
		printf("Cannot allocate memory\n");
		return EXIT_FAILURE;
	}


	for(i=0;i<num;i++)    //loops for your array elements
	{	
		printf("enter element %d:\n",i );
		scanf("%d",&p[i]);
	}


	for(i=0;i<num;i++)
	{
		printf("element %d is %d\n",i,p[i] );
	}


	free(p);
   return 0;
}



//go make your another pointer practice!