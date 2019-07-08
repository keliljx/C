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
    printf("\n\t国王共有%d个王子，将财宝分成了%d份\n\n",(int)(n/share1),n);
    num=1;
    while(n!=0)
    {
        spare=n-num;
        printf("第%d个王子，先得%d份财物，再得剩余的%2d份的1/10:%d份，\
        共得%d份\n",num,num,spare,spare/10,num+spare/10);  
        n=spare-spare/10;
        num++;         
    }
  system("PAUSE");	
  return 0;
}
