#include <stdio.h>
int main(int argc, char const *argv[])
{
    char a[5];
    scanf("%s",a);
    int i;
    for ( i = 0; i < 4; i++)
    {
        if (i==3)
        {
            printf("%c",a[i] );
        }
        else
            printf("%c ",a[i] );
    }
 
    return 0;
}