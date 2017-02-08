#include <stdio.h>
int main()
{
   float s=0,t=1;
   int n,num;
   scanf("%d",&num);
   for (n=1;n<=num;n++)
   {   
       t=t*n;  
       s=s+t;   
   }
   printf("%f",s);
  return 0;
}