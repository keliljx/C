# include <stdio.h>
# include <stdlib.h>

int main()
{
    int n; //������n��Ҳ����̬����ĳ���
    char *array; //����ָ��
    int i;
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
// ����̬������Ԫ�����
    for(i=0; i<n; ++i)
    {

        sum = sum + array[i];
    }
    printf("%d\n",sum);
    free(array); //�ͷ��ڴ�
    return 0;
}

