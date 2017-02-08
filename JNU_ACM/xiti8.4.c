#include<stdio.h>
int main(int argc, char const *argv[])
{
    int a[3][3],temp;
    int i,j;
    for ( i = 0; i < 3; i++)
    {
        for ( j = 0; j < 3; j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for ( i = 0; i < 3; i++)
    {
        for ( j = i+1; j < 3; j++)
        {
            temp = a[i][j];
            a[i][j]=a[j][i];
            a[j][i] = temp;
        }
    }
    for ( i = 0; i < 3; i++)
    {
        for ( j = 0; j < 3; j++)
        {
            printf("%d ",a[i][j] );
        }
        printf("\n");
        // if (i<2)
        //  printf("\n");
    }
    return 0;
}