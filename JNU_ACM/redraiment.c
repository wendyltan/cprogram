#include<stdio.h>
  int main()
  {
      int a, b;
      while(scanf("%d/%d", &a, &b) != EOF&&a&&b)//一切非0都可以视为真，一旦为0则假
      {
          if(a == 8){
              b = b + 31;
              if(b > 55)
                printf("0\n");
              else if (b > 45)
               printf("1\n");
             else if (b > 36)
               printf("2\n");
             else if(b > 31)
               printf("3\n");
         }
         else if(a == 7){
             if (b > 28)
               printf("3\n");
             else if (b > 21)
               printf("4\n");
             else if (b > 15)
               printf("5\n");
             else if (b > 10)
               printf("6\n");
             else if (b > 6)
               printf("7\n");
             else if (b > 3)
              printf("8\n");
           else if (b > 1)
               printf("9\n");
             else if (b == 1)
               printf("10\n");
         }
     }
     return 0;
}
//此题不需要什么思路，每天对应一个答案输出即可