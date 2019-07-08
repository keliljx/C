#include <stdio.h>
#include <conio.h>

void chessBoard(int tr,int tc,int dr,int dc,int size);

static int tile = 1;
int chess[100][100];

int main(void)
{
 int size,dr,dc,i,j;
 printf("���������̵Ŀ�ȣ�");
 scanf("%d",&size);
 printf("���̵ĳ�ʼ����Ϊ��0��0��\n");
 printf("���������������꣺");
 scanf("%d %d",&dr,&dc);
 chess[dr][dc] = 0;
 chessBoard(0,0,dr,dc,size);
 printf("\n");
 for(i = 0;i < size;i++)
 {
  printf("  ");
  for(j = 0;j < size;j++)
  {
   printf("%-4d",chess[i][j]);
  }
  printf("\n");
 }
 getch();
 return 0;
}

void chessBoard(int tr,int tc,int dr,int dc,int size)
{
 int t = tile++;/*L�͹��ƺ�*/
 int s = size/2;/*�ָ�����*/ 
 if(size == 1)
 {
  tile--;
  return;
 }
 /*�������Ͻ�������*/
 if(dr < tr + s && dc < tc + s)
 {
 /*���ⷽ���ڴ�������*/
  chessBoard(tr,tc,dr,dc,s);
 }
 else/*û�����ⷽ��*/
 {
 /*��t��L�͹��Ƹ������½�*/
  chess[tr + s - 1][tc + s - 1] = t;
  /*�������෽��*/
  chessBoard(tr,tc,tr + s - 1,tc + s - 1,s);
 }
 /*�������Ͻ�������*/
 if(dr < tr +s && dc >= tc +s)
 {
 /*���ⷽ���ڱ�������*/ 
  chessBoard(tr,tc + s,dr,dc,s);
 }
 else
 {
     /*��t��L�͹��Ƹ������½�*/
  chess[tr + s - 1][tc + s] = t;
  chessBoard(tr,tc+s,tr + s - 1,tr + s - 1,s);
 }
 /*�������½�������*/
 if(dr >= tr + s && dc < tc + s)
 {
       
  chessBoard(tr + s,tc,dr,dc,s);
 }
 else
 {
    /*��t��L�͹��Ƹ������Ͻ�*/ 
  chess[tr + s][tc + s - 1] = t;
  chessBoard(tr + s,tc,tr + s,tr + s - 1,s);
 }
  /*�������½�������*/
 if(dr >= tr + s && dc >= tc + s)
 {
  chessBoard(tr + s,tr + s,dr,dc,s);
 }
 else
 {
     /*��t��L�͹��Ƹ������Ͻ�*/  
  chess[tr + s][tc + s] = t;
  chessBoard(tr + s,tc + s,tr + s,tc + s,s);
 }
}
