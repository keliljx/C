/*
(1)��ǲ�ͬ����ͨ����
(2)�жϳ����������ͨ����
(3)������ͨ������ܳ���  ����ѡ�����ͨ�飬ֻҪĳһ��������������ĸ������зǵ�ǰ��ͨ�����ֵ���ܳ���һ��
(4)��������
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

void init() //��ʼ��״̬
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

void mark(int m, int n) //��ǡ�m��n�����������������������ͨ����������
{
    block_mark[m][n] = flag;
    for(int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            if(i != 0 || j != 0) //�˸�����
            {
                m = m + i;
                n = n + j;
                if(m > 0 && m <= row && n > 0 && n <= col) //δ����ͼ�η�Χ
                {
                    if(chess[m][n]== 'X' && block_mark[m][n] == 0) //�뵱ǰ����ͨ��δ���
                    {
                        mark(m,n);
                    }
                }
                m = m - i;
                n = n - j;//����
            }
        }
    }

}

void markBlock() //��ǲ�ͬ����ͨ����
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

void judge(int m , int n) //�жϸõ������������Ƿ��з�Xֵ������߳���һ
{
    for(int i = -1; i <= 1; i++)
    {
        for(int j = -1; j <= 1; j++)
        {
            if((i + j) == 1 || (i + j) == -1) //�ĸ�����
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

void calAns() //���㱻ѡ��ͼ�ε��ܳ�
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
        now_flag = block_mark[x][y];//�ҵ���ǰ��ѡ�������

        calAns();
        cout << len_ans << endl;
        cin >> m >> n >> x >> y;
        row = m;
        col = n;
    }
    return 0;
}