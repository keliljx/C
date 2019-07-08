#include <stdio.h>
#include <stdlib.h>
typedef int datatype;
typedef struct node{
    datatype data;
    struct node *next;        
}listnode;
typedef listnode *linklist;
listnode *p ;
linklist createlist()
{
    int ch;
    linklist head;
    listnode *p;
    head=NULL;
    scanf("%d",&ch);
    while (ch!=0){
          p=(listnode*)malloc(sizeof(listnode));
          p->data=ch;
          p->next=head;
          head=p;
         scanf("%d",&ch);
          }         
          return (head);
}

listnode * minpoint(linklist head,char key)
{   
    listnode * p=head;
    while(p->next && p->data!=key)
            p=p->next;
            if(p!=NULL)
            printf("要查找的数值是：%d\n",(p->data));                 
    return p;
          
}
int main()
{ 
  linklist list;
  listnode *node;
  int key=5;
  printf("请输入链表的值："); 
  list=createlist();
  node=minpoint(list,key); 
  system("PAUSE");	
  return 0;
}
