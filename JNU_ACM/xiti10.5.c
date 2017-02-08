#include<stdio.h>
#include<stdlib.h>
int main(int argc, char const *argv[])
{
    int n; 
    int num;
    int i, flag = 0;//这是一个标记，报数到3时重置为0
    scanf("%d", &n);
    int a[n];
    num = n;
    for ( i = 0; i < n; i++)
    {
        a[i]=0;//对于任意大小的输入，全部先初始化位置为0
    }
    while (num != 1)//剩余人数为1时退出循环
    {
        for ( i = 0; i < n; i++)
        {
            if (a[i] == 0)
            {
                flag++;
            }
            if (flag==3)
            {
                a[i]=1;//如果为3，标记为1
                flag = 0;//重置flag
                num--;//剩余人数减一
            }
        }
    }
    for ( i = 0; i < n; i++)
    {
        if (a[i]==0)
        {
            printf("%d",i+1 );//第一个为0的即是剩余的一个人
            break;
        }
    }
 
    return 0;
}//类似扫雷插旗子。不直接改变数组的内容。参考约瑟夫环