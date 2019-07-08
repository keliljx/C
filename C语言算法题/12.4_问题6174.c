int num[2000],count;
 main()
{
	printf("输入一个整数：\n");
	scanf("%d",&num[0]);
	printf("%d",num[0]);
	count=1;
	while(1)
	{int i;int f=0;
		num[count]=next(num[count-1]);/*对num[count=1]排序，计算得到下一个值*/
		printf("->%d",num[count]);/*输出下一个值*/		
		for(i=0;i<count;i++)
			if(num[i]==num[count])/*从第0个开始比较，看是否有相同的数字*/
			{
				f=1;break;/*发现相同的，f=1*/
			}
			if(f)/*若发现跳出循环*/
				break;
			count++;
	}
	printf("\n");

}
int next(int x)
{
	int a,b,n,i,j;
	char s[10];
	sprintf(s,"%d",x);/*将整数转换成字符串*/
	n=strlen(s);		/*字符串长度*/
	for(i=0;i<n;i++)	/*冒泡排序*/
		for(j=i+1;j<n;j++)
			if(s[i]>s[j])
			{
				char t=s[i];s[i]=s[j];s[j]=t;
			}
			sscanf(s,"%d",&b);/*将字符串s转换成整数b*/
			for(i=0;i<n/2;i++)/*反转字符串*/
			{
				char t=s[i];
				s[i]=s[n-1-i];
				s[n-1-i]=t;
			}
			sscanf(s,"%d",&a);/*将此字符串转换成整数a*/
			return a-b;/*返回差值，即下一个数*/
} 