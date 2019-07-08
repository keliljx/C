#include <iostream>
#include <cstdio>
#include <queue>
#include <utility>

using namespace std;

queue< pair<int, int> > q;
int chess[205][205];
int ans[205][205];


int init()
{
    for(int i = 0; i<= 201; i++)
    {
        for(int j = 0; j <= 201; j++)
        {
            chess[i][j] = 0;
            ans[i][j] = 0;
        }
    }
    queue< pair<int, int> > empty_;
    swap(empty_, q);

    return 0;
}
pair<int , int> moveNext(pair<int ,int> now, int i)
{
    pair<int , int> next;
    switch(i)
    {
    case 1:
        next = make_pair(now.first - 2, now.second + 1);
        break;
    case 2:
        next = make_pair(now.first - 1, now.second + 2);
        break;
    case 3:
        next = make_pair(now.first - 2, now.second - 1);
        break;
    case 4:
        next = make_pair(now.first - 1, now.second - 2);
        break;
    case 5:
        next = make_pair(now.first + 1, now.second - 2);
        break;
    case 6:
        next = make_pair(now.first + 2, now.second - 1);
        break;
    case 7:
        next = make_pair(now.first + 2, now.second + 1);
        break;
    case 8:
        next = make_pair(now.first + 1, now.second + 2);
        break;
    default:
        break;
    }
    int nex = next.first;
    int ney = next.second;
    int nox = now.first;
    int noy = now.second;
    if(nex <= 200 && nex >= 0 && ney >= 0 && ney <= 200)
    {
        ans[nex][ney] = ans[nox][noy] + 1;
    }

    return next;
}

int main()
{
    int n;
    int sx,sy, tx,ty;
    cin >> n;
    while(n--)
    {
        init();
        int flag = 0;
        cin >> sx >> sy >> tx >> ty;
        q.push(make_pair(sx,sy));
        while(!q.empty() && !flag)
        {
            pair<int , int> now = q.front();
            pair<int , int> next;
            q.pop();
            for(int i = 1; i<= 8; i++)
            {
                next = moveNext(now, i);
                if(next.first <= 200 && next.second <= 200 &&
                        next.first >= 0 && next.second >= 0 &&
                        chess[next.first][next.second] == 0 &&
                        (next.first != tx || next.second != ty))
                {

                    chess[next.first][next.second] = 1;
                    q.push(next);
                }
                else if (next.first == tx && next.second == ty)
                {
                    cout << ans[next.first][next.second] << endl;
                    flag = 1;
                    break;
                }
            }
        }
    }
    return 0;
}
