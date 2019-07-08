#include <graphics.h>
#include <stdlib.h>
#include <dos.h>
#include<conio.h>
#define LEFT 0x4b00
#define RIGHT 0x4d00
#define DOWN 0x5000
#define UP 0x4800
#define ESC 0x011b
#define N 100/*̰���ߵ���󳤶�*/
int i,key;
int speed;/*��Ϸ�ٶ�*/
struct FOOD
{
   int x;/*ʳ��ĺ�����*/
   int y;/*ʳ���������*/
   int flag;/*��־�Ƿ�Ҫ����ʳ��*/
}food;
struct Snake
{
   int x[N];
   int y[N];
   int node;/*�ߵĽ���*/
   int dir;/*���ƶ�����*/
   int life;/*��־�����ǻ�*/
}snake;
void GameOver();/*������Ϸ*/
void Play();/*����Ϸ����*/
void dwall();/*��ǽ*/
void wall(int x,int y);/*�����ǽ��ש*/
int Speed();/*ѡ��̰���ߵ��ٶ�*/

main()
{
  int gdriver=DETECT,gmode;
   initgraph(&gdriver,&gmode,"");
   speed=Speed();/*����������ֵ����speed*/
   cleardevice();/*����*/
   dwall();/*��ʼ��ǽ*/
   Play();/*��ʼ����Ϸ*/
   getch();
   closegraph();/*�˳�ͼ�ν���*/
}

void wall(int x,int y)
{
 int sizx=9;
 int sizy=9;
 setcolor(15);/*��ɫ��ש���ϱߺ����*/
 line(x,y,x+sizx,y);
 line(x,y+1,x+sizx-1,y+1);
 line(x,y,x,y+sizy);
 line(x+1,y,x+1,y+sizy-1);
 setcolor(4);/*��ɫ��ש�����������*/
 line(x+1,y+sizy,x+sizx,y+sizy);
 line(x+2,y+sizy-1,x+sizx,y+sizy-1);
 line(x+sizx-1,y+2,x+sizx-1,y+sizy-1);
 line(x+sizx,y+1,x+sizx,y+sizy);
 setfillstyle(1,12);/*�õ���ɫ���ש���м䲿��*/
 bar(x+2,y+2,x+sizx-2,y+sizy-2);
}
void dwall()/*��ǰ�滭�õ�ש����ǽ*/
{int j;
for(j=50;j<=600;j+=10)
{
	wall(j,40);/*������ǽ*/
	wall(j,451);/*������ǽ*/
}
for(j=40;j<=450;j+=10)
{
wall(50,j);/*������ǽ*/
wall(601,j);/*������ǽ*/
}
}
int Speed()/*ѡ��̰�������е��ٶ�*/
{           int m;
gotoxy(20,10);
   printf("level1\n");
   gotoxy(20,12);
   printf("level2\n");
   gotoxy(20,14);
   printf("level3\n\t\tplease choose:");
   scanf("%d",&m);
   switch(m)
   {
   case 1:return 60000;
   case 2:return 40000;
   case 3:return 20000;
   default:
   cleardevice();
   Speed();
   }
}

void Play(void)/*��Ϸʵ�ֹ���*/
{
   srand((unsigned long)time(0));
   food.flag=1;/*1��ʾ�������ʳ��,0��ʾʳ���Ѵ���*/
   snake.life=0;/*��־̰���߻���*/
   snake.dir=1;/*��������*/
   snake.x[0]=300;snake.y[0]=240;/*��λ��ͷ��ʼλ��*/
   snake.x[1]=300;snake.y[1]=240;
   snake.node=2;/*̰ʳ�߽���*/
   do
   {
      while(!kbhit())/*��û�а����������,���Լ��ƶ�����*/
      {
	 if(food.flag==1)/*��Ҫ������ʳ��*/
	 do
	 {
	     food.x=rand()%520+60;
	     food.y=rand()%370+60;
		food.flag=0;/*��־����ʳ��*/
	 }while(food.x%10!=0||food.y%10!=0);
	 if(food.flag==0)/*����ʳ��*/
	 {
              setcolor(GREEN);
	      setlinestyle(3,0,3);
              rectangle(food.x,food.y,food.x+10,food.y+10);
	 }
         for(i=snake.node-1;i>0;i--)/*ʵ������ǰ�ƶ�*/
         {
            snake.x[i]=snake.x[i-1];
	    snake.y[i]=snake.y[i-1];
	 }
      
	 switch(snake.dir)
	 {
	    case 1:snake.x[0]+=10;break;/*������*/
	    case 2: snake.x[0]-=10;break;/*������*/
	    case 3: snake.y[0]-=10;break;/*������*/
	    case 4: snake.y[0]+=10;break;/*������*/
	 }
	 for(i=3;i<snake.node;i++)
	 {
	    if(snake.x[i]==snake.x[0]&&snake.y[i]==snake.y[0])/*�ж����Ƿ�Ե��Լ�*/
	    {
               GameOver();/*��Ϸ����*/
               snake.life=1;/*����*/
               break;
	    }
        }
	if(snake.x[0]<60||snake.x[0]>590||snake.y[0]<50||
	   snake.y[0]>440)/*���Ƿ�ײ��ǽ��*/
	{
	    GameOver();/*��Ϸ����*/
	    snake.life=1; /*����*/
	    break;
	}
	if(snake.x[0]==food.x&&snake.y[0]==food.y)/*�ж��Ƿ�Ե�ʳ��*/
	{
           setcolor(0);/*�ñ���ɫ�ڸǵ�ʳ��*/
           rectangle(food.x,food.y,food.x+10,food.y+10);
	   snake.node++;/*�ߵ����峤һ��*/
	   food.flag=1;/*��Ҫ�����µ�ʳ��*/
	}
	setcolor(4);/*����*/
	for(i=0;i<snake.node;i++)
	 {     setlinestyle(0,0,1);
	   rectangle(snake.x[i],snake.y[i],snake.x[i]+10,
	       snake.y[i]+10);
	       }
	delay(speed);
	setcolor(0);/*�ñ���ɫ�ڸ��ߵĵ����һ��*/
	rectangle(snake.x[snake.node-1],snake.y[snake.node-1],
	snake.x[snake.node-1]+10,snake.y[snake.node-1]+10);
     }  /*endwhile����kbhit��*/
    if(snake.life==1)/*�������������ѭ��*/
        break;
    key=bioskey(0);/*���հ���*/
       if(key==UP&&snake.dir!=4)/*�ж��Ƿ����෴�ķ����ƶ�*/
	  snake.dir=3;
       else
	 if(key==DOWN&&snake.dir!=3)/*�ж��Ƿ����෴�ķ����ƶ�*/
		   snake.dir=4;
	  else
	      if(key==RIGHT&&snake.dir!=2)/*�ж��Ƿ����෴�ķ����ƶ�*/
	     snake.dir=1;
	     else
	if(key==LEFT&&snake.dir!=1)/*�ж��Ƿ����෴�ķ����ƶ�*/
		snake.dir=2;
   }while(key!=ESC);/*ESC���˳���Ϸ*/
}

void GameOver(void)
{
    cleardevice();
   setcolor(RED);
   settextstyle(0,0,4);
   outtextxy(50,200,"GAME OVER,BYE BYE!");
   sleep(3);
}
