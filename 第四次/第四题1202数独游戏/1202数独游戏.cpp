#include <iostream>
#include <cstdio>

using namespace std;

int blockUsed[3][3][10];//九个小正方形的标记
int rowUsed[9][10];//行标记
int colUsed[9][10];//列标记
char chart[9][9];
int flag;

void output()
{
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            cout << chart[i][j];
        }
        cout << endl;
    }
    //cout << endl;//不用换行？？
}
void fillNum(int r, int c)  //在【r，c】处填数字
{
    int tempR,tempC ;
    if(flag ) return;
    if(r > 8)
    {
        output();
        flag = 1;
        return;
    }
    else if(chart[r][c] != '0')    //如果当前位置已经被填过，开始填下一个位置
    {
        c++;
        if(c > 8)
        {
            r++;
            c = 0;
        }
        fillNum(r, c);
    }
    else
    {
        for(int i = 1; i <= 9; i++)
        {
            tempR = r,tempC = c;
            if(rowUsed[r][i] == 0 && colUsed[c][i] == 0
                    && blockUsed[r/3][c/3][i] == 0)  //满足三个条件没有重复值
            {
                chart[r][c] = i + '0';
                rowUsed[r][i] = 1;
                colUsed[c][i] = 1;
                blockUsed[r/3][c/3][i] = 1;
                tempC++;
                if(tempC > 8)
                {
                    tempR++;
                    tempC = 0;
                }
                fillNum(tempR,tempC);
                rowUsed[r][i] = 0;//回溯
                colUsed[c][i] = 0;
                blockUsed[r/3][c/3][i] = 0;
                chart[r][c] = '0';
            }
        }
    }
}

int main()
{
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            cin >> chart[i][j];
            if(chart[i][j] != '0')  //根据开始状态更新标记状态
            {
                int temp = chart[i][j] - '0';
                rowUsed[i][temp] = 1;
                colUsed[j][temp] = 1;
                blockUsed[i/3][j/3][temp] = 1;
            }
        }
    }
    fillNum(0,0);
    return 0;
}
