#include <iostream>
#include <cstdio>

using namespace std;

int flag[1005] = {0,0,1,0,1,0,1,0,1,0,1};

void cal()
{

    for(int i = 11; i <= 1000; i++)
    {
        if((flag[i - 1] + flag[i - 5] + flag[i - 10]) < 3)
            flag[i] = 1;
        else flag[i] = 0;
    }

}

int main()
{
    int n;
    cal();
    cin >> n;
    while(n)
    {
        cout << flag[n] << endl;
        cin >> n;
    }
    return 0;
}
