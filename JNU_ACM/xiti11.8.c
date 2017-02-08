#include <stdio.h>
struct information
{
    int number;
    int grade;
    struct information *next;
};
int main(int argc, char const *argv[])
{
    int n, m, i, j;
    scanf("%d%d", &n, &m);
    struct information a[n];
    struct information b[m];
    struct information *header1 = NULL, *header2 = NULL, *p1, *p2, *p3, *p4;
    for (i = 0; i < n; i++)
    {
        p1 = &a[i];
        if (header1 == NULL) header1 = p1;
        else p2->next = p1;
        p2 = p1;
        scanf("%d%d", &p1->number, &p1->grade);
    }
    p2->next = NULL;
 
    for (i = 0; i < m; i++)
    {
        p3 = &b[i];
        if (header2 == NULL) header2 = p3;
        else p4->next = p3;
        p4 = p3;
        scanf("%d%d", &p3->number, &p3->grade);
    }
    p4->next = NULL;
 
    p2->next = header2;
 
 
 
    // sort the linked list
    struct information *p,*p5;
    int temp1,temp2;
    p = header1;
     
    for (i = 0; i < n + m - 1; i++)
    {
        p5 = p->next;
        if (p == NULL)
        {
            break;
        }
        else {
            for ( j = i + 1; j < n + m; j++)
            {
                if (p5->number < p->number)
                {
                    temp1 = p5->number;
                    temp2 = p5->grade;
                    p5->number = p->number;
                    p5->grade = p->grade;
                    p->number = temp1;
                    p->grade = temp2;
                }
                p5= p5->next;
            }
            p = p->next;
        }
 
 
    }
 
 
    p = header1;
    do
    {
        printf("%d %d\n", p->number, p->grade );
        p = p->next;
    } while (p != NULL);
    // output linked list;
 
    return 0;
}