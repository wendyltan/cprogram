#include<stdio.h>
struct information {
    char number[100];
    char name[100];
    int grades[3];
}students[100];
int main(int argc, char const *argv[])
{
    int i, n, j;
    scanf("%d", &n);
    for ( i = 0; i < n; i++)
    {
        scanf("%s%s%d%d%d",&students[i].number,&students[i].name,&students[i].grades[0],&students[i].grades[1],&students[i].grades[2]);
  
    }
    for ( i = 0; i < n; i++)
    {
          
        printf("%s,%s,%d,%d,%d",students[i].number,students[i].name ,students[i].grades[0],students[i].grades[1],students[i].grades[2]);
  
        printf("\n");
  
          
    }
  
    return 0;
}