#include <stdio.h>
int main(int argc, char const *argv[])
{
    int space=0,alpha=0,number=0,other=0;
    char ch;
     
    while ((ch=getchar())!='\n')
    {
        if (ch >='a'&&ch<='z'||ch>='A'&&ch<='Z')
        {
            alpha++;
            continue;
        }
        else if(ch ==' ')
        {
            space++;
            continue;
        }
        else if(ch>='0'&&ch<='9')
        {
            number++;
            continue;
        }
        else
        {
            other++;
            continue;
        }
    }
    printf("%d %d %d %d",alpha,number,space,other);
 
    return 0;
}