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
    bool operator <(const Table &b) const  //����С�ںţ���������set�еĽṹ���С�ж�
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

void output(Table now)  //����ʱʹ�õ��������
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

bool check(Table x)   //�ж��Ƿ�ﵽ����״̬
{
    for(int i = 0; i <  9; i++)
    {
        if(x.data[i] != example[i])
            return false;
    }
    return true;
}

Table moveNext(Table n, int i)   //�ƶ�����һ��״̬
{
    Table now;//��ǰ��״̬
    int posX,posY;//��ǰ״̬��0��λ������

    for(int i = 0; i <= 9; i++)
    {
        now.data[i] = n.data[i];
    }
    now.length = n.length + 1;
    for(int j = 0; j < 9; j++)  //�ҵ���ǰ״̬��0��λ��
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
    case 1://���ϻ�
        if(posX >= 1)
        {
            p1 = (posX - 1) * 3 + posY;
        }
        else
        {
            p1 = p0;
            now.data[9] = -1;//��ǵ�ǰ״̬���ɵ�
        }
        break;
    case 2://���һ�
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
    case 3://����
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
    case 4://���»�
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
    if(p0 < 0 || p1 < 0)//���Դ���
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
        st.insert(temp);//�������״̬���д洢
        q.pop();

        if(check(temp))  //�ж��Ƿ�ﵽĿ��״̬
        {
            cout << temp.length <<endl;
            flag = 1;
            break;
        }
        for(int i = 1; i<= 4; i++)
        {
            next = moveNext(temp,i);//���ĸ�������̽һ��
            if(next.data[9] != -1 && st.count(next) == 0)  //����ܹ�������������Ҹ�״̬֮ǰδ���ﵽ�����������
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
