#include <stdio.h>
#include <stdlib.h>
#define X 8
#define Y 8
int chessboard[X][Y];
int nextstep(int *x,int *y,int count)
{
    switch(count)
    {
        case 0:if(*x+2<=X-1 && *y-1>=0 && chessboard[*x+2][*y-1]==0)
               {
                   *x=*x+2;
                   *y=*y-1;
                   return 1;             
               }            
               break;
         
         case 1: if(*x+2<=X-1 && *y+1<=Y-1 && chessboard[*x+2][*y+1]==0) 
                 {
                    *x = *x+2;
                    *y = *y+1 ;
                    return 1;
                 }
                 break;
        case 2: if(*x+1<=X-1 && *y-2>=0 && chessboard[*x+1][*y-2]==0)
                {
                    *x = *x+1;
                    *y = *y-2;
                    return 1;
                } 
                break;
        case 3: if(*x+1<=X-1 && *y+2<=Y-1 && chessboard[*x+1][*y+2]==0) 
                {
                     *x = *x+1; 
                     *y = *y+2;
                     return 1;
                }
                break;
        case 4: if(*x-2>=0 && *y-1>=0 && chessboard[*x-2][*y-1]==0) 
                {
                     *x = *x-2; 
                     *y = *y-1; 
                     return 1;
                } 
                break;
        case 5: if(*x-2>=0 && *y+1<=Y-1 && chessboard[*x-2][*y+1]==0)
                {
                     *x = *x-2; 
                     *y = *y+1; 
                     return 1;
                } 
                break;
        case 6:if(*x-1>=0 && *y-2>=0 && chessboard[*x-1][*y-2]==0) 
                {
                     *x = *x-1; 
                     *y = *y-2;
                     return 1;
                }
                break;
        case 7:  if(*x-1>=0 && *y+2<=Y-1 && chessboard[*x-1][*y+2]==0) 
                {
                     *x = *x-1; 
                     *y = *y+2; 
                     return 1;
                }
                break;
        default: break ;
    }
    return 0;
}

int TravelChessBoard(int x,int y,int tag)    /*深度优先搜索地"马踏棋盘"*/
{
    int x1 = x, y1 = y, flag = 0,a,b ,count = 0 ;
    chessboard[x][y] = tag;
    if(tag == X*Y)  { return 1;}
    flag = nextstep(&x1,&y1,count);
    while(flag == 0 && count <7){
          count = count + 1;
            flag = nextstep(&x1,&y1,count);
            }
       while(flag ){
        if(TravelChessBoard(x1,y1,tag+1))return 1;
          x1 = x;y1 = y;
          count = count +1;
          flag = nextstep(&x1,&y1,count);        /*寻找下一个(x,y)*/
          while(flag == 0 && count <7){        /*循环地寻找下一个(x,y)*/
            count = count + 1;
            flag = nextstep(&x1,&y1,count);
            }
    }
    if(flag == 0)
    chessboard[x][y] = 0;
    return 0;
}

int main()
{
   int i,j;
    for(i=0;i<X;i++)
        for(j=0;j<Y;j++)
        chessboard[i][j] = 0;
    if(TravelChessBoard(1,1,1)) {
    for(i=0;i<X;i++) {
        for(j=0;j<Y;j++)
            printf("%d    ",chessboard[i][j]);
            printf("\n");
            }
            printf("马踏棋盘矩阵\n");
            }
    else
    printf("马无路可走了！\n");
  system("PAUSE");	
  return 0;
}
