#include<iostream>  
using namespace std;  

int hw(long long num)//定义判断回文质数的函数
{  

    int m=num,n=1;  

    while(m)  
    {  
        m/=10;  
        n*=10;  
    }  

    n/=10;  

    m=num;  

    for(int i=n;i>=1;i/=100)//判断回文  
    {  
        if(m/i!=m%10)  
            return 0;  
        m-=m/i*i;  
        m/=10;  
    }  

    for(int i=2;i*i<=num;i++)//判断质数  
    {  
        if(num%i==0)  
            return 0;  
    }  
    return 1;  
}  

int main()  
{  
    long long a,b;  

    cin>>a>>b; 

    if(a==1)
        a+=1; 

    if(b>10000000)  /*偶数位回文数一定是11的倍数，因此一千万以上的都忽略*/
        b=10000000;  

    for(long long i=a;i<=b;i++)  
        if(hw(i)==1)  
            cout<<i<<endl;  

    return 0;
}  
