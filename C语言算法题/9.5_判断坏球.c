#include <stdio.h>
#include <stdlib.h>
int t1,t2,flag,x1,x2,x3,r,x4,t3,res;
int sel()
{
    int a;
    char q[]={"left heavy","balance","right heavy"};
    do
    {
        printf(
            "please answear the state of balance(0:left heavy1:balance2:right heavy):");
        scanf("%d", &a);
    }
    while (a != 0 && a != 1 && a != 2);
    printf("\nyou choose%s", (q+a));
    return (a);
}
void thir(int x1, int x2, int x3)
{
     int t3=0;
    printf("\nbad ball is among %d,%d,%d\n", x1, x2, x3);
    printf("\nthird time:%d put left,%d put right\n", x1, x2);
    t3 = sel();											/*将第三次称重结果赋给t3*/
    if (t3 == 1) 											/*如果天平平衡*/
    {
        res = x3;										/*则坏球为x3*/
        if (t2 == 0)  										/*如果第二次称重左边重则坏球轻否则坏球重*/
            flag = 0;
        else
            flag = 1;
    }
    else if (t2 == 0 && t3 == 0)								/*如果第二次第三次均左边重*/
    {
        res = x1; 										/*则坏球为x1*/
        flag = 1;										/*坏球重*/
    }
    else if (t2 == 0 && t3 == 2)								/*如果第二次左边重第三次右边重*/
    {
        res = x2;  										/*则坏球为x2*/
       flag = 1;               							/*坏球重*/
    }
    else if (t2 == 2 && t3 == 0) 								/*如果第二次称重右边重第三次左边轻*/
    {
        res = x2;										/*则坏球为x2*/
        flag = 0;            								/*坏球轻*/
    }
    else
    {
        res = x1; 										/*否则坏球为x1*/
        flag = 0;				 						/*坏球轻*/
    }
    return ;
}
int main()
{
    printf("\nThe number of bad ball,light or heavy? please confirm!\n");
    printf("start:");
    printf("\nfirst time:1~4put left,5~8 put right\n");
    t1 = sel(); 										/*调用sel()函数返回值赋给t1*/
    flag = 0;
    if (t1 == 1)										/*第一次称如果天平两边平衡*/
    {
        printf("1~8 are good balls,bad ball among 9~12\n");
        printf("\nsecond time:9,10 put left\n");
        printf("11,1 put right\n");
        x1 = 9;
        x2 = 10;
        x3 = 11;
        x4 = 12;
        r = 1;
        t2 = sel(); 									/*调用sel()函数返回值赋给t2*/
        if (t2 == 1)									/*第二次称如果天平两边平衡*/
        {
            printf("\nthird time:%d put left,%d put right\n", x4, r);
            t3 = sel(); 								/*调用sel()函数返回值赋给t3*/
            res = x4; /*坏球是12号*/
            if (t3 == 0)								/*若果左边重说明坏球重，否则坏球轻*/
                flag = 1;
            else
                flag = 0;
        }
        else  										/*第二次称如果天平两边不平衡则进行第三次称重*/
            thir(x1, x2, x3);
    }
    else											/*第一次称如果天平两边不平衡,说明坏球在9~12中*/
    {
        printf("9-12 are good balls,bad ball among1-8\n");
        printf("second time:1,2 still put left,take off 3\n");
        printf("\t4 and 5 exchange,6 still puts right\n");
        printf("\ttake off 7,8,put 9\n");
        t2 = sel();									/*第二次称重后的结果赋给t2*/
        r = 12;
        if (t1==0&&t2==2||t1==2&&t2==0)
        {
            printf("\nthird time:4 puts left,9 puts right!\n");
            t3 = sel();  								/*第三次称重后的结果赋给t3*/
            res = 4; 									/*当坏球是4号球时*/
            if (t3 == 0)								/*如果左面重，则说明4号球重*/
                flag = 1;  							/*重则标志位置1*/
            else if (t3 == 2)							/*如果右面重，则说明4号球轻*/
                flag = 0;								/*轻则标志位置1*/
            else
            {
                res = 5; 								/*如果天平平衡则说明坏球是5号球*/
                if (t2 == 0)  							/*如果第二次称重时左面重则说明5号球重*/
                   flag = 1;
                else
                    flag = 0;							/*如果第二次称重时左面轻则说明5号球轻*/
            }
        }
        else
        {
            if (t1 == 0 && t2 == 0 || t1 == 2 && t2 == 2)   
			/*如果一直是一面重或一面轻，则坏球在1，2，6中，否则在7，8，3中*/
            {
                x1 = 1;
                x2 = 2;
                x3 = 6;
            }
            else
            {
                x1 = 7;
                x2 = 8;
                x3 = 3;
                if (t1 == 0) 
			/*当坏球在7，8，3中时可能第一次称重左面轻第二次右面重或是第二次平衡*/
                    t2 = 2;
                else
                    t2 = 1;
            }
            thir(x1, x2, x3);								/*调用函数thir进行第三次比较*/
        }
    }
    printf("\n\tthe bad ball is %d", res);							/*输出最终坏球的球号*/
    if (flag == 0)										/*flag=0说明坏球轻否则重*/
        printf("light!\n\n");
    else
        printf("==>heavy!\n\n");
        
        system("PAUSE");	
  return 0;
}
