#include<stdio.h>
#define max 100
quan(int a[],int n,int s,int r[],int m)
{
	int i,j,k,flag=0;
	int b[max];
	for(i=0;i<n;i++)
	{
		flag=1;
		r[s]=a[i];					/*固定不动的数字*/
		j=0;
		for(k=0;k<n;k++)			/*调换位置，将待排序的数列赋给b子序列*/
			if(i!=k)
			{
				b[j]=a[k];
				j++;
			}
		quan(b,n-1,s+1,r,m);		/*递归调用全排列函数*/		
	}
	if(flag==0)						/*得到一种排序结果*/
	{
		for(k=0;k<m;k++)			
			printf("%d ",r[k]);		/*输出存放排列结果的数组r中的内容*/
		printf("\n");
	}
}
main()
{
	int a[max],r[max];
	int i,n;
	printf("输入元素个数：");
	scanf("%d",&n);
	printf("请输入一组数字序列！\n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	printf("该数列有如下排列方式：\n");
	quan(a,n,0,r,n);				/*调用全排列*/
	getche();
}