# include <stdio.h>

int n = 8;
int a[10] = {0};
int count = 0;

void search(int );
int judge(int ,int );
void output();
int abs(int );

int main(void)
{
    search(1);

    return 0;
}

void search(int k)
{
    int i;

    if (k == n + 1)
        output();
    else
    {
        for (i = 1; i <= n; ++i)
            if (judge(k, i))
            {
                a[k] = i;
                search(k + 1);
                a[k] = 0;//恢复状态很重要
            }
    }
}

int judge(int row, int col)
{
    int i, flag;

    flag = 1;
    for (i = 1; i <= row; ++i)
        if (a[i] == col)
            flag = 0;
    if (flag)
    {
        for (i = 1; i <= row; ++i)
            if (abs(i - row) == abs(a[i] - col))//判断对角线的条件
                flag = 0;
    }

    return flag;
}

void output()
{
    int i, j;

    count++;
    printf("No %d:\n", count);
    for (i = 1; i <= n; ++i)
    {
        for (j = 1; j <= n; ++j)
            if (a[i] == j)
                printf("A");
            else
                printf(".");
        printf("\n");
    }
}

int abs(int k)
{
    if (k < 0)
        return -k;
    else
        return k;
}
