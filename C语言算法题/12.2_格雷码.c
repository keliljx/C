#include <stdio.h>
#include <stdlib.h> 
int n;
char s[17];
void DFS(int i)
{	
if(i==n) printf("%s\n",s); /*到达底部就输出*/
else
{
DFS(i+1);					/*深度优先搜索*/
if(s[i]=='0') 
s[i]='1';
else 
s[i]='0';				/*把当前位逆转*/
DFS(i+1);					/*继续向下搜索*/
}
} 
main()
{
	int i;
	while(1)
	{
		printf("输入要显示的格雷码的二进制位数:");
		scanf("%d",&n);
		if(!n)
			break;				/*是0就退出*/
		for(i=0;i<17;i++) 
			s[i]='0';
		s[n]='\0';
		DFS(0);
		printf("\n");
	}
}
