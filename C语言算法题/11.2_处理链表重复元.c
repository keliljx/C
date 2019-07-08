#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
   int data;
   struct Node *next;
}NODE;
NODE *createlist()
{
    int ch;
    NODE *last=NULL;
    NODE *p,*head;
    head->next=NULL;
    head->data=NULL;
    scanf("%d",&ch);
    while (ch!=0){
          p=(NODE*)malloc(sizeof(NODE));
          p->data=ch;
          p->next=NULL;
          if(head->next==NULL){
              head->next=p;last=p;
          }
          else {
               last->next=p;last=p;
          }
          scanf("%d",&ch);
    }
    return head;
}
NODE *compress(NODE *head) 
{  NODE *ptr,*q;
   ptr =head->next; /*ȡ�õ�һ��Ԫ�ؽ���ָ�� */
   while(ptr&& ptr->next){
        q = ptr -> next;
        while(q&&(q->data==ptr->data)) {   /*�����ظ�Ԫ�� */
              ptr->next= q -> next;
            free(q);
            q = ptr -> next;
        }
         ptr= ptr->next;
}
   return (head);
}
void out(NODE *head){
      NODE *ptr;
      ptr =head->next;   /*ȡ�õ�һ��Ԫ�ؽ���ָ�� */
      printf("����������ǣ�\n");
      while(ptr->data!=NULL){
          printf("%3d",ptr->data);
          if(ptr->next!=NULL){
              ptr= ptr -> next;
          }
          else{
              break;     
          }
      }
}
int main()
{
  NODE *node,*list,*list1;
  printf("�����������ֵ��\n"); 
  list=createlist();
  list1=compress(list);
  out(list1);
  printf("\n");
  system("PAUSE");	
  return 0;
}


