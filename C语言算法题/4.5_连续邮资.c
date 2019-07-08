#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h> 
#define MAXINT INT_MAX-1 
#define VALUE_LIMIT 1500 
    int n,m;                        /*n:邮票的种数,m:邮票的最大数量*/
    int maxv;                        /*当前的最优值*/
    int *x;                            /*当前解数组*/
    int y[VALUE_LIMIT+1];     /*贴出各种邮资所需要的最少邮票数*/
    int *bestx;                        /*当前最优解*/

void backtrack(int i,int r);

int max_stamp() 
{ 
    int i; 
     x=(int *)malloc(sizeof(int)*(n+1));              /*给解数组分配具体的空间*/
     bestx=(int*)malloc(sizeof(int)*(n+1));           /*给最优解数组分配具体的空间*/
     maxv=0;                            /*初始化最优值为0*/
    
    for(i=0;i<=n;i++)                    /*初始化邮票面值都为0*/
         x[i]=bestx[i]=0; 
    
    for(i=1;i<=VALUE_LIMIT;i++)                 /*初始化贴出邮资需要邮票数为无穷大*/
         y[i]=MAXINT; 
     x[1]=1;                                                    /*只有一种面值时,邮资只能为1*/
     y[0]=0;                                               /*邮资不存在时,则邮票也不能存在*/
     backtrack(2,1);                        /*从解空间树的第二层进行搜索,此时邮资上限r=1*/
    return maxv; 
} 

void backtrack(int i,int r) 
{ 
    int j,k;                        /*j表示邮资区间的暂时上限*/
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
    
    while(y[r]<MAXINT)                    /*r为邮资上界,这里用邮票数MAXINT构建最大邮资上界*/
         r++; 
    
    if(i>n){                        /*如果搜索到叶子节点,更新相应的邮资最优值为r-1*/
        if(r-1>maxv){ 
             maxv=r-1; 
            for(j=1;j<=n;j++) 
                bestx[j]=x[j];            /*更新x[i]为最优解*/
         } 
        return; 
     } 
    
    for(k=1;k<=VALUE_LIMIT;k++) 
         t[k]=y[k];                    
    for(j=x[i-1]+1;j<=r;j++) 
    { 
        if(y[r-j]<m)
        {
             x[i]=j;                    /*更新几素计算x[i]的值*/
             backtrack(i+1,r+1);            /*递归回溯，求出前i种邮票所能达到的最大连续区间1~r-1*/
            for(k=1;k<=VALUE_LIMIT;k++) 
                 y[k]=t[k];                
         }
     } 
    
} 

int main(void) 
{ 
    int i;
     printf("*****************************************************************\n ");
     printf("* 连续邮资问题 * \n");
     printf("*****************************************************************\n ");

     printf("请输入邮票的种数和每个信封最多允许贴的有票数： ");
    while(scanf("%d%d",&n,&m)!=EOF)
  { 
        if(n<=0&&m<=0) break; 
         printf("最大邮资上界是:%d ",max_stamp());
         printf("\n");
         printf("各邮票面值分别是: ");
        for(i=1;i<=n;i++)
     {
             printf("%d ",bestx[i]);
         }
         printf("\n");
         printf("\n");
         printf("请再次输入邮票的种数和邮票最大面值： ");
     } 
    
    return 0; 
}


