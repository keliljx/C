#include <stdio.h>
#include <stdlib.h> 
int n;
char s[17];
void DFS(int i)
{	
if(i==n) printf("%s\n",s); /*����ײ������*/
else
{
DFS(i+1);					/*�����������*/
if(s[i]=='0') 
s[i]='1';
else 
s[i]='0';				/*�ѵ�ǰλ��ת*/
DFS(i+1);					/*������������*/
}
} 
main()
{
	int i;
	while(1)
	{
		printf("����Ҫ��ʾ�ĸ�����Ķ�����λ��:");
		scanf("%d",&n);
		if(!n)
			break;				/*��0���˳�*/
		for(i=0;i<17;i++) 
			s[i]='0';
		s[n]='\0';
		DFS(0);
		printf("\n");
	}
}
