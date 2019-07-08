#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>
double rnd(int x)
{
 FILE *fp;
 static double a=262147.0,t,i,b=34359738365.0/549755813888.0;
 if(x==1)					/*得到一个新的随机数*/
 b=b*a-(long)(b*a);
 else if(x==2);				/*重复上一个随机数，使函数值返回原b值*/
 else
 {



   if((fp=fopen("rnd","rb+"))==NULL)
   {
    printf("cannot open this file\n");
    exit(0);
   }
   if(x==-1)				/*从磁盘文件rnd中读取上次的随机数，计算新的随机数*/
	   fread(&b,8,1,fp);
   else						/*x==0时，向磁盘文件中写入最后一次的随机数*/
   {
    rewind(fp);				/*使位置指针重新返回文件的开头*/
	fwrite(&b,8,1,fp);
   }
 }
 return(b);
}
main()
{
	long i,n=0,n1=0,n2=0;
	rnd(-1);				/*从磁盘文件中读取上次的随机数*/
	for(i=1;i<=100000;i++)	/*实验100000次*/
	{
		if(rnd(1)>0.6)		/*每次抽取一个随机数*/
		{
			n++;
			if(rnd(2)<0.7)	/*重复上一个随机数*/
				n1++;
			else 
				n2++;
		}
	}
	printf("警察在火车车厢内找到犯人的概率为%.3f\n犯人不在车厢的概率为%.3f\n\n",1.0*n1/n,1.0*n2/n);
	rnd(0);					/*将最后的随机数存入文件rnd中*/
}