#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[101],i,k,n=0;
    for(i=1;i<=100;i++) a[i]=1;
    for(k=1;k<=100;k++)
        for(i=k;i<=100;i+=k)
         a[i]=-a[i];
    printf("Ï¨Ãð×´Ì¬µÄµÆµÄ±àºÅÊÇ£º\n");
    for(i=1;i<=100;i++)
    if(a[i]==-1){
        printf("%4d",i);n++;}
    printf("\t¹²%dÕµµÆÊÇÃðµÄ\n",n);  
  system("PAUSE");	
  return 0;
}
