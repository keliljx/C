/*
(1)标记不同的联通区域；
(2)判断出被点击的联通区域；
(3)计算联通区域的周长：  遍历选择的联通块，只要某一个点的上下左右四个方向有非当前联通区域的值，周长加一；
(4)输出结果；
*/

#include <iostream>
#include <cstdio>
#define MAX_SIZE 100

using namespace std;

char chess[MAX_SIZE][MAX_SIZE];
int block_mark[MAX_SIZE][MAX_SIZE];
int len_ans;
int flag, now_flag;
int row, col;

void init() //初始化状态
{
    for(int i = 0; i < MAX_SIZE; i++)
    {
        for(int j= 0; j <= MAX_SIZE; j++)
        {
            chess[i][j] = '.';
            block_mark[i][j] = 0;
        }
    }
    len_ans = 0;
    flag = 0;
    now_flag = 0;
}

void mark(int m, int n) //标记【m，n】的区域并搜索出与该区域联通的所有区域
{
    block_mark[m][n] = flag;
    for(int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            if(i != 0 || j != 0) //八个方向
            {
                m = m + i;
                n = n + j;
                if(m > 0 && m <= row && n > 0 && n <= col) //未超出图形范围
                {
                    if(chess[m][n]== 'X' && block_mark[m][n] == 0) //与当前点联通且未标记
                    {
                        mark(m,n);
                    }
                }
                m = m - i;
                n = n - j;//回溯
            }
        }
    }

}

void markBlock() //标记不同的联通区域
{
    for(int i = 1; i <= row; i++)
    {
        for(int j =1; j <= col; j++)
        {
            if(chess[i][j]== 'X' && block_mark[i][j] == 0)
            {
                flag++;
                mark(i, j);
            }

        }
    }
}

void judge(int m , int n) //判断该点周上下左右是否有非X值，有则边长加一
{
    for(int i = -1; i <= 1; i++)
    {
        for(int j = -1; j <= 1; j++)
        {
            if((i + j) == 1 || (i + j) == -1) //四个方向
            {
                m = m + i;
                n = n + j;
                if(m >= 0 && m <= row + 1 && n >= 0 && n <= col + 1 && chess[m][n] != 'X')
                    len_ans++;
                m = m - i;
                n = n - j;
            }
        }
    }
}

void calAns() //计算被选择图形的周长
{
    for(int i = 1; i <= row; i++)
    {
        for(int j = 1; j <= col; j++)
        {
            if(block_mark[i][j] == now_flag)
            {
                judge(i,j);
            }
        }
    }
}

int main()
{
    int m,n,x,y;
    cin >> m >> n >> x >> y;
    row = m;
    col = n;
    while(m != 0 || n != 0 || x != 0 || y != 0)
    {
        init();
        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j<= n; j++)
            {
                cin >> chess[i][j];
            }
        }
        markBlock();
        now_flag = block_mark[x][y];//找到当前被选择的区域

        calAns();
        cout << len_ans << endl;
        cin >> m >> n >> x >> y;
        row = m;
        col = n;
    }
    return 0;
}