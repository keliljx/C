#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n=11,spare,num;
    float share1=1,share2=2;
    while(share1!=share2)
    {
         n++;
         share1=(n+9)/10.0;
         share2=(9*n+171)/100.0;
         if(share1!=(int)share1)     continue;
         if(share2!=(int)share2)     continue;                      
    }
    printf("\n\t��������%d�����ӣ����Ʊ��ֳ���%d��\n\n",(int)(n/share1),n);
    num=1;
    while(n!=0)
    {
        spare=n-num;
        printf("��%d�����ӣ��ȵ�%d�ݲ���ٵ�ʣ���%2d�ݵ�1/10:%d�ݣ�\
        ����%d��\n",num,num,spare,spare/10,num+spare/10);  
        n=spare-spare/10;
        num++;         
    }
  system("PAUSE");	
  return 0;
}
