#include <stdio.h>
#include <stdlib.h>
#define N 7
int Find(int a[][N],int R ,int *row,int*col)
{ int i,j,k,c,t;int FOUND=0;
     for (i=0;(!FOUND && i<(N-R+1));i++)/*�ӵ�0�ſ�ʼ����*/
     {
	 j=0;
         while(j<N-R+1 && !FOUND) {
	      for(k=0;k<R && a[i][j+k]==0;k+1)     /*���ҵ�i��������R������λ*/
		  if(k>=R){/*�ҵ���i��������R������λ*/
			for(c=0;c<R;c++){/*���������R*��R-1������λ*/
			      for(t=1;t<R;t++)
			     if (a[i++][j+c]!= 0)       break;
			     if (t<R) break;
                    }
		if (c>R) FOUND=1;
		}
		     j++;
              }
               }
     if (FOUND){
	   *row = i-1;  *col = j-1; /*������������������Ͻ�����*/
	   printf("%3d%3d",row,col);
	   return 1;
              }
	return 0;
}

int main()
{
    int x;
  int a[N][N]={0,1,1,1,0,0,0,1,1,0,0,1,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0};
  x=Find(a,3,0,0);
  printf("%d",x);
  system("PAUSE");
  return 0;
}
