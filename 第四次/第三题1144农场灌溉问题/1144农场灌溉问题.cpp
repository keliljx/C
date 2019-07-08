#include <iostream>
#include <cstdio>

using namespace std;


int example[11][4] = {{1,0,1,0},{1,0,0,1},{0,1,1,0},{0,1,0,1},{1,1,0,0},
    {0,0,1,1},{1,0,1,1},{1,1,1,0},{0,1,1,1},{1,1,0,1},
    {1,1,1,1}//ͼʾ����һ��������ĸ��������α�ʾ�ϡ��¡������Ƿ���ˮ�������
};
char input[55][55];//�������ĸ��
int farm[55][55];//������ͨ�������ֵͬ������Ϊ��ͨ��
int row,col,ans;//ansΪ�����ͨ������ֵ��ÿ�����һ�Σ���һ������ֵ������ͨ������

void dfs(int m, int n)//������ȣ���ans��ֵ����ɵڡ�i��j��������ʼ����ͨ����
{
    int f = ans;
    int old_, new_;
    new_ = input[m][n] - 'A';


    if(m > 1 && farm[m - 1][n] == 0)   //�ж����ϱߵ������Ƿ���ͨ��
    {
        old_ = input[m - 1][n] - 'A';
        if(example[new_][0] == 1 && example[old_][1] == example[new_][0])
        {
            farm[m - 1][n] = f;
            dfs(m - 1,n);
        }
        else
        {
            farm[m - 1][n] = 0;
        }
    }
    if(n > 1 && farm[m][n - 1] == 0)   //�ж�����ߵ������Ƿ���ͨ��
    {
        old_ = input[m][n - 1] - 'A';
        if(example[new_][2] == 1 && example[old_][3] == example[new_][2])
        {
            farm[m][n - 1] = f;
            dfs(m,n - 1);
        }
        else
        {
            farm[m][n - 1] = 0;
        }
    }
    if(n < col && farm[m][n + 1] == 0)   //�ж����ұߵ������Ƿ���ͨ��
    {
        old_ = input[m][n + 1] - 'A';
        if(example[new_][3] == 1 && example[old_][2] == example[new_][3])
        {
            farm[m][n + 1] = f;
            dfs(m,n + 1);
        }
        else
        {
            farm[m][n + 1] = 0;
        }
    }

    if(m < row && farm[m + 1][n] == 0)   //�ж����±ߵ������Ƿ���ͨ��
    {
        old_ = input[m + 1][n] - 'A';
        if(example[new_][1] == 1 && example[old_][0] == example[new_][1])
        {
            farm[m + 1][n] = f;
            dfs(m + 1,n);
        }
        else
        {
            farm[m + 1][n] = 0;
        }
    }
}

void init()//��ʼ������
{
    for(int i = 1; i <= row; i++)
    {
        for(int j = 1; j <= col; j++)
        {
            farm[i][j] =  0;
        }
    }
    ans = 1;
    farm[1][1] = 1;
    dfs(1,1);
}
void  check(int m, int n)
{
    init();
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(farm[i][j] == 0)  //ֻҪ������û�б����˵����������֮ǰ����ǹ���������ͨ��
            {
                //�Ӹ�����ʼ�µ���ͨ���ǣ���ͨ���������һ
                ans++;
                dfs(i,j);
            }
        }
    }
}

int main()
{
    cin >> row >> col;
    while(row != -1 && col != -1)
    {
        for(int i = 1; i <= row; i++)
        {
            for(int j = 1; j <= col; j++)
            {
                cin >> input[i][j];
            }
        }
        check(row,col);
        cout << ans << endl;
        cin >> row >> col;
    }
    return 0;
}
