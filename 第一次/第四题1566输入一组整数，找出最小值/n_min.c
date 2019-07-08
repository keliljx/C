# include <stdio.h>
# include <stdlib.h>
# include <malloc.h>
int main()
{
    int n; //正整数n，也即动态数组的长度
    char *array; //数组指针
    int i,j,t;
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
// 输出动态数组中的最小值
    for(i=0;i<n; ++i)
    {
      for (j=i+1;j<n+1;++j)
        if(array[j]>array[i])
        {
                t =array[i] ;
				array[i] = array[j];
				array[j] = t;
        }
    }
    printf("%d\n",array[i-1]);
    free(array); //释放内存
    return 0;
}

