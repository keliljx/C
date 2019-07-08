#include<stdio.h>
#include<math.h>
main()
{
	int i;
	double s=0;
	for(i=1;i<=64;i++)		/*64个格子*/
		s+=pow(2,i-1);		/*累加2的0次方到2的i-1次方*/
	printf("舍罕王的计算结果是\n%lf\n粒麦子！\n",s);
}