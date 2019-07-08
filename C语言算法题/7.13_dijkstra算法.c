#include<stdlib.h>
#include<stdio.h>
#define MAXNODE 30
#define MAXCOST 1000
int dist[MAXNODE],cost[MAXNODE][MAXNODE],n=5;
void dijkstra(int v0)
{
int s[MAXNODE];
int mindis,dis,i,j,u;
for(i=1;i<=n;i++)
{
dist[i]=cost[v0][i];
s[i]=0;
}
s[v0]=1;
for(i=1;i<=n;i++)
{
mindis=MAXCOST;
for(j=1;j<=n;j++)
if(s[j]==0&&dist[j]<mindis)
{
u=j;
mindis=dist[j];
}
s[u]=1;
for(j=1;j<=n;j++)
if(s[j]==0)
{
dis=dist[u]+cost[u][j];
dist[j]=(dist[j]<dis)?dist[j]:dis;
}
}
}
void display_path(int v0)
{
int i;
printf("\n 顶点 %d 到各顶点的最短路径长度如下:\n",v0);
for(i=1;i<=n;i++)
{
printf("  (v%d->v%d):",v0,i);
if(dist[i]==MAXCOST)
printf("wu lun jing\n");
else
printf("%d\n",dist[i]);
}
}
main()
{
int i,j,v0=1;
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
cost[i][j]=MAXCOST;
for(i=1;i<=n;i++)
cost[i][i]=0;
cost[1][2]=10;cost[1][5]=100;cost[1][4]=30;
cost[2][3]=50;cost[4][3]=20;cost[3][5]=10;
cost[4][5]=60;

dijkstra(v0);
display_path(v0);
}
