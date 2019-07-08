#include <stdio.h>
#include <stdlib.h>
int p=0;
void Backtrack(int curCity,int n,int pathTemp[],int path[],int *allValTemp,int *allVal,int cityVal[n+1][n+1])
{
 	 int nexCity,j,i;
 	 int flag=0;
 	 for(nexCity=2;nexCity<=n;nexCity++){
   	     flag=0;
   	     for(j=1;j<=(p+1);j++){
   		     if(nexCity==pathTemp[j] || curCity == nexCity) flag=1;
   		 }
   		 if(flag==1) continue;
   		 else{
			/*判断已定总旅资是否大于当前临时总旅资与到下一城市旅资和*/
		 	  if(*allValTemp+cityVal[curCity][nexCity]<*allVal){ 
				  *allValTemp=*allValTemp+cityVal[curCity][nexCity];
				  p++;
				  pathTemp[p] = nexCity;							/*赋值临时路线*/
				  if(p==(n-1)){ /*最后城市的前一个城市*/
			   	     if(*allVal > *allValTemp+cityVal[nexCity][1]){	 /*判断总旅资是否大于前总旅资*/
			  	 		   *allVal = *allValTemp+cityVal[nexCity][1];
			  	 		   for(i=0;i<n+1;i++) path[i] = pathTemp[i]; 	/*将临时路线放入路线数组*/
			         }
			         pathTemp[p]=0;
			         *allValTemp=*allValTemp-cityVal[curCity][nexCity];
			         p--;
	 			  }
				  else{
				  	   Backtrack(nexCity,n,pathTemp,path,allValTemp,allVal,cityVal);
					   pathTemp[p]=0;
					   *allValTemp=*allValTemp-cityVal[curCity][nexCity];
					   p--;
				  }
	  		  }else{
			  		return;
 			  }
	  	 }
     }
}
int main()
{
 	int n;//旅行商经过的城市个数 
 	int i,j;
 	int allVal=10000,allValTemp=0;
 	printf("旅行商需经过多少个城市：");
 	scanf("%d",&n);
 	printf("输入城市间的耗费，用矩阵表示：\n");
 	int cityVal[n+1][n+1];
 	cityVal[0][0]=0;
 	int path[n+1],pathTemp[n+1];
 	path[0]=1;
 	path[n]=1;
 	pathTemp[0]=1;
 	pathTemp[n]=1;
 	for(i=1;i<n;i++){
	    path[i]=0;
	    pathTemp[i]=0;
    }
 	for(i=1;i<=n;i++)
 	{
		for(j=1;j<=n;j++)
		{
		    scanf("%d",&cityVal[i][j]);
		}
    }
    for(i=1;i<=n;i++)
 	{
		for(j=1;j<=n;j++)
		{
		    printf("%d  ",cityVal[i][j]);
		}
		printf("\n");
    }
  	Backtrack(1,n,pathTemp,path,&allValTemp,&allVal,cityVal);
  	printf("旅行商最少总耗费为：%d\n",allVal);
  	printf("旅行商旅行路径为：");
  	for(i=0;i<=n;i++){
	    printf("%d ",path[i]);
    }
    printf("\n");
  system("PAUSE");	
  return 0;
}
