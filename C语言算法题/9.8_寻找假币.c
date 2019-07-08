#include <stdio.h>
#include <stdlib.h>
int findCoin(int coin[],int front,int back)
{
     int i,sumf=0,sumb=0,sum=0;
     if(front+1==back)
     {
         if(coin[front]<coin[back])    return front+1;
         else return back+1;                 
     }   
     if((back-front+1)%2==0)
     {
         for(i=front;i<=front+(back-front)/2;i++)
             sumf=sumf+coin[i];
         for(i=front+(back-front)/2+1;i<=back;i++)
             sumb=sumb+coin[i];
         if(sumf<sumb)
             return findCoin(coin,front,front+(back-front)/2);
         if(sumf>sumb)
             return findCoin(coin,front+(back-front)/2+1,back);                       
     }
     
     if((back-front+1)%2!=0)
     {
         for(i=front;i<=front+(back-front)/2-1;i++)
             sumf=sumf+coin[i];
         for(i=front+(back-front)/2+1;i<=back;i++)
             sumb=sumb+coin[i];
             sum=coin[front+(back-front)/2];
         if(sumf<sumb)
             return findCoin(coin,front,front+(back-front)/2-1);
         if(sumf>sumb)
             return findCoin(coin,front+(back-front)/2+1,back); 
         if(sumf+sum==sumb+sum)
             return front+(back-front)/2+1;                       
     }
}
    
int main()
{
    int coin[30]={1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    printf("那个假币是第%d个金币！\n",findCoin(coin,0,29));
    system("PAUSE");	
    return 0;
}
