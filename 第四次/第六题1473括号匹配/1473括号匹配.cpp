#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

char str[105];
int stackM[105];
int top = 0;

void No()
{
    cout << "No" << endl;
    exit(0);
}
void Yes()
{
    cout << "Yes" << endl;
    exit(0);
}
int main()
{
    int len = 0;
    cin >> str;
    while(str[len] != '\0')
    {
        switch (str[len])
        {
        case '{':
            stackM[top++] = 1;
            break;
        case '}':
            if(top <= 0 || stackM[top - 1] != 1)
                No();
            stackM[--top] = 0;
            break;
        case '[':
            stackM[top++] = 2;
            break;
        case ']':
            if(top <= 0 || stackM[top - 1] != 2)
                No();
            stackM[--top] = 0;
            break;
        case '(':
            stackM[top++] = 3;
            break;
        case ')':
            if(top <= 0 || stackM[top - 1] != 3)
                No();
            stackM[--top] = 0;
            break;
        default:
            break;
        }
        len++;
    }
    if(top == 0)
    {
        Yes();
    }
    else
    {
        No();
    }
    return 0;
}