#include <stdio.h>
#include <string.h>
 
int main(int argc, char const *argv[])
{
    char a[3][100], temp[3][100];
    int i, j,min;
    for ( i = 0; i < 3; i++)
    {
        gets(a[i]);
    }
    for ( i = 0; i < 3; i++)
    {
        min = i;
        for ( j = i + 1; j < 3; j++)
        {
            if (strcmp(a[j],a[min])<0)
            {
                min = j;
            }
 
        }
        strcpy(temp[i] , a[min]);
        strcpy(a[min] , a[i]);
        strcpy(a[i] , temp[i]);
    }
    for ( i = 0; i < 3;i++)
    {
        printf("%s\n",a[i] );
    }
    return 0;
}