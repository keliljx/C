#include <stdio.h>
#include <stdlib.h>
	void move(char x,char y){
	printf("%c-->%c",x,y);
	printf("\n");
	}
	/*��n�����Ӵӵ�һ�������ڶ����Ƶ�������*/
	void hanoit(int n,char one,char two,char three){
	if(n==1){                                /*���ֻ��һ������*/
			move(one,three);
	}
	else{
			hanoit(n-1,one,three,two);      /*��һ�ϵ����ӽ������Ƶ�����*/
			move(one,three);
			hanoit(n-1,two,one,three);      /*�����ϵ����ӽ���һ�Ƶ�����*/
	}
	}	
int main()
{
    int m;
	printf("��������Ҫ�ƶ�����������");
	scanf("%d",&m);
	printf("�ƶ�%d�����ӵĲ�������",m);
	hanoit(m,'A','B','C');
    system("PAUSE");	
    return 0;
}
