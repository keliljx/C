#include<stdio.h>
paixu(int f[])
{
	int i,j,t;
	for(i=0;i<7;i++)			/*冒泡排序*/
		for(j=0;j<7-i;j++)
			if(f[j]>=f[j+1])	/*相邻数字比较*/
			{
				t=f[j];			/*交换*/
				f[j]=f[j+1];
				f[j+1]=t;
				printf("*%d-->*0\t",j+1);/*输出移动步骤*/
				printf("*%d-->*%d\t",j+2,j+1);
				printf("*0-->*%d\t",j+2);
			}
			printf("\n");
} 
show(int a[])
{/*显示九宫格*/

	printf("%d--%d--%d\n",a[0],a[1],a[2]);
	printf("|%c | %c|\n",92,47);
	printf("%d--#--%d\n",a[7],a[3]);
	printf("|%c | %c|\n",47,92);
	printf("%d--%d--%d\n",a[6],a[5],a[4]);
}
main()
{
	int i,m[8];
	printf("请任意顺序输入8个整数（1~8）\n");
	for(i=0;i<8;i++)
		scanf("%d",&m[i]);
	printf("这初始数据矩阵为：\n");
	show(m);
	printf("\n移动步骤：\n");
	paixu(m);
	printf("最终移动结果是\n");
	show(m);
	getche();
}