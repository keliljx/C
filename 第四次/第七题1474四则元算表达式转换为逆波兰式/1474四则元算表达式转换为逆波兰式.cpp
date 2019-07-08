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
    while(str[lenS] != '\0')  //��ջ
    {
        st.push(str[lenS++]);
    }
    while(!st.empty())
    {
        temp = st.top();
        st.pop();
        switch(temp)
        {
        case ')'://���������ţ��á�#�����һ����λ�������������
            out[lenO++] = '#';
            break;
        case 'a':
        case 'b':
        case 'c'://������ĸ��ֱ������
            out[lenO++] = temp;
            break;
        case '('://�����Ų�����
            break;
        default://����������������Ҳ��뵱ǰλ������Ŀ�λ��
            flag = lenO;
            while(out[--flag] != '#');//�ҵ��뵱ǰλ������Ŀ�λ��
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
