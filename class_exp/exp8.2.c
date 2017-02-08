#include <stdio.h>
#include <stdlib.h>
struct information
{
  char name[200],sex[3];
  int num,age;
  struct information *next; 
};
int main(int argc, char const *argv[])
{
    int number,i,j,ch;
    struct information *header=NULL, *p1, *p2;
    
    p1=p2 = (struct information*)malloc(sizeof(struct information));
    // printf("please enter the node num:\n");//
    scanf("%d",&number);

   for ( i = 0; i < number; i++)
   {
      
      p1= (struct information*)malloc(sizeof(struct information));
      if (header == NULL) header = p1;
      else  p2->next = p1;
      p2 = p1;  
      // printf("enter the number:\n");
      scanf("%d",&p1->num);
      // printf("enter the name:\n");
      getchar();
      gets(p1->name);
      // printf("enter sex :\n");
      gets(p1->sex);
      // printf("enter age :\n");
      scanf("%d",&p1->age);
      
   }
   p2->next = NULL;
 //输出链表  
// puts("\n") ;
// struct information *p;
// p = header;

//    do
//    {
//     printf("%d\n%s\n%s\n%d\n",p->num,p->name,p->sex,p->age );
//     p = p->next;
//    }while(p != NULL);

//删除节点

 
    // printf("enter a number(0 to quit):\n");
    scanf("%d",&ch);
    while(ch!=0)
    {

       p1 = header;
       while(p1->age != ch && p1->next!=NULL)
       {
            p2 = p1;
            p1 = p1->next;
       }
       if (p1->age == ch)
       {
           if (header == p1)
           {
               header = p1->next;
           }
           else
           {
                p2->next = p1->next;
           }
           printf("Delete success!\n");
       }
       else
            printf("Can't find!\n");

        // printf("enter a number(0 to quit):\n");
        scanf("%d",&ch);
    }


    return 0;
}

