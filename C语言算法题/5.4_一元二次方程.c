#include<string.h>
#include<math.h>
long temp,n;
long zdgys(long a,long b)			/*�����Լ��*/
{
	if(a<0)
		a=-a;
	if(b<0)
		b=-b;
	if(a<b)					/*aʼ��Ϊ���*/
	{
		temp=a;
		a=b;
		b=temp;
	}
	if(b==0)
		return a;
	while(a%b!=0)			/*ȡ�࣬շת������õ�bΪ���Լ��*/
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
	return m*n/zdgys(m,n);		/*������˳������Լ��Ϊ��С������*/
}
void yuefen(long *y,long *f)	/*Լ�ֻ���*/
{
	temp=zdgys(*y,*f);
	*y/=temp;
	*f/=temp;
}
void xshubfshu(char *p,long *fz,long *fm)		/*��ϵ��Ϊ������ʽ*/
{
	char w1[11],w2[11],*p1=w1,*p2=w2;
	p1=strchr(p,'/');				/*�ַ����в��ҡ�/��*/
	if(p1!=0)						/*�ҵ���/��,pΪ������p1����*/
	{
		*p1='\0';*fz=atol(p);		/*ȡ��/��ǰ�����Ϊ����*/
		strcpy(p2,++p1);			/*ȡ��/���������Ϊ��ĸ*/
		*fm=atol(p2);
	}
	else 
	{
		p1=strchr(p,'.');			/*�ַ������ҡ�.��*/
		if(p1!=0)					/*�ҵ�.ΪС����p1��Ϊ��*/
		{
			*p1='\0';/*ԭ.���á�\0��*/
			p2=++p1;				
			n=strlen(p2);			/*nΪ.���λ��*/
			strcat(p,p2);
			*fz=atol(p);*fm=pow(10,n);
		}
		else
		{
			*fz=atol(p);
			*fm=1;
		}
	}
	yuefen(fz,fm);						/*Լ�ֻ���*/

}
main()
{
	char a[11],b[11],c[11],*pa=a,*pb=b,*pc=c;/*��ϵ��������10���ַ�*/
	long a1,a2,b1,b2,c1,c2,f1,f2,*fz=&f1,*fm=&f2,zxgb,zdgy,d,s1,s2,s3,e,k;
	printf("*******************************************************\n\n\n");
	printf("������һԪ���η���ϵ��a b c��");
	scanf("%s%s%s",pa,pb,pc);
	printf("\n��ⷽ��Ϊ��%sX^2+%sX+%s=0\n",pa,pb,pc);
	xshubfshu(pa,fz,fm);					/*����ϵ��ȫ����ɷ��ӷ�ĸ��ʽ*/
	a1=*fz;a2=*fm;
	xshubfshu(pb,fz,fm);
	b1=*fz;b2=*fm;
	xshubfshu(pc,fz,fm);
	c1=*fz;c2=*fm;
	if(a1<0)							/*������ϵ��Ӧ����0*/
	{
		a1=-a1;
		b1=-b1;
		c1=-c1;
	}
	zxgb=zxgbs(zxgbs(a2,b2),c2);				/*���ĸ����С������*/
	a1=a1*zxgb/a2;						/*ȥ��ĸ��Ϊ��ϵ������*/
	b1=b1*zxgb/b2;
	c1=c1*zxgb/c2;
	printf("\n���̿�����ã�");
	if(a1!=1)printf("%ld",a1);
	printf("X^2");
	if(b1>0)printf("+%ldX",b1);
	else if(b1<0)printf("%ldX",b1);
	if(c1>0)printf("+%ld=0\n",c1);
	else if(c1<0)printf("%ld=0\n",c1);
	else printf("=0\n");
	d=b1*b1-4*a1*c1;					/*�б�ʽ*/
	s1=-b1;s2=2*a1;s3=s2;
	yuefen(&s1,&s2);
	if(d==0)
	{
		printf("\n���������ʵ����x1=x2=%ld",s1);
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
				printf("\n�����в���ʵ����x=");
					if(s1!=0)printf("%ld",s1);
					if(s1!=0&&s2!=1)
						printf("/%ld",s2);
					printf("��");
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
			printf("\n�����ж�������x=");
			if(s1!=0)printf("%ld",s1);
			if(s1!=0&&s2!=1)
				printf("/%ld",s2);
			printf("��");
			if(k!=1)printf("%ld",k);
			if(e!=1)printf("sqrt(%ld)",e);
			printf("i");
			if(s3!=1)printf("/%ld\n",s3);
		}
	}
printf("\n\n\n*******************************************************\n");
}