#include<stdio.h>
#include<math.h>
main()
{
	int i;
	double s=0;
	for(i=1;i<=64;i++)		/*64������*/
		s+=pow(2,i-1);		/*�ۼ�2��0�η���2��i-1�η�*/
	printf("�ằ���ļ�������\n%lf\n�����ӣ�\n",s);
}