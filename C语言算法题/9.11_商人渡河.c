#include <stdio.h>
#include <stdlib.h>
struct node                        /*建立一个类似栈的数据结构并且可以浏览每一个数据点*/
{
    int x;
    int y;
    int state;
    struct node *next;
};
typedef struct node state;
typedef state *link;
link PPointer1=NULL;
link PPointer2=NULL;
int a1,b1;
int a2,b2;
                                               /*栈中每个数据都分为0，1状态*/
void Push(int a,int b,int n)                   
{
    link newnode;
    newnode=(link)malloc(sizeof(state));
    newnode->x=a;
    newnode->y=b;
    newnode->state=n;
    newnode->next=NULL;
    if(PPointer1==NULL)
        {
            PPointer1=newnode;
            PPointer2=newnode;
        }
        else
        {
            PPointer2->next=newnode;
            PPointer2=newnode;
        }
}

void Pop()                            /*弹栈*/
{
    link pointer;
    if(PPointer1==PPointer2)
    {
        free(PPointer1);
        PPointer1=NULL;
        PPointer2=NULL;
    }
    pointer=PPointer1;
    while(pointer->next!=PPointer2)
        pointer=pointer->next;
    free(PPointer2);
    PPointer2=pointer;
    PPointer2->next=NULL;
} 

int history(int a,int b,int n)              /*比较输入的数据和栈中是否有重复的*/
{
    link pointer;
    if(PPointer1==NULL)
            return 1;
    else
    {
        pointer=PPointer1;
        while(pointer!=NULL)
        {
            if(pointer->x==a&&pointer->y==b&&pointer->state==n)
                return 0;
            pointer=pointer->next;
        }
        return 1;
    }
}
int judge(int a,int b,int c,int d,int n)      /*判断这个状态是否可行，其中使用了history函数*/
{
    if(history(a,b,n)==0) return 0;
    if(a>=0&&b>=0&&a<=3&&b<=3&&c>=0&&d>=0&&c<=3&&d<=3&&a+c==3&&b+d==3)
    {
        switch(n)
        {
            case 1:
            {
                if(a==3)
                {
                    Push(a,b,n);
                    return 1;
                }
                else if(a==0)
                {
                    Push(a,b,n);
                    return 1;
                }
                else if(a==b)
                {
                    Push(a,b,n);
                    return 1;
                }
                else return 0;
            }
case 0:
            {
                if(a==3)
                {
                    Push(a,b,n);
                    return 1;
                }
                else if(a==0)
                {
                    Push(a,b,n);
                    return 1;
                }
                else if(a>=b)
                {
                    Push(a,b,n);
                    return 1;
                }
                else return 0;
            }
        }
    }
    else return 0;
}
int Duhe(int a,int b,int n)               /*递归法解决商人渡河问题，如果这一个状态符合*/
{                                         /*则判断下一个状态，直至问题解决*/ 
    if(a==0&&b==0)  return 1;
    if(n==0)                                /*判断0状态时，商匪状态是否符合要求*/
    {
        if(judge(a-1,b-1,4-a,4-b,1))
        {
            if(Duhe(a-1,b-1,1)==1)
            return 1;
        }
        if(judge(a,b-2,3-a,5-b,1))
        {
            if(Duhe(a,b-2,1)==1)
            return 1;
        }
        if(judge(a-2,b,5-a,3-b,1))
        {
            if(Duhe(a-2,b,1)==1)
            return 1;
        }
        if(judge(a-1,b,4-a,3-b,1))
        {
            if(Duhe(a-1,b,1)==1)
            return 1;
        }
        if(judge(a,b-1,3-a,4-b,1))
        {
            if(Duhe(a,b-1,1)==1)
            return 1;
        }
        else
        {
            Pop(0);
            return 0;
        }
    }
if(n==1)                              /*判断0状态时，商匪状态是否符合要求*/
    {
        if(judge(a+1,b+1,2-a,2-b,0))
        {
            if(Duhe(a+1,b+1,0)==1)
            return 1;
        }
        if(judge(a,b+2,3-a,1-b,0))
        {
            if(Duhe(a,b+2,0)==1)
            return 1;
        }
        if(judge(a+2,b,1-a,3-b,0))
        {
            if(Duhe(a+2,b,0)==1)
            return 1;
        }
        if(judge(a+1,b,2-a,3-b,0))
        {
            if(Duhe(a+1,b,0)==1)
            return 1;
        }
        if(judge(a,b+1,3-a,2-b,0))
        {
            if(Duhe(a,b+1,0)==1)
            return 1;
        }
        else
        {
            Pop(1);
            return 0;
        }
    }
    return 0;
}

int main(int argc, char *argv[])
{
   link pointer;
    Push(3,3,0);
    Duhe(3,3,0);
    pointer=PPointer1;
    while(pointer!=NULL)
    {
        printf("河这边的商人数%d：",pointer->x);
        printf("河这边的强盗数%d:",pointer->y);
        printf("---------------"); 
        pointer->state==0?printf("船不在对岸"):printf("船在对岸");
        printf("\n");
        pointer=pointer->next;
    }

  system("PAUSE");	
  return 0;
}
