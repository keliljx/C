#include<iostream>  
using namespace std;  

int hw(long long num)//�����жϻ��������ĺ���
{  

    int m=num,n=1;  

    while(m)  
    {  
        m/=10;  
        n*=10;  
    }  

    n/=10;  

    m=num;  

    for(int i=n;i>=1;i/=100)//�жϻ���  
    {  
        if(m/i!=m%10)  
            return 0;  
        m-=m/i*i;  
        m/=10;  
    }  

    for(int i=2;i*i<=num;i++)//�ж�����  
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

    if(b>10000000)  /*ż��λ������һ����11�ı��������һǧ�����ϵĶ�����*/
        b=10000000;  

    for(long long i=a;i<=b;i++)  
        if(hw(i)==1)  
            cout<<i<<endl;  

    return 0;
}  
