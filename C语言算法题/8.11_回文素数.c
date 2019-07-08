main()
{
	long i;int k=0;
	for(i=10;i<=1000;i++)	/*遍历10到1000内的整数*/
	{
		if(is(i))			/*判断是否为回文数*/
		{
			if(pri(i))		/*判断是否为素数*/
			{k++;			/*累加记录回文式素数的个数*/
			printf("%d\t\t",i);/*输出素数*/
			}
		}
	}
	printf("\n总共有%d个回文式素数！\n",k);
}
long is(long n)				/*判断是否为回文数*/
{
	long m;
	m=re(n);								
	if(m==n)				/*判断两数是否相等*/
		return 1;			/*若相等，返回1，*/
	else return 0;
}
long re(long i)				/*将余数相加得出j*/
{
	long m,j=0;
	m=i;
	while(m)
	{
		j=j*10+m%10;
		m=m/10;
	}
	return j;				/*返回j*/
}
long pri(long m)			/*判断素数*/
{long i;
	for(i=2;i<=m-1;i++)
	{
	
		if(m%i==0)
			goto h1;
		else continue;
	}
	return 1;
h1:	return 0;
}