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
    t3 = sel();											/*�������γ��ؽ������t3*/
    if (t3 == 1) 											/*�����ƽƽ��*/
    {
        res = x3;										/*����Ϊx3*/
        if (t2 == 0)  										/*����ڶ��γ���������������������*/
            flag = 0;
        else
            flag = 1;
    }
    else if (t2 == 0 && t3 == 0)								/*����ڶ��ε����ξ������*/
    {
        res = x1; 										/*����Ϊx1*/
        flag = 1;										/*������*/
    }
    else if (t2 == 0 && t3 == 2)								/*����ڶ�������ص������ұ���*/
    {
        res = x2;  										/*����Ϊx2*/
       flag = 1;               							/*������*/
    }
    else if (t2 == 2 && t3 == 0) 								/*����ڶ��γ����ұ��ص����������*/
    {
        res = x2;										/*����Ϊx2*/
        flag = 0;            								/*������*/
    }
    else
    {
        res = x1; 										/*������Ϊx1*/
        flag = 0;				 						/*������*/
    }
    return ;
}
int main()
{
    printf("\nThe number of bad ball,light or heavy? please confirm!\n");
    printf("start:");
    printf("\nfirst time:1~4put left,5~8 put right\n");
    t1 = sel(); 										/*����sel()��������ֵ����t1*/
    flag = 0;
    if (t1 == 1)										/*��һ�γ������ƽ����ƽ��*/
    {
        printf("1~8 are good balls,bad ball among 9~12\n");
        printf("\nsecond time:9,10 put left\n");
        printf("11,1 put right\n");
        x1 = 9;
        x2 = 10;
        x3 = 11;
        x4 = 12;
        r = 1;
        t2 = sel(); 									/*����sel()��������ֵ����t2*/
        if (t2 == 1)									/*�ڶ��γ������ƽ����ƽ��*/
        {
            printf("\nthird time:%d put left,%d put right\n", x4, r);
            t3 = sel(); 								/*����sel()��������ֵ����t3*/
            res = x4; /*������12��*/
            if (t3 == 0)								/*���������˵�������أ���������*/
                flag = 1;
            else
                flag = 0;
        }
        else  										/*�ڶ��γ������ƽ���߲�ƽ������е����γ���*/
            thir(x1, x2, x3);
    }
    else											/*��һ�γ������ƽ���߲�ƽ��,˵��������9~12��*/
    {
        printf("9-12 are good balls,bad ball among1-8\n");
        printf("second time:1,2 still put left,take off 3\n");
        printf("\t4 and 5 exchange,6 still puts right\n");
        printf("\ttake off 7,8,put 9\n");
        t2 = sel();									/*�ڶ��γ��غ�Ľ������t2*/
        r = 12;
        if (t1==0&&t2==2||t1==2&&t2==0)
        {
            printf("\nthird time:4 puts left,9 puts right!\n");
            t3 = sel();  								/*�����γ��غ�Ľ������t3*/
            res = 4; 									/*��������4����ʱ*/
            if (t3 == 0)								/*��������أ���˵��4������*/
                flag = 1;  							/*�����־λ��1*/
            else if (t3 == 2)							/*��������أ���˵��4������*/
                flag = 0;								/*�����־λ��1*/
            else
            {
                res = 5; 								/*�����ƽƽ����˵��������5����*/
                if (t2 == 0)  							/*����ڶ��γ���ʱ��������˵��5������*/
                   flag = 1;
                else
                    flag = 0;							/*����ڶ��γ���ʱ��������˵��5������*/
            }
        }
        else
        {
            if (t1 == 0 && t2 == 0 || t1 == 2 && t2 == 2)   
			/*���һֱ��һ���ػ�һ���ᣬ������1��2��6�У�������7��8��3��*/
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
			/*��������7��8��3��ʱ���ܵ�һ�γ���������ڶ��������ػ��ǵڶ���ƽ��*/
                    t2 = 2;
                else
                    t2 = 1;
            }
            thir(x1, x2, x3);								/*���ú���thir���е����αȽ�*/
        }
    }
    printf("\n\tthe bad ball is %d", res);							/*������ջ�������*/
    if (flag == 0)										/*flag=0˵�������������*/
        printf("light!\n\n");
    else
        printf("==>heavy!\n\n");
        
        system("PAUSE");	
  return 0;
}
