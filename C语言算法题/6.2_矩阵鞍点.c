#include <stdio.h>
#include <stdlib.h>
int seachPoint(int *x,int *y,int (*A)[5],int m,int n)
{
    int max,i,j,k,flag;
    for(i=0;i<m;i++)
    {
        max=0;
        flag=1;
        /*找寻一列中最大的*/
        for(j=1;j<n;j++)
        {
            if(A[i][j]>A[i][max])    max=j;                
        } 
        /*判断是否有多个重复最大值*/ 
        for(k=0;k<n;k++)
        {
            if(A[i][max]==A[i][k] && max!=k)
            {
                 flag=0;
                 break;                      
            }                
        }   
        /*判断列中的最大值*/      
        if(flag==1)
        {
            for(k=0;k<m;k++)
            {
                if(A[k][max]<=A[i][max] && k!=i)
                {
                     flag=0;
                     break;                        
                }                
            }           
        }
        if(flag==1)
        {
            *x=i;
            *y=max;
            return 1;
        }
    }    
    return 0;
}
int main()
{
    int A[5][5],i,j,x,y;
    printf("请输入一个5*5的矩阵\n");
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            scanf("%d",&A[i][j]);                
        }                
    }
    if(seachPoint(&x,&y,A,5,5))
    {
         printf("\n鞍点的位置是(%d,%d):",x+1,y+1);                           
    }
    else
    {
         printf("\n本矩阵没有鞍点！");    
    }
  
    system("PAUSE");	
    return 0;
}
