#include <iostream>
#include <cstdio>

using namespace std;


int example[11][4] = {{1,0,1,0},{1,0,0,1},{0,1,1,0},{0,1,0,1},{1,1,0,0},
    {0,0,1,1},{1,0,1,1},{1,1,1,0},{0,1,1,1},{1,1,0,1},
    {1,1,1,1}//图示的是一种情况，四个数字依次表示上、下、左、右是否有水渠的情况
};
char input[55][55];//输入的字母表
int farm[55][55];//保存联通情况，相同值的区域为联通的
int row,col,ans;//ans为标记联通的区块值，每标记完一次，加一，最后的值就是联通区域数

void dfs(int m, int n)//深度优先，用ans的值标记由第【i，j】块区域开始的联通区域
{
    int f = ans;
    int old_, new_;
    new_ = input[m][n] - 'A';


    if(m > 1 && farm[m - 1][n] == 0)   //判断与上边的区块是否联通；
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
    if(n > 1 && farm[m][n - 1] == 0)   //判断与左边的区块是否联通；
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
    if(n < col && farm[m][n + 1] == 0)   //判断与右边的区块是否联通；
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

    if(m < row && farm[m + 1][n] == 0)   //判断与下边的区块是否联通；
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

void init()//初始化函数
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
            if(farm[i][j] == 0)  //只要该区域没有被标记说明该区域与之前被标记过的区域不连通，
            {
                //从该区域开始新的联通块标记，联通区域块数加一
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
