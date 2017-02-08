#include<stdio.h>
int main(int argc, char const *argv[])
{
    int a[3][3];
    int i,j,b,c;
    for (i = 0; i < 3; i++)
    {
        for ( j = 0; j < 3; j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    b = a[0][0]+a[1][1]+a[2][2];
    c = a[0][2]+a[1][1]+a[2][0];
    printf("%d %d",b,c );
    return 0;
}