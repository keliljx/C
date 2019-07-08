#include<string.h>
#include<stdio.h>
#include<conio.h>
int count=0;          /*���ڼ�¼�ⷨ��������Ϊȫ���ͱ���*/

/*isCorrect���������жϸ�λ���Ƿ���Է�������*/
/*����ֵΪ1��ʾ���Է��ã�����ֵΪ0��ʾ�����Է���*/
int isCorrect(int i,int j, int (*chess)[8])		
{
	int q,t;
	for(q=i,t=0;t<8;t++)      /*�ж�ˮƽ����*/
		if(chess[q][t]==1 && t!=j) return 0;
		
	for(q=0,t=j;q<8;q++)      /*�ж���ֱ����*/
		if(chess[q][t]==1 && q!=i) return 0;
			
	for(q=i-1,t=j-1;q>=0 && t>=0;q--,t--)  /*�ж����Ϸ�*/
		if(chess[q][t]==1) return 0;
				
	for(q=i+1,t=j+1;q<8 && t<8;q++,t++)		/*�ж����·�*/
		if(chess[q][t]==1) return 0;
					
	for(q=i-1,t=j+1;q>=0 && t<8;q--,t++)   /*�ж����Ϸ�*/
		if(chess[q][t]==1) return 0;
						
	for(q=i+1,t=j-1;q<8 && t>=0;q++,t--)    /*�ж����·�*/
		if(chess[q][t]==1) return 0;
	return 1;
}
/*eightqueen����ʵ�ְ˻ʺ�����Ļ��ݷ����*/
/*��0-1�����ʾ�˻ʺ�����̾��棬0��ʾδ�������ӣ�1��ʾ�ѷ�������*/
void eightqueen(int n,int (*chess)[8])
{
	int i,j;
	if(n==8)				/*�õ�һ����*/
	{
		for(i=0;i<8;i++)	/*�������Ĳ������*/
		{
			for(j=0;j<8;j++)
				printf("%d ",chess[i][j]);
			printf("\n");
		}
		printf("\n");
		getch();
		count++;			/*���������һ*/
		return;
		
	}
	for(i=0;i<8;i++)
	{
		if(isCorrect(i,n,chess))	/*�ж��Ƿ���Է�������*/
		{
			chess[i][n]=1;			/*���ûʺ�*/
			eightqueen(n+1,chess);   /*�������������ռ���*/
			chess[i][n]=0;
		}
	}
}
main()
{
	int chess[8][8],i,j;
	for (i=0;i<8;i++)				/*��ʼ����������*/
	{
		for(j=0;j<8;j++)
			chess[i][j]=0;
	}
	eightqueen(0,chess);			/*ִ�а˻ʺ���⺯��*/
	printf("The number of the answer for eightqueen is: %d",count);
	getch();	
}

