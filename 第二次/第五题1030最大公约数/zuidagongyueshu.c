/*
շת�����
*/
#include<stdio.h>
int main()
{
 int a,b,temper;
 scanf("%d %d",&a,&b);
 while(b)
 {
  temper=a%b; a=b; b=temper;//շת��������ô�����С��ȡ��
                            //�����͵�ǰ����С���ٴ�շת���
 }
 printf("%d\n",a);
 return 0;
}
