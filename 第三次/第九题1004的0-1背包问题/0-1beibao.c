/*输入函数将两组数字存储在
一个结构体数组中*/
#include <stdio.h>
#include <stdlib.h>
/*f(i,c)=max(f(i-1,c),f(i-1,c-wi)+vi)
状态方程*/

#define maxsize 10
int n,c;
int x=0;
typedef struct bagnode
{
    int weight;
    int value;
   struct bagnode * next;
}*bag,bagnode;

bag input()
{
    bag d,z;
    d=(bag)malloc(sizeof(bagnode));
    d->next =d;
    z=d;
    int i;
    scanf("%d%d",&n,&c);
    for(i=0; i<n; i++)
    {
        scanf("%d",&z->weight);
        if(i<n)
        {
            bag y;
            y=(bag)malloc(sizeof(bagnode));
            z->next =y;
            y->next =d;
            z=y;
        }
    }
    z=d;
    for( i=0; i<n; i++)
    {
        scanf("%d",&z->value);
        z=z->next;
    }
    return d;
}

int maxvalue(bag d,int capacity)
{
    while(d->weight>capacity&&x++<n)
    {
        d=d->next;
    }
    if((x++<n)&&d->weight<=capacity)
    {
        int a,b,c;
        c=x;
        a=maxvalue(d->next,capacity);
        x=c;
        b=maxvalue(d->next,capacity-d->weight)+d->value;
        return(a>b?a:b);
    }
    if(x>=n)
    {
        return 0;
    }
}

void main()
{
    bag d;
    int a[maxsize];
    int i=0;
    int j;
    while(1)
    {
        x=0;
        d=input();
        if(n||c)
        {
            a[i]=maxvalue(d,c);
            i++;
        }
        else
            break;
    }
    for( j=0; j<i; j++)
        printf("%d\n",a[j]);
}
