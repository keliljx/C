#include <stdio.h>
#include <stdlib.h>
#define N 10
int find_Max_Min(int a[],int n) {
/* �ҳ�n��Ԫ�ص�����a�е����Ԫ�ء���СԪ�ز���������ز��ҹ�����Ԫ�صıȽϴ���*/
    int i,j,z,Count = 0;
    int temp,Maxnum,Minnum;
    for(i=0;i<n-1;i++){
        z=i;
        for(j=i+1;j<n;j++){
        Count = Count + 1;/*Ԫ�رȽϴ�������*/
        if(a[z]>a[j])
        {
            z=j;                
        }
            }
        if(z!=j){
                 temp=a[z];a[z]=a[i];a[i]=temp;
                 }
        
    }
    Maxnum=a[n-1];
    Minnum=a[0];
    printf("������������ֵ��Max=%d\n",Maxnum);
    printf("�����������Сֵ��Min=%d\n",Minnum); 
    return Count;
}

int main()
{ 
    int a[10],x,k;
    printf("������һ��10��Ԫ�ص����飺\n");
    for(k=0;k<N;k++){
          scanf("%d",&a[k]);
    }
    x=find_Max_Min(a,N);
    printf("�ڲ���ʱ�ȽϵĴ����ǣ�Count=%d\n",x);
    system("PAUSE");
    return 0;
}
