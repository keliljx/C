#include <stdio.h> 
#include <stdlib.h> 
#define MAX 20 
typedef struct 
{ 
	int num; 
	char name[20]; 
} ElemType;//定义查找的结点元素 
typedef struct 
{ 
	ElemType *elem; 
	int count; 
	int sizeindex; 
} HashTable;//定义哈希表 
int Hash(int num) 
{ 
	int p; 
	p=num%5; 
	return p; 
}//定义哈希函数 
void InitHash(HashTable *H)//创建哈希表 
{ 
	int i; 
	H->elem=(ElemType *)malloc(MAX*sizeof(ElemType)); 
	H->count=0; 
	H->sizeindex=MAX; 
	for(i=0;i<MAX;i++) 
		H->elem[i].num=0;//初始化，使SearHash函数能判断到底有没有元素在里面 
} 
int SearHash(HashTable H,int key,int *p)//查找函数 
{ 
	int c=0; 
	*p=Hash(key); 
	while(H.elem[*p].num!=key&&H.elem[*p].num!=0) //通过二次探测再散列解决冲突
	{
		c=c+1; 
		if(c%2==1) 
			*p=*p+(c+1)*(c+1)/4; 
		else 
			*p=*p-(c*c)/4; 
	} 
	if(H.elem[*p].num==key) 
		return 1; 
	else 
		return 0; 
} 


void InsertHash(HashTable *H,ElemType e) //如果查找不到就插入元素
{ 
	int p; 
	SearHash(*H,e.num,&p); 
	H->elem[p]=e; 
	++H->count; 
} 

void main()//主函数 
{ 
	HashTable H; 
	int p,key,i; 
	ElemType e; 
	InitHash(&H); 
	for(i=0;i<3;i++) //输入3个元素
	{ 
loop:	printf("输入第%d个学生学号\n",i+1); 
		scanf("%d",&e.num);//输入学号 
		if(!SearHash(H,e.num,&p)) 
		{ 
			printf("输入第%d个学生名字\n",i+1); 
			scanf("%s",e.name);//输入名字 
			InsertHash(&H,e);//插入元素 
		} 
		else
		{
			printf("该学号已经存在\n");//否则就表示元素的学号已经存在
			goto loop;//跳到loop处
		}
	} 
	printf("请输入您要查找查找的学生学号:\n"); 
	scanf("%d",&key);//输入要查找的学号 
	if(SearHash(H,key,&p))//能查找成功 
	{ 
		printf("查找成功！学生的姓名是%s\n",H.elem[p].name);//输出名字 
		printf("学生所在表中的位置是%d\n",p);//输出位置 
	} 
	else 
		printf("查找失败！您要查找的学生不存在！\n"); 
} 
