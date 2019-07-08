#include   <stdio.h>   
 #include   <stdlib.h>   
    
  #define   MAXVEX   30   
  #define   MAXCOST   1000   
  void   prim   (int   c[MAXVEX][MAXVEX],   int   n)
  {   
  int   i,j,k,min,lowcost[MAXVEX],closest[MAXVEX];   
  for   (i=2;i<=n;i++)    
  {   
  lowcost[i]=c[1][i];  /*从顶点1开始*/   
  closest[i]=1;   
  }   
  closest[1]=0;   
  for   (i=2;i<=n;i++)   /*从U之外求离U中某一顶点最近的顶点*/   
  {   
  min=MAXCOST;   
  j=1;   
  k=i;   
  while   (j<=n)   
  {   
  if   (lowcost[j]<min   &&   closest[j]!=0)/*在V-U中找出离U最近的顶点，赋给k*/    
  {   
  min=lowcost[j];   
  k=j;   
  }   
  j++;   
  }   
  printf   ("(%d,%d)",closest[k],k);   /*打印边*/   
  closest[k]=0;   /*   k加入到U中   */   
  for   (j=2;j<=n;j++)   
  if   (closest[j]!=0&&c[k][j]<lowcost[j])   
  {   
  lowcost[j]=c[k][j]; /*修改数组lowcost和closest*/   
  closest[j]=k;   
  }   
  }   
  }   
    
  void   main()   
  {   
  int   n=7,i,j,mx[MAXVEX][MAXVEX];   
  for   (i=0;i<=n;i++)   
  for   (j=0;j<=n;j++)   
  mx[i][j]=MAXCOST;  /*给mx中每个元素赋初值*/  
  mx[1][2]=50;   
  mx[1][3]=60;   
  mx[2][4]=65;   
  mx[2][5]=40;   
  mx[3][4]=52;   
  mx[3][7]=45;   
  mx[4][5]=50;   
  mx[5][6]=70;   
  mx[4][6]=30;   
  mx[4][7]=42;   
  printf("Minimal Spanning Tree is:\n");   
  prim(mx,n);   
  } 
