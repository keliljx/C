#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <algorithm>
using namespace std;

typedef struct Activity
{
    int begin_;
    int end_;

    bool operator <( const Activity b) const
    {
        return end_ < b.end_;
    }
};

int main()
{
    int n,len,ans,temp;
    Activity activities[1001];
    cin >> n;
    len = n;
    ans = 1;
    while(n--)
    {
        cin >> activities[n].begin_ >> activities[n].end_;
    }
    sort(activities, activities + len);
    temp = activities[0].end_;
    for(int i = 1; i < len; i++)
    {
        if(activities[i].begin_ >= temp)
        {
            ans++;
            temp = activities[i].end_;
        }
    }
    cout << ans << endl;
    return 0;
}