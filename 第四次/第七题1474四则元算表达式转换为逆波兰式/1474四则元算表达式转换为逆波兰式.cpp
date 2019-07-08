#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

stack<char> st;

int main()
{
    char str[101],out[101],temp;
    int lenS = 0, lenO = 0;
    int flag = 0;

    cin >> str;
    while(str[lenS] != '\0')  //入栈
    {
        st.push(str[lenS++]);
    }
    while(!st.empty())
    {
        temp = st.top();
        st.pop();
        switch(temp)
        {
        case ')'://遇到右括号，用‘#’标记一个空位置用于填运算符
            out[lenO++] = '#';
            break;
        case 'a':
        case 'b':
        case 'c'://遇到字母，直接填入
            out[lenO++] = temp;
            break;
        case '('://左括号不处理
            break;
        default://遇到运算符，填入右侧离当前位置最近的空位置
            flag = lenO;
            while(out[--flag] != '#');//找到离当前位置最近的空位置
            out[flag] = temp;
            break;
        }
    }

    for(int i = lenO - 1; i >= 0; i--)
    {
        cout << out[i];
    }
    cout << endl;

    return 0;
}
