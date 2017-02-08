#include<stdio.h>
struct information {
    char number[10];
    char name[10];
    int grades[3];
 
} students[100];
int main(int argc, char const *argv[])
{
    int n, i, j, sum = 0, average[3];
    scanf("%d", &n);
    int  st_average[n];
    for ( i = 0; i < n; i++)
    {
        scanf("%s%s", &students[i].number, &students[i].name);
        scanf("%d %d %d", &students[i].grades[0], &students[i].grades[1], &students[i].grades[2]);
    }
 
 
    for (i = 0; i < 3; i++)
    {
        for ( j = 0; j < n; j++)
        {
            sum += students[j].grades[i];
        }
        average[i] = sum / n;
        sum = 0;
    }
    for ( i = 0; i < 3; i++)
    {
        printf("%d", average[i]);
        if (i != 2)
        {
            putchar(' ');
        }
    }
 
    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < 3; j++)
        {
            sum += students[i].grades[j];
        }
        st_average[i] = sum / 3;
        sum = 0;
    }
    int max;
    for (i = 0; i < n-1; i++)
    {
        for ( j= i+1; j<n; j++)
        {
            if (st_average[i]>st_average[j])
            {
                max = i;
            }
            else
            {
                max = j;
            }
        }
    }
    printf("\n");
    printf("%s %s %d %d %d", students[max].number, students[max].name , students[max].grades[0], students[max].grades[1], students[max].grades[2]);
 
 
 
 
 
    return 0;
}