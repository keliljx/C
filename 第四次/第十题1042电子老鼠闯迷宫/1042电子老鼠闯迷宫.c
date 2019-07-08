#include<stdio.h>

int a[12][12],L[144],head,tail,length;

int canmove(int direction,int row,int col,int *new_row,int *new_col)
{
    switch(direction)
    {
    case 0:
        --row;
        break;
    case 1:
        ++row;
        break;
    case 2:
        --col;
        break;
    case 3:
        col++;
        break;
    }
    if(row>=0&&row<=11&&col>=0&&col<=11&&(a[row][col]==-3||a[row][col]==-1))
    {
        *new_row=row;
        *new_col=col;
        return 1;
    }
    else
        return 0;
}
void Sesearch(int x,int y)
{
    int i,u,row,col,num,new_row,new_col,result,success=0;

    for(i=0; i<=143; ++i)
        L[i]=0;
    head=0;
    tail=0;
    length=1;

    u=x*12+y;
    L[0]=u;

    while(length)
    {

        u=L[head];
        L[head]=0;
        --length;
        head=(head+1)%144;

        row=u/12;
        col=u%12;

        num=a[row][col];
        for(i=0; i<4; i++)
        {
            result=canmove(i,row,col,&new_row,&new_col);
            if(result)
            {
                if(a[new_row][new_col]==-1)
                {
                    ++length;
                    tail=(tail+1)%144;
                    L[tail]=new_row*12+new_col;
                    a[new_row][new_col]=num+1;
                }
                else
                {
                    printf("%d\n",num+1);
                    success=1;
                    break;
                }
            }
        }
        if(success)
            break;
    }
}
int main(void)
{
    int i,j,x,y,m,n;
    char temp;
    scanf("%d%d%d%d",&x,&y,&m,&n);
    for(i=0; i<=11; ++i)
    {
        temp=getchar();
        for(j=0; j<=11; ++j)
        {
            temp=getchar();
            if(temp=='X')
                a[i][j]=-2;
            else
                a[i][j]=-1;
        }

    }
    if(a[x-1][y-1]==-1&&(x!=m||y!=n))
    {
        a[x-1][y-1]=0;
        a[m-1][n-1]=-3;
        Sesearch(x-1,y-1);
    }
    else
        printf("0\n");
}
