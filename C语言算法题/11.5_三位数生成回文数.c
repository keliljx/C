#include <stdio.h>
#include <stdlib.h>

int isPalm(long m)
{ /*判断m是否为回文数*/
    int i = 0, k = 0;
    char str[32];
    while(m>0) {		 /*从个位数开始逐个取出m的各位数字并存入字符数组str*/
         str[k++]= m%10+ '0';
         m = m/10;
    }
    for(i=0;i<k/2;i++){	 /*判断str中的k个数字字符序列是否是回文*/
        if (str[i]!= str[k-i-1]) 
        return 0;
        return 1;
    }
}
int main()
{
     long n, a, t;
     printf("请输入一个少于1000的三位整数:\n"); 
     scanf("%ld",&n);
     if(n < 100||n>=1000) return -1 ;
     printf("生成回文数的过程如下：\n");
     while(!isPalm(n)) {		 /*n不是回文数时执行循环*/
         printf("%ld -> ", n);
         for(a=0,t=n;t>0;){		/*计算n的反序数并存入a*/
                 a=a*10+t%10;
                 t=t/10;
         } 
         n=n+a;				 /*与反序数求和*/
     } 
     printf("%ld\n",n);
     system("PAUSE");
     return 0;
}
