#include<stdio.h>
main()
{
    FILE *fp;											/*����һ��ָ��FILE���ͽṹ���ָ�����*/
    char filename[50];										/*��������Ϊ�ַ���*/
    printf("please input the name of the file which do you want to delete:\n");
    scanf("%s", filename);									/*����Ҫɾ�����ļ���·��������*/
    if ((fp = fopen(filename, "r")) != NULL)						/*��ֻ����ʽ��ָ���ļ�*/
    {
        printf("%s open successfully!", filename);					/*�ļ��򿪳ɹ������ʾ��Ϣ*/
        fclose(fp);										/*�ر��ļ�*/
    }
    else
    {
        printf("%s cannot open!", filename);				/*�ļ���ʧ�������ʾ��Ϣ*/
        exit(0);
    }
    remove(filename);								/*���ú���ɾ���ļ�*/
    if ((fp = fopen(filename, "r")) == NULL)
        printf("\n%s has removed!", filename);			/*��Ҫ�򿪵��ļ������ڣ���ɾ���ɹ��������ʾ��Ϣ*/
    else
        printf("error");							/*��Ҫ�򿪵��ļ����ڣ���ɾ�����ɹ��������ʾ��Ϣ*/
}
