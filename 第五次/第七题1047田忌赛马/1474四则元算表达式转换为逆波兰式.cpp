#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int pos=0;
char a[100];
queue<char> q1;
stack<char> s1;

void marge();

void creatReverseNotation()
{
    char ch;
    ch=a[pos];
    if(ch==')')
    {
        marge();
        return;
    }
    if(ch=='(')
    {   pos++;
        creatReverseNotation();
    }
    if(ch=='a'||ch=='b'||ch=='c') //(a*(b*(c+(c/a))))
    {
        q1.push(ch);
    }
    pos++;
    ch=a[pos];
    if(ch=='+'||ch=='-'||ch=='*'||ch=='/')
    {
        s1.push(ch);
        pos++;

    }
    creatReverseNotation();


}

void marge()
{
    char temp;
//    while(!s1.empty())
//    {
    if(!s1.empty())
    {

        temp=s1.top();
        s1.pop();
        q1.push(temp);
    }
//    }
}

int main()
{
    cin>>a;
    char r;
    creatReverseNotation();
    while(!q1.empty())
    {
        r=q1.front();
        cout<<r;
        q1.pop();
    }
    cout<<endl;
}
