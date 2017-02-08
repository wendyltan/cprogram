#include<stdio.h>
#include<string.h>
int main(int argc, char const *argv[])
{
    char a[100], b[100], temp;
    int i, j, counter, min,t;
    memset(b,0,sizeof(b));
    scanf("%s", a);
    i = strlen(a);
    counter = 0;
    for ( j = 0; j < i; j++)
    {
        if (a[j] == 'a' || a[j] == 'e' || a[j] == 'i' || a[j] == 'o' || a[j] == 'u')
        {
            b[counter] = a[j];
            counter++;
        }
        else continue;
    }
    i = strlen(b);
    for ( t = 0; t < i; t++)
    {
        min = t;
        for ( j = t + 1; j <i; j++)
        {
            if (b[j] < b[min])
            {
                min = j;
            }
 
        }
        temp = b[min];
        b[min] = b[t];
        b[t] = temp;
    }
    for ( t = 0; t < i; t++)
        printf("%c",b[t]);
    return 0;
}