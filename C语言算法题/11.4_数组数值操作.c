#include <stdio.h>
#include <stdlib.h>
#define N 10
int find_Max_Min(int a[],int n) {
/* 找出n个元素的数组a中的最大元素、最小元素并输出，返回查找过程中元素的比较次数*/
    int i,j,z,Count = 0;
    int temp,Maxnum,Minnum;
    for(i=0;i<n-1;i++){
        z=i;
        for(j=i+1;j<n;j++){
        Count = Count + 1;/*元素比较次数计数*/
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
    printf("输入数组的最大值是Max=%d\n",Maxnum);
    printf("输入数组的最小值是Min=%d\n",Minnum); 
    return Count;
}

int main()
{ 
    int a[10],x,k;
    printf("请输入一个10个元素的数组：\n");
    for(k=0;k<N;k++){
          scanf("%d",&a[k]);
    }
    x=find_Max_Min(a,N);
    printf("在查找时比较的次数是：Count=%d\n",x);
    system("PAUSE");
    return 0;
}
