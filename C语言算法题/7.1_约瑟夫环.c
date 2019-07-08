#include <stdio.h>
#include<stdlib.h>
#define N 9
#define OVERFLOW 0
#define OK 1
int KeyW[N]={1,2,3,4,5,6,7,8,9};							/*人员编号*/


typedef struct LNode{
	int keyword;										/*表示编号*/
	struct LNode *next;
}LNode,*LinkList;


void Joseph(LinkList p,int m,int x){
	LinkList q;											/*声明变量*/
	int i;
	if(x==0)return;
	q=p;												/*获取头结点*/
	m%=x;											/*取余*/
	if(m==0)m=x;
	for(i=1;i<=m;i++){									/*找到下一个结点*/
		p=q;
		q=p->next;		
	}
	p->next=q->next;									/*移动结点*/
	i=q->keyword;										/*获取编号*/
	printf("%d ",q->keyword);
	free(q);											/*释放结点*/
	Joseph(p,i,x-1);										/*递归调用*/
}


int main()
{
	int i,m;
	LinkList Lhead,p,q;
	Lhead=(LinkList)malloc(sizeof(LNode));					/*申请结点空间*/
	if(!Lhead) return OVERFLOW;
	Lhead->keyword=KeyW[0];							/*数据域赋值*/
	Lhead->next=NULL;
	p=Lhead;											/*指向头结点*/
	for(i=1;i<9;i++){									/*创建循环链表*/
		if(!(q=(LinkList)malloc(sizeof(LNode))))return OVERFLOW;
		q->keyword=KeyW[i];							/*数据域赋值*/
		p->next=q;
		p=q;											/*移动到下一个结点*/
	}
	p->next=Lhead;										/*尾结点指向头结点，形成循环链表*/
	printf("Please input the first record m: \n");
	scanf("%d",&m);									/*输入起始位置*/
	printf("The output alignment is:\n");
	Joseph(p,m,N);										/*调用函数*/
	return OK;   
}


