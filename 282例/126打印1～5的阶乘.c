#include <stdio.h>
int fac(int num)
{
	static int result=1;								/*����ֲ���̬����*/
	result=result*num;								/*���м���*/
	return(result);									/*���ؽ��*/
}
main()
{ 
	int i, n;										/*��������*/
	for(i=1;i<=5;i++)								/*ѭ���õ�1��5�Ľ׳�ֵ*/
	{
		n=fac(i);									/*�����Զ��庯����׳�*/
		printf("%d!=%d\n",i,n);						/*������*/
	}
	return 0;
}
