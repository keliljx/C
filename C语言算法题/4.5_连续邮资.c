#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h> 
#define MAXINT INT_MAX-1 
#define VALUE_LIMIT 1500 
    int n,m;                        /*n:��Ʊ������,m:��Ʊ���������*/
    int maxv;                        /*��ǰ������ֵ*/
    int *x;                            /*��ǰ������*/
    int y[VALUE_LIMIT+1];     /*����������������Ҫ��������Ʊ��*/
    int *bestx;                        /*��ǰ���Ž�*/

void backtrack(int i,int r);

int max_stamp() 
{ 
    int i; 
     x=(int *)malloc(sizeof(int)*(n+1));              /*��������������Ŀռ�*/
     bestx=(int*)malloc(sizeof(int)*(n+1));           /*�����Ž�����������Ŀռ�*/
     maxv=0;                            /*��ʼ������ֵΪ0*/
    
    for(i=0;i<=n;i++)                    /*��ʼ����Ʊ��ֵ��Ϊ0*/
         x[i]=bestx[i]=0; 
    
    for(i=1;i<=VALUE_LIMIT;i++)                 /*��ʼ������������Ҫ��Ʊ��Ϊ�����*/
         y[i]=MAXINT; 
     x[1]=1;                                                    /*ֻ��һ����ֵʱ,����ֻ��Ϊ1*/
     y[0]=0;                                               /*���ʲ�����ʱ,����ƱҲ���ܴ���*/
     backtrack(2,1);                        /*�ӽ�ռ����ĵڶ����������,��ʱ��������r=1*/
    return maxv; 
} 

void backtrack(int i,int r) 
{ 
    int j,k;                        /*j��ʾ�����������ʱ����*/
    int t[VALUE_LIMIT+1];                     
    for(j=0;j<=x[i-2]*(m-1);j++)
    { 
        if(y[j]<m){ 
            for(k=1;k<=m-y[j];k++) 
            { 
                if(y[j]+k<y[j+x[i-1]*k]) 
                     y[j+x[i-1]*k]=y[j]+k; 
             } 
         } 
     } 
    
    while(y[r]<MAXINT)                    /*rΪ�����Ͻ�,��������Ʊ��MAXINT������������Ͻ�*/
         r++; 
    
    if(i>n){                        /*���������Ҷ�ӽڵ�,������Ӧ����������ֵΪr-1*/
        if(r-1>maxv){ 
             maxv=r-1; 
            for(j=1;j<=n;j++) 
                bestx[j]=x[j];            /*����x[i]Ϊ���Ž�*/
         } 
        return; 
     } 
    
    for(k=1;k<=VALUE_LIMIT;k++) 
         t[k]=y[k];                    
    for(j=x[i-1]+1;j<=r;j++) 
    { 
        if(y[r-j]<m)
        {
             x[i]=j;                    /*���¼��ؼ���x[i]��ֵ*/
             backtrack(i+1,r+1);            /*�ݹ���ݣ����ǰi����Ʊ���ܴﵽ�������������1~r-1*/
            for(k=1;k<=VALUE_LIMIT;k++) 
                 y[k]=t[k];                
         }
     } 
    
} 

int main(void) 
{ 
    int i;
     printf("*****************************************************************\n ");
     printf("* ������������ * \n");
     printf("*****************************************************************\n ");

     printf("��������Ʊ��������ÿ���ŷ��������������Ʊ���� ");
    while(scanf("%d%d",&n,&m)!=EOF)
  { 
        if(n<=0&&m<=0) break; 
         printf("��������Ͻ���:%d ",max_stamp());
         printf("\n");
         printf("����Ʊ��ֵ�ֱ���: ");
        for(i=1;i<=n;i++)
     {
             printf("%d ",bestx[i]);
         }
         printf("\n");
         printf("\n");
         printf("���ٴ�������Ʊ����������Ʊ�����ֵ�� ");
     } 
    
    return 0; 
}


