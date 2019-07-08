#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;
int temp[101];
int len[101];
int ans;

void init()
{
    for(int i = 0; i<= 100; i++)
    {
        temp[i] = 0;
        len[i] = 0;
    }
    ans = 1;
}

int main()
{
    int n;
    cin >> n;
    while(n)
    {
        init();
        for(int i = 1; i <= n ; i++)
        {
            cin >> temp[i];
        }
        len[1] = 1;
        for(int i = 2; i <= n; i++)
        {
            for(int j = 1; j < i; j++)
            {
                if(temp[j] >= temp[i])
                {
                    len[i] = max(len[j], len[i]);
                }
            }
            len[i]++;
            ans = max(len[i], ans);
        }
        cout << ans << endl;
        cin >> n;
    }
    return 0;
}
