#include <iostream>
#include <cstdio>
#include <queue>
#include <cstdlib>
#include <set>

using namespace std;

typedef struct Table
{
    int data[10];
    int length;
    bool operator <(const Table &b) const  //重载小于号，用于容器set中的结构体大小判断
    {
        for(int i = 0; i < 9; i++)
        {
            if(data[i] != b.data[i])
                return data[i] < b.data[i];
        }
        return data[0] < b.data[0];
    }
};

queue <Table> q;
int example[10] = {1,2,3,4,5,6,7,8,0,0};
Table temp, in,next;
int flag;
set<Table> st;

void output(Table now)  //调试时使用的输出函数
{
    for(int i = 0; i <= 8; i++)
    {
        cout << now.data[i] << " ";
        if(i % 3 == 2)
            cout << endl;
    }
    cout <<endl;
    cout << now.length << "  length" << endl;
}

bool check(Table x)   //判断是否达到最终状态
{
    for(int i = 0; i <  9; i++)
    {
        if(x.data[i] != example[i])
            return false;
    }
    return true;
}

Table moveNext(Table n, int i)   //移动到下一个状态
{
    Table now;//当前的状态
    int posX,posY;//当前状态下0的位置坐标

    for(int i = 0; i <= 9; i++)
    {
        now.data[i] = n.data[i];
    }
    now.length = n.length + 1;
    for(int j = 0; j < 9; j++)  //找到当前状态下0的位置
    {
        if(now.data[j] == 0)
        {
            posX = j / 3;
            posY = j % 3;
            break;
        }
    }

    int p0,p1;
    p0 = posX  * 3 + posY;

    switch(i)
    {
    case 1://向上换
        if(posX >= 1)
        {
            p1 = (posX - 1) * 3 + posY;
        }
        else
        {
            p1 = p0;
            now.data[9] = -1;//标记当前状态不可到
        }
        break;
    case 2://向右换
        if(posY <= 1)
        {
            p1 = (posX) * 3 + posY + 1;
        }
        else
        {
            p1 = p0;
            now.data[9] = -1;
        }
        break;
    case 3://向左换
        if(posY >= 1)
        {
            p1 = (posX) * 3 + (posY - 1);
        }
        else
        {
            p1 = p0;
            now.data[9] = -1;
        }
        break;
    case 4://向下换
        if(posX <= 1)
        {
            p1 = (posX + 1) * 3 + posY;
        }
        else
        {
            p1 = p0;
            now.data[9] = -1;
        }
        break;
    default:
        break;
    }
    if(p0 < 0 || p1 < 0)//调试代码
        cout << "error!<0 " << i << endl;
    if(p0 > 9 || p1 > 9)
        cout << "error!>9 " << i << endl;

    int ttt = now.data[p0];
    now.data[p0] = now.data[p1];
    now.data[p1]= ttt;

    return now;
}

int main()
{

    for(int i = 0; i < 9; i++)
    {
        cin >> in.data[i];
    }
    in.length = 0;
    q.push(in);
    while(!q.empty())
    {
        temp = q.front();
        st.insert(temp);//到达过的状态进行存储
        q.pop();

        if(check(temp))  //判断是否达到目标状态
        {
            cout << temp.length <<endl;
            flag = 1;
            break;
        }
        for(int i = 1; i<= 4; i++)
        {
            next = moveNext(temp,i);//向四个方向试探一次
            if(next.data[9] != -1 && st.count(next) == 0)  //如果能够向这个方向走且该状态之前未曾达到过，进入队列
            {
                q.push(next);
            }
        }
    }
    if(q.empty() && !flag)
    {
        cout<< -1 << endl;
    }
    return 0;
}
