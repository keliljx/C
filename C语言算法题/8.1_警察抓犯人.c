#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>
double rnd(int x)
{
 FILE *fp;
 static double a=262147.0,t,i,b=34359738365.0/549755813888.0;
 if(x==1)					/*�õ�һ���µ������*/
 b=b*a-(long)(b*a);
 else if(x==2);				/*�ظ���һ���������ʹ����ֵ����ԭbֵ*/
 else
 {



   if((fp=fopen("rnd","rb+"))==NULL)
   {
    printf("cannot open this file\n");
    exit(0);
   }
   if(x==-1)				/*�Ӵ����ļ�rnd�ж�ȡ�ϴε�������������µ������*/
	   fread(&b,8,1,fp);
   else						/*x==0ʱ��������ļ���д�����һ�ε������*/
   {
    rewind(fp);				/*ʹλ��ָ�����·����ļ��Ŀ�ͷ*/
	fwrite(&b,8,1,fp);
   }
 }
 return(b);
}
main()
{
	long i,n=0,n1=0,n2=0;
	rnd(-1);				/*�Ӵ����ļ��ж�ȡ�ϴε������*/
	for(i=1;i<=100000;i++)	/*ʵ��100000��*/
	{
		if(rnd(1)>0.6)		/*ÿ�γ�ȡһ�������*/
		{
			n++;
			if(rnd(2)<0.7)	/*�ظ���һ�������*/
				n1++;
			else 
				n2++;
		}
	}
	printf("�����ڻ𳵳������ҵ����˵ĸ���Ϊ%.3f\n���˲��ڳ���ĸ���Ϊ%.3f\n\n",1.0*n1/n,1.0*n2/n);
	rnd(0);					/*����������������ļ�rnd��*/
}