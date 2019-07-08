#include <stdio.h>
#include <stdlib.h>
 int main()
{
    int i = 1, j = 0, n = 0, a[14] ={0};							/*为数组中元素赋初值为0*/
    while (i <= 13)
    {
        while (1)
        {
            j++;
            if (j > 13)									/*当j大于13是，将其重新置1*/
                j = 1;
            if (!a[j])										/*如果该位置元素为0则n加1*/
                n++;
            if (n == i)
            {
                a[j] = i;									/*将i的值放入数组指定位置中*/
                n = 0;									/*计数器重新置0*/
                break;									/*调出内层循环*/
            }
        }
        i++;											/*数数加1*/
    }
    printf("the original order of cards is:\n");
    for (i = 1; i <= 13; i++)
        printf("%3d", a[i]);									/*输出扑克牌原有顺序*/
    system("PAUSE");	
  return 0;
}
