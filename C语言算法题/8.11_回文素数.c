main()
{
	long i;int k=0;
	for(i=10;i<=1000;i++)	/*����10��1000�ڵ�����*/
	{
		if(is(i))			/*�ж��Ƿ�Ϊ������*/
		{
			if(pri(i))		/*�ж��Ƿ�Ϊ����*/
			{k++;			/*�ۼӼ�¼����ʽ�����ĸ���*/
			printf("%d\t\t",i);/*�������*/
			}
		}
	}
	printf("\n�ܹ���%d������ʽ������\n",k);
}
long is(long n)				/*�ж��Ƿ�Ϊ������*/
{
	long m;
	m=re(n);								
	if(m==n)				/*�ж������Ƿ����*/
		return 1;			/*����ȣ�����1��*/
	else return 0;
}
long re(long i)				/*��������ӵó�j*/
{
	long m,j=0;
	m=i;
	while(m)
	{
		j=j*10+m%10;
		m=m/10;
	}
	return j;				/*����j*/
}
long pri(long m)			/*�ж�����*/
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