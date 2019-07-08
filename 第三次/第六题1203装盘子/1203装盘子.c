#include<stdio.h>
#define N 101
int i,j,k,l,m,n,sum,f[N][N][N];
int main()
{
    for(i=0; i<N; ++i)
        f[0][i][0]=1;
 scanf("%d %d",&m,&n);
    for(i=1; i<=m; ++i)
        for(j=1; j<=n; ++j)
            for(k=1; k<=i; ++k)
                for(l=0; l<=k; ++l)
                    f[i][j][k]+=f[i-k][j-1][l];
    for(i=1; i<=m; ++i)
        sum+=f[m][n][i];
    printf("%d\n",sum);
    return 0;
}
