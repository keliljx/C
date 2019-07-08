#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100
#define M 2*N-1

typedef char *HuffmanCode[2*M];
typedef struct
{
        int weight;/*权值 */
        int parent;/*父节节点 　*/
        int LChild;/*左子节点 　*/
        int RChild;/*右子节点 */
        }HTNode,Huffman[M+1];/*huffman树 　*/

typedef struct Node
{
        int weight;/*叶子结点的权值 */
        char c; /*叶子节点*/
        int num;/*叶子结点的二进制码的长度 */
        }WNode,WeightNode[N];
/***产生叶子结点的字符和权值***/
void CreateWeight(char ch[],int *s,WeightNode CW,int *p)
{
      int i,j,k;
      int tag;*p=0;/*叶子节点个数 　*/
      /*统计字符出现个数,放入CW 　*/
      for(i=0;ch[i]!='\0';i++)
      {
          tag=1;
	      for(j=0;j<i;j++)
	      if(ch[j]==ch[i])
          {
	          tag=0;   break;
           }
          if(tag) {
                  CW[++*p].c=ch[i];
                  CW[*p].weight=1;
                  for(k=i+1;ch[k]!='\0';k++)
                      if(ch[i]==ch[k])
                      CW[*p].weight++;/*权值累加 */
                      }
          }
                  *s=i;/*字符串长度 */
}
/********创建哈夫曼树********/
void CreateHuffmanTree(Huffman ht,WeightNode w,int n)
{
     int i,j;
     int s1,s2;/*初始化哈夫曼树 */
     for(i=1;i<=n;i++) {
         ht[i].weight =w[i].weight;
         ht[i].parent=0;
         ht[i].LChild=0;
         ht[i].RChild=0;
         }
     for(i=n+1;i<=2*n-1;i++)
     {
         ht[i].weight=0;
         ht[i].parent=0;
         ht[i].LChild=0;
         ht[i].RChild=0;
     }
     for(i=n+1;i<=2*n-1;i++)
     {
         for(j=1;j<=i-1;j++)
         if(!ht[j].parent)
         break;
         s1=j;
         /*找到第一个双亲不为零的结点 */
         for(;j<=i-1;j++)
             if(!ht[j].parent)
             s1=ht[s1].weight>ht[j].weight?j:s1;
             ht[s1].parent=i;
             ht[i].LChild=s1;
         for(j=1;j<=i-1;j++)
             if(!ht[j].parent)
             break;
             s2=j;
         /*找到第二个双亲不为零的结点 */
     for(;j<=i-1;j++)
         if(!ht[j].parent)
         s2=ht[s2].weight>ht[j].weight?j:s2;
         ht[s2].parent=i;
         ht[i].RChild=s2;
         ht[i].weight=ht[s1].weight+ht[s2].weight;/*权值累加 　*/
         }
}
/***********叶子结点的编码***********/
void CrtHuffmanNodeCode(Huffman ht,char ch[],HuffmanCode h,WeightNode weight,int m,int n)
{
     int i,c,p,start;
     char *cd;
     cd=(char *)malloc(n*sizeof(char));
     cd[n-1]='\0';/*末尾置0*/
     for(i=1;i<=n;i++)
     {
         start=n-1; //cd串每次从末尾开始
         c=i;
         p=ht[i].parent;//p在n+1至2n-1
         while(p) //沿父亲方向遍历,直到为0
         {
             start--;//依次向前置值
             if(ht[p].LChild==c)//与左子相同,置0
                 cd[start]='0';
             else //否则置1
                 cd[start]='1';
             c=p;
             p=ht[p].parent;
         }
         weight[i].num=n-start; //二进制码的长度(包含末尾0)
         h[i]=(char *)malloc((n-start)*sizeof(char));
         strcpy(h[i],&cd[start]);//将二进制字符串拷贝到指针数组h中
     }
     free(cd);//释放cd内存
     system("pause"); 
}
/*********所有字符的编码*********/
void CrtHuffmanCode(char ch[],HuffmanCode h,HuffmanCode hc,WeightNode weight,int n,int m)
{
     int i,k;
     for(i=0;i<m;i++)
     { 
         for(k=1;k<=n;k++) /*从weight[k].c中查找与ch[i]相等的下标K*/
             if(ch[i]==weight[k].c)
             break;
         hc[i]=(char *)malloc((weight[k].num)*sizeof(char));
         strcpy(hc[i],h[k]); //拷贝二进制编码
     }
}
/*****解码*****/
void TrsHuffmanTree(Huffman ht,WeightNode w,HuffmanCode hc,int n,int m)
{
     int i=0,j,p;
     printf("***字符串解码信息***\n");
     while(i<m)
     {
         p=2*n-1;/*从父亲节点向下遍历直到叶子节点*/
         for(j=0;hc[i][j]!='\0';j++)
         { 
             if(hc[i][j]=='0')
                 p=ht[p].LChild;
             else
                 p=ht[p].RChild;
         }
         printf("%c",w[p].c); /*打印原信息*/
         i++; 
     }
}
/*****释放huffman编码内存*****/
void FreeHuffmanCode(HuffmanCode h,HuffmanCode hc,int n,int m)
{
     int i;
     for(i=1;i<=n;i++)//释放叶子结点的编码
     free(h[i]);
     for(i=0;i<m;i++)
     //释放所有结点的编码
     free(hc[i]);
}
 void main()
 {
     int i,n=0; /*n为叶子结点的个数*/
     int m=0; /*m为字符串ch[]的长度*/
     char ch[N]; /*ch[N]存放输入的字符串*/
     Huffman ht; /*Huffman二叉数 */
     HuffmanCode h,hc; /*h存放叶子结点的编码，hc 存放所有结点的编码*/
     WeightNode weight; /*存放叶子结点的信息*/
     printf("请输入字符串信息 :");
     gets(ch); /*输入字符串*/
     CreateWeight(ch,&m,weight,&n); /*产生叶子结点信息，m为字符串ch[]的长度*/
     printf("***权值信息***\n Node ");
     for(i=1;i<=n;i++) /*输出叶子结点的字符与权值*/
         printf("%c ",weight[i].c);
     printf("\nWeight ");
     for(i=1;i<=n;i++)
         printf("%d ",weight[i].weight);
     CreateHuffmanTree(ht,weight,n); /*产生Huffman树*/
     printf("\n***哈夫曼树信息***\n");
     printf("\ti\tweight\tparent\tLChild\tRChild\n");
     for(i=1;i<=2*n-1;i++) /*打印Huffman树的信息*/
     printf("\t%d\t%d\t%d\t%d\t%d\n",i,ht[i].weight,ht[i].parent,ht[i].LChild,ht[i].RChild);
     CrtHuffmanNodeCode(ht,ch,h,weight,m,n); /*叶子结点的编码*/
     printf(" ***叶子节点***\n"); /*打印叶子结点的编码*/
     for(i=1;i<=n;i++) {
         printf("\t%c:",weight[i].c);
         printf("%s\n",h[i]); 
     }
     CrtHuffmanCode(ch,h,hc,weight,n,m); /*所有字符的编码*/
     printf("***输入字符串的编码***\n"); /*打印字符串的编码*/
     for(i=0;i<m;i++)
         printf("%s",hc[i]);
     printf("\n"); 
     system("pause");
     TrsHuffmanTree(ht,weight,hc,n,m); /*解码*/
     FreeHuffmanCode(h,hc,n,m);
     printf("\n");
     system("pause");
 }
