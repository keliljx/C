#include<string.h>
#include<math.h>
long temp,n;
long zdgys(long a,long b)			/*求最大公约数*/
{
	if(a<0)
		a=-a;
	if(b<0)
		b=-b;
	if(a<b)					/*a始终为最大*/
	{
		temp=a;
		a=b;
		b=temp;
	}
	if(b==0)
		return a;
	while(a%b!=0)			/*取余，辗转相除，得到b为最大公约数*/
	{
		temp=a%b;
		a=b;
		b=temp;
	}
	return b;
}
long zxgbs(long m,long n)
{
	if(n==0)
		return m;
	return m*n/zdgys(m,n);		/*两数相乘除以最大公约数为最小公倍数*/
}
void yuefen(long *y,long *f)	/*约分化简*/
{
	temp=zdgys(*y,*f);
	*y/=temp;
	*f/=temp;
}
void xshubfshu(char *p,long *fz,long *fm)		/*变系数为分数形式*/
{
	char w1[11],w2[11],*p1=w1,*p2=w2;
	p1=strchr(p,'/');				/*字符串中查找‘/’*/
	if(p1!=0)						/*找到‘/’,p为分数，p1不空*/
	{
		*p1='\0';*fz=atol(p);		/*取‘/’前面的数为分子*/
		strcpy(p2,++p1);			/*取‘/’后面的数为分母*/
		*fm=atol(p2);
	}
	else 
	{
		p1=strchr(p,'.');			/*字符串中找‘.’*/
		if(p1!=0)					/*找到.为小数，p1不为空*/
		{
			*p1='\0';/*原.处置‘\0’*/
			p2=++p1;				
			n=strlen(p2);			/*n为.后的位数*/
			strcat(p,p2);
			*fz=atol(p);*fm=pow(10,n);
		}
		else
		{
			*fz=atol(p);
			*fm=1;
		}
	}
	yuefen(fz,fm);						/*约分化简*/

}
main()
{
	char a[11],b[11],c[11],*pa=a,*pb=b,*pc=c;/*设系数不超过10个字符*/
	long a1,a2,b1,b2,c1,c2,f1,f2,*fz=&f1,*fm=&f2,zxgb,zdgy,d,s1,s2,s3,e,k;
	printf("*******************************************************\n\n\n");
	printf("请输入一元二次方程系数a b c：");
	scanf("%s%s%s",pa,pb,pc);
	printf("\n求解方程为：%sX^2+%sX+%s=0\n",pa,pb,pc);
	xshubfshu(pa,fz,fm);					/*三个系数全部变成分子分母形式*/
	a1=*fz;a2=*fm;
	xshubfshu(pb,fz,fm);
	b1=*fz;b2=*fm;
	xshubfshu(pc,fz,fm);
	c1=*fz;c2=*fm;
	if(a1<0)							/*二次项系数应大于0*/
	{
		a1=-a1;
		b1=-b1;
		c1=-c1;
	}
	zxgb=zxgbs(zxgbs(a2,b2),c2);				/*求分母的最小公倍数*/
	a1=a1*zxgb/a2;						/*去分母变为整系数方程*/
	b1=b1*zxgb/b2;
	c1=c1*zxgb/c2;
	printf("\n方程可整理得：");
	if(a1!=1)printf("%ld",a1);
	printf("X^2");
	if(b1>0)printf("+%ldX",b1);
	else if(b1<0)printf("%ldX",b1);
	if(c1>0)printf("+%ld=0\n",c1);
	else if(c1<0)printf("%ld=0\n",c1);
	else printf("=0\n");
	d=b1*b1-4*a1*c1;					/*判别式*/
	s1=-b1;s2=2*a1;s3=s2;
	yuefen(&s1,&s2);
	if(d==0)
	{
		printf("\n方程有相等实根：x1=x2=%ld",s1);
		if(s2!=1)printf("/%ld\n",s2);
	}
	else
	{
		e=fabs(d);k=sqrt(e);
		while(e%(k*k)!=0)k--;
		e=e/(k*k);
		yuefen(&k,&s3);
		if(d>0)
		{
			if(e!=1)
			{
				printf("\n方程有不等实根：x=");
					if(s1!=0)printf("%ld",s1);
					if(s1!=0&&s2!=1)
						printf("/%ld",s2);
					printf("±");
					if(k!=1)printf("%ld",k);
					printf("sqrt(%ld)",e);
					if(s3!=1)printf("/%ld\n",s3);
			}
			else
			{
				a2=s1*s3+s2*k;
				b2=s2*s3;yuefen(&a2,&b2);
				printf("x1=%ld",a2);
				if(b2!=1)printf("/%ld",b2);
				a2=s1*s3-s2*k;b2=s2*s3;yuefen(&a2,&b2);
				printf("\tx2=%ld",a2);
				if(b2!=1)printf("/%ld\n",b2);
			}
		}
		else
		{
			yuefen(&k,&s3);
			printf("\n方程有二复根：x=");
			if(s1!=0)printf("%ld",s1);
			if(s1!=0&&s2!=1)
				printf("/%ld",s2);
			printf("±");
			if(k!=1)printf("%ld",k);
			if(e!=1)printf("sqrt(%ld)",e);
			printf("i");
			if(s3!=1)printf("/%ld\n",s3);
		}
	}
printf("\n\n\n*******************************************************\n");
}