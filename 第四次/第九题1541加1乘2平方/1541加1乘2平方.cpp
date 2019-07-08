#include <iostream>
#include <queue>

using namespace std;

queue <int> q;
int used[10005];
int ans[10005];
int temp,temp1;

int main()
{
    int n, m;
    cin >> m >> n;
    q.push(m);
    used[m] = 1;
    ans[m] = 0;
    while(!q.empty())
    {
        temp = q.front();
        q.pop();
        for(int i = 1; i <= 3; i++)
        {
            if(i == 1)
            {
                temp1 = temp + 1;
                if(temp1 <= 10000 && ans[temp1] == 0)ans[temp1] = ans[temp]+1;
            }
            if(i == 2)
            {
                temp1 = temp * 2;
                if(temp1 <= 10000 && ans[temp1] == 0)ans[temp1] = ans[temp]+1;
            }
            if(i == 3)
            {
                temp1 = temp * temp;
                if(temp1 <= 10000 && ans[temp1] == 0)ans[temp1] = ans[temp]+1;
            }
            //cout <<temp <<endl;
            if(temp1 < n && !used[temp1] )
            {
                q.push(temp1);
                used[temp1] = 1;
            }
            else if(temp1 == n)
            {
                cout << ans[temp1] << endl;
                return 0;
            }
        }
    }
    return 0;
}
