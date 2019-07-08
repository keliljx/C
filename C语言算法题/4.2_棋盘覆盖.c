#include <stdio.h>
#include <conio.h>

void chessBoard(int tr,int tc,int dr,int dc,int size);

static int tile = 1;
int chess[100][100];

int main(void)
{
 int size,dr,dc,i,j;
 printf("请输入棋盘的宽度：");
 scanf("%d",&size);
 printf("棋盘的初始坐标为（0，0）\n");
 printf("请输入特殊格的坐标：");
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
 int t = tile++;/*L型骨牌号*/
 int s = size/2;/*分割棋盘*/ 
 if(size == 1)
 {
  tile--;
  return;
 }
 /*覆盖左上角子棋盘*/
 if(dr < tr + s && dc < tc + s)
 {
 /*特殊方格在此棋盘中*/
  chessBoard(tr,tc,dr,dc,s);
 }
 else/*没有特殊方格*/
 {
 /*用t号L型骨牌覆盖右下角*/
  chess[tr + s - 1][tc + s - 1] = t;
  /*覆盖其余方格*/
  chessBoard(tr,tc,tr + s - 1,tc + s - 1,s);
 }
 /*覆盖右上角子棋盘*/
 if(dr < tr +s && dc >= tc +s)
 {
 /*特殊方格在本期盘中*/ 
  chessBoard(tr,tc + s,dr,dc,s);
 }
 else
 {
     /*用t号L型骨牌覆盖左下角*/
  chess[tr + s - 1][tc + s] = t;
  chessBoard(tr,tc+s,tr + s - 1,tr + s - 1,s);
 }
 /*覆盖左下角子棋盘*/
 if(dr >= tr + s && dc < tc + s)
 {
       
  chessBoard(tr + s,tc,dr,dc,s);
 }
 else
 {
    /*用t号L型骨牌覆盖右上角*/ 
  chess[tr + s][tc + s - 1] = t;
  chessBoard(tr + s,tc,tr + s,tr + s - 1,s);
 }
  /*覆盖右下角子棋盘*/
 if(dr >= tr + s && dc >= tc + s)
 {
  chessBoard(tr + s,tr + s,dr,dc,s);
 }
 else
 {
     /*用t号L型骨牌覆盖左上角*/  
  chess[tr + s][tc + s] = t;
  chessBoard(tr + s,tc + s,tr + s,tc + s,s);
 }
}
