#include <iostream>
#include <cstdio>

using namespace std;

char arryTree[10000];//使用数组存储二叉树，父节点为下标i时，左子节点为2*i，右子节点为2*i+1;
int son[10000];
int pos;

void createTree(char ch)
{
    if(pos == 1 && son[pos] == 2)
    {
        return;
    }
    if(ch >= 'A' && ch <= 'Z' || ch == '#')
    {
        arryTree[pos] = ch;
        son[pos]++;
    }
    else if(ch == '(')
    {
        pos = pos * 2;
    }
    else if(ch == ')')
    {
        pos = pos / 2;
    }
    else if(ch == ',')
    {
        pos = pos + 1;
    }
}

void  init()
{
    for(int i = 1; i <= 10000; i++)
    {
        arryTree[i] = '#';
    }
}
void output()
{
    for(int i = 1; i <= 10000; i++)
    {
        if(arryTree[i] != '#')
        {
            cout << arryTree[i];
        }
    }
    cout << endl;
}
int main()
{
    char str[1000];
    cin >> str;
    init();
    int length = 0;
    pos = 1;
    while(str[length] != '\0')
    {
        createTree(str[length]);
        length++;
    }
    output();
    return 0 ;
}
