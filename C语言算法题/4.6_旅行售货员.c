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
			/*�ж��Ѷ��������Ƿ���ڵ�ǰ��ʱ�������뵽��һ�������ʺ�*/
		 	  if(*allValTemp+cityVal[curCity][nexCity]<*allVal){ 
				  *allValTemp=*allValTemp+cityVal[curCity][nexCity];
				  p++;
				  pathTemp[p] = nexCity;							/*��ֵ��ʱ·��*/
				  if(p==(n-1)){ /*�����е�ǰһ������*/
			   	     if(*allVal > *allValTemp+cityVal[nexCity][1]){	 /*�ж��������Ƿ����ǰ������*/
			  	 		   *allVal = *allValTemp+cityVal[nexCity][1];
			  	 		   for(i=0;i<n+1;i++) path[i] = pathTemp[i]; 	/*����ʱ·�߷���·������*/
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
 	int n;//�����̾����ĳ��и��� 
 	int i,j;
 	int allVal=10000,allValTemp=0;
 	printf("�������辭�����ٸ����У�");
 	scanf("%d",&n);
 	printf("������м�ĺķѣ��þ����ʾ��\n");
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
  	printf("�����������ܺķ�Ϊ��%d\n",allVal);
  	printf("����������·��Ϊ��");
  	for(i=0;i<=n;i++){
	    printf("%d ",path[i]);
    }
    printf("\n");
  system("PAUSE");	
  return 0;
}
