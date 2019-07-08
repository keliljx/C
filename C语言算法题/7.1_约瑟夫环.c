#include <stdio.h>
#include<stdlib.h>
#define N 9
#define OVERFLOW 0
#define OK 1
int KeyW[N]={1,2,3,4,5,6,7,8,9};							/*��Ա���*/


typedef struct LNode{
	int keyword;										/*��ʾ���*/
	struct LNode *next;
}LNode,*LinkList;


void Joseph(LinkList p,int m,int x){
	LinkList q;											/*��������*/
	int i;
	if(x==0)return;
	q=p;												/*��ȡͷ���*/
	m%=x;											/*ȡ��*/
	if(m==0)m=x;
	for(i=1;i<=m;i++){									/*�ҵ���һ�����*/
		p=q;
		q=p->next;		
	}
	p->next=q->next;									/*�ƶ����*/
	i=q->keyword;										/*��ȡ���*/
	printf("%d ",q->keyword);
	free(q);											/*�ͷŽ��*/
	Joseph(p,i,x-1);										/*�ݹ����*/
}


int main()
{
	int i,m;
	LinkList Lhead,p,q;
	Lhead=(LinkList)malloc(sizeof(LNode));					/*������ռ�*/
	if(!Lhead) return OVERFLOW;
	Lhead->keyword=KeyW[0];							/*������ֵ*/
	Lhead->next=NULL;
	p=Lhead;											/*ָ��ͷ���*/
	for(i=1;i<9;i++){									/*����ѭ������*/
		if(!(q=(LinkList)malloc(sizeof(LNode))))return OVERFLOW;
		q->keyword=KeyW[i];							/*������ֵ*/
		p->next=q;
		p=q;											/*�ƶ�����һ�����*/
	}
	p->next=Lhead;										/*β���ָ��ͷ��㣬�γ�ѭ������*/
	printf("Please input the first record m: \n");
	scanf("%d",&m);									/*������ʼλ��*/
	printf("The output alignment is:\n");
	Joseph(p,m,N);										/*���ú���*/
	return OK;   
}


