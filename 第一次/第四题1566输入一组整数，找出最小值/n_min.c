# include <stdio.h>
# include <stdlib.h>
# include <malloc.h>
int main()
{
    int n; //������n��Ҳ����̬����ĳ���
    char *array; //����ָ��
    int i,j,t;
    int sum =0;
    scanf("%d",&n);   // ��̬�����ڴ�ռ�
    array = (char*)malloc( n*sizeof(char) );
    if(!array)
    {
        printf("��������ʧ�ܣ�\n");
        exit(1);
    }
// ��̬������д������
    for(i=0; i<n; ++i)
    {
        scanf("%d",&array[i]);

    }
// �����̬�����е���Сֵ
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
    free(array); //�ͷ��ڴ�
    return 0;
}

