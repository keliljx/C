# include <stdio.h>
# include <stdlib.h>

int main()
{
    int n; //正整数n，也即动态数组的长度
    char *array; //数组指针
    int i;
    int sum =0;
    scanf("%d",&n);   // 动态分配内存空间
    array = (char*)malloc( n*sizeof(char) );
    if(!array)
    {
        printf("创建数组失败！\n");
        exit(1);
    }
// 向动态数组中写入数据
    for(i=0; i<n; ++i)
    {
        scanf("%d",&array[i]);

    }
// 将动态数组中元素相加
    for(i=0; i<n; ++i)
    {

        sum = sum + array[i];
    }
    printf("%d\n",sum);
    free(array); //释放内存
    return 0;
}

