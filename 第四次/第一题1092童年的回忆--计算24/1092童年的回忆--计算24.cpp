#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

int cal(int x, int y, int op); //定义加减乘除运算
int search(int m); //回溯法遍历所有数字顺序
int test(); //遍历所有运算符
int calculate(int op1, int op2, int op3); //遍历所有括号形式

int n;
int a[4];
int main()
{
    while(cin>>n)
    {
        while(n--)
        {
            for(int j=0; j<4; j++)
            {
                cin>>a[j];
            }
            if(search(0))
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
        }
    }
    return 0;
}
/*回溯法遍历所有数字顺序*/
int search(int m)
{
    if(m == 4)
    {
        if(test() == 1)
            return 1;
    }
    else
    {
        for(int i=m; i<4; i++)
        {
            swap(a[i], a[m]);
            if(search(m + 1) == 1)
            {
                return(1);
            }
            swap(a[i], a[m]);
        }
    }
    return 0;
}

/*遍历所有运算符*/
int test()
{
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
            for(int k=0; k<4; k++)
                if(calculate(i, j, k)==1)
                    return 1;
    return 0;
}

/*遍历所有括号形式*/
int calculate(int op1, int op2, int op3)
{
    if(cal(cal(cal(a[0], a[1], op1), a[2], op2), a[3], op3) == 24)
    {
        return(1);
    }

    if(cal(cal(a[0], a[1], op1), cal(a[2], a[3], op3), op2) == 24)
    {
        return(1);
    }

    if(cal(cal(a[0], cal(a[1], a[2], op2), op1), a[3], op3) == 24)
    {
        return(1);
    }

    if(cal(a[0], cal(cal(a[1], a[2], op2), a[3], op3), op1) == 24)
    {
        return(1);
    }

    if(cal(a[0], cal(a[1], cal(a[2], a[3], op3), op2), op1) == 24)
    {
        return(1);
    }
    return(0);
}


/*定义加减乘除运算*/
int cal(int x, int y, int op)
{
    switch(op)
    {
    case 0:
        return x + y;
    case 1:
        return x - y;
    case 2:
        return x * y;
    case 3:
        if(y != 0)
            return x / y;
        else
            return 123456; //返回一个很大的数即刻
    }
}
