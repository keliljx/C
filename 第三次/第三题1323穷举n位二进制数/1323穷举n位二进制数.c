# include <stdio.h>
int a[20];
int n;
void print();
void search(int m);
int main(){  
      scanf("%d",&n); 
	  search(0);	  
  return 0;
}

void search(int m){
    if(m == n){
	     print();
	}else{
	   a[m]=0;
	   search(m+1);
	   a[m]=1;
	   search(m+1);
	}
   
}

void print(){
   int i;
   for(i=0;i<n;i++){
      printf("%d",a[i]);
   }
   printf("\n");
}