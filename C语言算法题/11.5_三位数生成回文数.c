#include <stdio.h>
#include <stdlib.h>

int isPalm(long m)
{ /*�ж�m�Ƿ�Ϊ������*/
    int i = 0, k = 0;
    char str[32];
    while(m>0) {		 /*�Ӹ�λ����ʼ���ȡ��m�ĸ�λ���ֲ������ַ�����str*/
         str[k++]= m%10+ '0';
         m = m/10;
    }
    for(i=0;i<k/2;i++){	 /*�ж�str�е�k�������ַ������Ƿ��ǻ���*/
        if (str[i]!= str[k-i-1]) 
        return 0;
        return 1;
    }
}
int main()
{
     long n, a, t;
     printf("������һ������1000����λ����:\n"); 
     scanf("%ld",&n);
     if(n < 100||n>=1000) return -1 ;
     printf("���ɻ������Ĺ������£�\n");
     while(!isPalm(n)) {		 /*n���ǻ�����ʱִ��ѭ��*/
         printf("%ld -> ", n);
         for(a=0,t=n;t>0;){		/*����n�ķ�����������a*/
                 a=a*10+t%10;
                 t=t/10;
         } 
         n=n+a;				 /*�뷴�������*/
     } 
     printf("%ld\n",n);
     system("PAUSE");
     return 0;
}
