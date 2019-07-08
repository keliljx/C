#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std ;

int chart[230][230];

void output(int n)
{
    for(int i = 1; i<= n; i++)
    {
        for(int j = 1; j<= n; j++)
        {
            cout << chart[i][j];
            if(j != n)
                cout << " ";
        }
        cout << endl;
    }
}
void fillChart(int n)
{
    int s  =1;
    while(s < n)
    {
        for(int i = 1; i <= s; i++)
        {
            for(int j = 1; j <= s; j++)
            {
                chart[i][j + s] = chart[i][j] + s;//�������Ͻ�
                chart[i + s][j] = chart[i][j] + s;//�������½�
                chart[i + s][j + s] = chart[i][j + s] - s;//�������½�
            }
        }
        s *= 2;
    }

}

int main()
{
    chart[1][1] = 1;
    int length;
    int n;
    cin >> n;
    length = (int)(pow(2, n));
    fillChart(length);
    output(length);
    return 0;
}
