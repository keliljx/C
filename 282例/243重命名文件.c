#include<stdio.h>
main()
{
    FILE *fp;											/*����һ��ָ��FILE���ͽṹ���ָ�����*/
    char filename1[20], filename2[20];							/*��������Ϊ�ַ���*/
    printf("please input the file name which do you want to change:\n");
    scanf("%s", filename1);									/*����Ҫ���������ļ����ڵ�·��������*/
    if ((fp = fopen(filename1, "r")) != NULL)						/*��ֻ����ʽ��ָ���ļ�*/
    {
        printf("%s open successfully", filename1);
        printf("\nplease input new name!");
            scanf("%s", filename2);	/*�����µ��ļ�·��������*/
        rename(filename1, filename2);								/*����rename��������������*/
        fclose(fp);											/*�ر��ļ�*/
    }
    else
    {
        printf("cannot find!!");
        exit(0);
    }
}
