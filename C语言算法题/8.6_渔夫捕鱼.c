int all(int i,int n)/*递推求出总共至少有多少条鱼*/
{
	int s=i;		/*初始值*/
	while(n)		/*递推次数*/
	{
		s=5*s+1;	/*递推公式*/
		n--;
	}
	return s;
}
main()
{
	int sum;
	sum=all(6,4);	/*鱼的总共条数*/
	printf("五个渔夫至少合伙捕了%d条鱼！\n",sum);	
}