/*
描述：每次拿出其中的一半再放回去一个球，一共这样做了n次，袋子里还有m个球。
问原来袋子中有多少个球？
输入：   输入两个正整数n和m，
输出：   袋子里原来有多少个球
输入样例：  1 3
输出样例：  4
*/
# include <stdio.h>
int main()
{
    int n,m,i;
    scanf("%d%d",&n,&m);
    for(i=0; i<n; ++i)
    {
        m=2*(m-1);
    }
    printf("%d\n",m);
    return 0;
}
