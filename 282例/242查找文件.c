#include<stdio.h>
main()
{
    char *ptr, filename[50];									/*�������������Ϊ�ַ���*/
    printf("please input the file name you want to search:\n");
    scanf("%s", filename);									/*����Ҫ���ҵ��ļ���*/
    if ((ptr = searchpath(filename)) != NULL)
        printf("the path is:%s\n", ptr);							/*���ļ����ڵ�·�����*/
    else
        printf("cannot find");								/*���ļ�δ�ҵ������˫��������ʾ��Ϣ*/
}
