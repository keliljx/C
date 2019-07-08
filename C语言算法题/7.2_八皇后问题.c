#include<string.h>
#include<stdio.h>
#include<conio.h>
int count=0;          /*用于记录解法数，定义为全局型变量*/

/*isCorrect函数用于判断该位置是否可以放置棋子*/
/*返回值为1表示可以放置，返回值为0表示不可以放置*/
int isCorrect(int i,int j, int (*chess)[8])		
{
	int q,t;
	for(q=i,t=0;t<8;t++)      /*判断水平方向*/
		if(chess[q][t]==1 && t!=j) return 0;
		
	for(q=0,t=j;q<8;q++)      /*判断竖直方向*/
		if(chess[q][t]==1 && q!=i) return 0;
			
	for(q=i-1,t=j-1;q>=0 && t>=0;q--,t--)  /*判断左上方*/
		if(chess[q][t]==1) return 0;
				
	for(q=i+1,t=j+1;q<8 && t<8;q++,t++)		/*判断右下方*/
		if(chess[q][t]==1) return 0;
					
	for(q=i-1,t=j+1;q>=0 && t<8;q--,t++)   /*判断右上方*/
		if(chess[q][t]==1) return 0;
						
	for(q=i+1,t=j-1;q<8 && t>=0;q++,t--)    /*判断左下方*/
		if(chess[q][t]==1) return 0;
	return 1;
}
/*eightqueen函数实现八皇后问题的回溯法求解*/
/*用0-1矩阵表示八皇后的棋盘局面，0表示未放置棋子，1表示已放置棋子*/
void eightqueen(int n,int (*chess)[8])
{
	int i,j;
	if(n==8)				/*得到一个解*/
	{
		for(i=0;i<8;i++)	/*将这个解的布局输出*/
		{
			for(j=0;j<8;j++)
				printf("%d ",chess[i][j]);
			printf("\n");
		}
		printf("\n");
		getch();
		count++;			/*解的数量加一*/
		return;
		
	}
	for(i=0;i<8;i++)
	{
		if(isCorrect(i,n,chess))	/*判断是否可以放置棋子*/
		{
			chess[i][n]=1;			/*放置皇后*/
			eightqueen(n+1,chess);   /*深度优先搜索解空间树*/
			chess[i][n]=0;
		}
	}
}
main()
{
	int chess[8][8],i,j;
	for (i=0;i<8;i++)				/*初始化棋盘数组*/
	{
		for(j=0;j<8;j++)
			chess[i][j]=0;
	}
	eightqueen(0,chess);			/*执行八皇后求解函数*/
	printf("The number of the answer for eightqueen is: %d",count);
	getch();	
}

