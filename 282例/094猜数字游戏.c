#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<dos.h>
void guess(int n)
{
   int acount,bcount,i,j,k=0,flag,a[10],b[10];
   do
   {
       flag=0;
       srand((unsigned)time(NULL));/*����ϵͳʱ���趨����*/
       for(i=0;i<n;i++)
           a[i]=rand()%10;/*ÿ�β���0��9��Χ�������һ����������浽����a��*/
       for(i=0;i<n-1;i++)
       {
           for(j=i+1;j<n;j++)
               if(a[i]==a[j])/*�ж�����a���Ƿ�����ͬ����*/
               {
                   flag=1;/*��������������־λ��1*/
                   break;
               }
       }
   }while(flag==1);/*����־λΪ1�����·�������*/
   do
   {
       k++;/*��¼�����ֵĴ���*/
       acount=0;/*ÿ�βµĹ�����λ�������־���ȷ�ĸ���*/
       bcount=0;/*ÿ�βµĹ�����λ�ò���ȷ��������ȷ�ĸ���*/
       printf("guess:");
       for(i=0;i<n;i++)
           scanf("%d",&b[i]);/*����²�����ݵ�����b��*/
       for(i=0;i<n;i++)
           for(j=0;j<n;j++)
           {
               if(a[i]==b[i])/*�����������������������������ͬ��λ����ͬ�ĸ���*/
               {
                   acount++;
                   break;
               }
               if(a[i]==b[j]&&i!=j)/*�����������������������������ͬ��λ�ò�ͬ�ĸ���*/
               {
                   bcount++;
                   break;
               }
           }
       printf("clue on:%d A %d B\n\n",acount,bcount);
       if(acount==n)/*�ж�acount�Ƿ������ֵĸ�����ͬ*/
       {
           if(k==1)
               printf(" you are the topmost rung of Fortune's ladder!! \n\n");
           else if(k<=5)
               printf("you are genius!!\n\n");
           else if(k<=10)
               printf("you are cleaver!!\n\n");
           else
               printf("you need try hard!!\n\n");
           break;
       }
   }while(1);
}

main()
{int i,n;
while(1)
{       clrscr();
	gotoxy(15,6);/*����궨λ*/
	printf("1.start game?(y/n)");
		gotoxy(15,8);
		printf("2.Rule");
	gotoxy(15,10);
	printf("3.exit\n");
	gotoxy(25,15);
printf("please choose:");
scanf("%d",&i);
switch(i)
{
case 1:                 clrscr();
	printf("please input n:\n");
	scanf("%d",&n);
guess(n);/*����guess����*/
sleep(5);/*����ֹͣ5����*/
break;
case 2:/*�����Ϸ����*/
clrscr();
printf("\t\tThe Rules Of The Game\n");
printf(" step1: input the number of digits\n");
printf(" step2: input the number,separated by a space between two numbers\n");
printf(" step3: A represent location and data are correct\n");
printf("\tB represent location is correct but data is wrong!\n");
sleep(10);
break;
case 3:/*�˳���Ϸ*/
exit(0);
default:break;
}
}
}