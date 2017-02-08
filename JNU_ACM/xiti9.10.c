#include<stdio.h>
#include <string.h>
  
int main(int argc, char const *argv[])
{
    char a[100];
    gets(a);
    int i = strlen(a);
    int k;
    for ( k = 0; k < i; k++)
    {
        if(a[k]=='Z'||a[k]=='z') 
        {
            a[k] -=25;
            continue;
        }
        else if(a[k]>='a'&&a[k]<'z'||a[k]>='A'&&a[k]<'Z')
            a[k] = a[k]+1;
        else
            continue;
  
          
    }
    for ( k = 0; k < i; k++)
    {
        putchar(a[k]);
    }
    printf("\n");
 
    return 0;
}