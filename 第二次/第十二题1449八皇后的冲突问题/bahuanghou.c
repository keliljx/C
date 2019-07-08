#include<stdio.h>
#include<math.h>
int main(){
	int i,j,n;
	int flag=1;
	int a[3][8];
	for(i=0;i<3;i++){
		for(j=0;j<8;j++){
			scanf("%d",&a[i][j]);
		}
	}
	scanf("%d",&n);
	for(i=0;i<3;i++){
		if(a[i][n]==1){
			flag=0;
		}
	}
	for(i=0;i<3;i++){
		for(j=0;j<8;j++){
			if(a[i][j]==1){
				if(abs(i-3)==abs(n-j))
					flag=0;
			}
		}
	}
	if(flag==0)
		printf("No\n");
	else
		printf("Yes\n");	                     
}
