#include <stdio.h>
struct index 									/*定义块的结构*/
{
    int key;
    int start;
    int end;
} index[4]; 								/*定义结构体数组*/
int search(int key, int a[]) 						/*自定义实现分块查找*/
{
    int i, j;
    i = 0;
    while (i < 3 && key > index[i].key)			/*确定在那个块中*/
        i++;
    if (i >= 3)									/*大于分得的块数，则返回0*/
        return -1;
    j = index[i].start; 							/*j等于块范围的起始值*/
    while (j <= index[i].end && a[j] != key)			/*在确定的块内进行查找*/
        j++;
    if (j > index[i].end)						/*如果大于块范围的结束值，则说明没有要查找的数,j置0*/
        j = -1;
    return j;
}
void main()
{
    int i, j = -1, k, key;                   /*定义变量*/
	int a[]={42,63,82,89,111,146,219,254,325,336,348,795,876,951,998};/*已知的一组数*/
	printf("已知有一组数\n");
	for(i=0;i<15;i++)
		printf("%d ",a[i]);      /*输出已知数组*/
	printf("\n");
    for (i = 0; i < 3; i++)
    {
        index[i].start = j+1; 					/*确定每个块范围的起始值*/
        j = j + 1;
        index[i].end = j + 4; 					/*确定每个块范围的结束值*/
        j = j + 4;
        index[i].key = a[j]; 					/*确定每个块范围中元素的最大值*/
    }
    printf("请输入您想要查找的数:\n");
    scanf("%d", &key); 							/*输入要查询的数值*/
    k = search(key, a); 						/*调用函数进行查找*/
    if (k >= 0)
        printf("查找成功！您要找的数在数组中的位置是:%d\n", k+1);			/*如果找到该数，则输出其位置*/
    else
        printf("查找失败！您要找的数不在数组中。\n");							/*若未找到则输出提示信息*/
}
