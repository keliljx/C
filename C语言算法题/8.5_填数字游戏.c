int r(int m)		/*获取四位数的倒置数即由1234得出4321*/
{
	int r=0;
	while(m)
	{
		r=r*10+m%10;
		m/=10;
	}
	return r;
}
int is(int m,int n)/*判断四位数的各个位以及n是否各不相等*/
{
	int a,b,c,d;
	a=m%10;			/*求出个位数*/
	b=m%100/10;		/*求出十位数*/
	c=m%1000/100;	/*求出百位数*/
	d=m/1000;		/*求出千位数*/
	if(a!=b&&a!=c&&a!=d&&a!=n&&b!=c&&b!=d&&b!=n&&c!=d&&c!=n&&d!=n)
		return 1;	/*不相等返回1*/
	return 0;

}
main()
{
int m,n,k;
for(m=1000;m<=9999;m++)/*四位数的范围*/
for(n=1;n<=9;n++)/*一位数的范围*/
{
	k=r(m);
	if(n*m==k&&is(m,n))/*判断m与n相乘是否等于倒置数及各个位数是否相等*/
		printf("ABCD=%d,E=%d\n",m,n);
}
}