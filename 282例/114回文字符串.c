#include<stdio.h>
int palind(char str[],int k,  int i)							/*�Զ��庯������Ƿ�Ϊ�����ַ���*/
{
	if(str[k]==str[i-k]&&k==0)							/*�ݹ��������*/
		return 1;
	else if(str[k]==str[i-k])								/*�ж����Ӧ�������ַ��Ƿ����*/
		palind(str,k-1,i);   							/*�ݹ����*/
	else
		return 0;
}
main()
{
	int i=0,n=0;										/*i��¼�ַ�������n�Ǻ�������ֵ*/
	char ch,str[20];
	while ((ch=getchar())!='\n')
	{
		str[i]=ch;
		i++;
	}
	if(i%2==0)										/*���ַ������ַ�����Ϊż��ʱ*/
	{
		n=palind(str,(i/2),i-1);
	}
	else
	{
		n=palind(str,(i/2-1),i-1);							/*���ַ������ַ�����Ϊ����ʱ*/
	}
	if(n==0)
	{
		printf("not palindrome");						/*��nΪ0˵�����ǻ������������ǻ�����*/
	}
	else
	{
		printf("palindrome\n");
	}
	getch();
	return 0;
}
