#include <stdio.h>
main()
{
    char ch, filename1[50], filename2[50];						/*����ͱ�������������Ϊ�ַ���*/
    FILE *fp1,  *fp2;										/*��������ָ��FILE���ͽṹ���ָ�����*/
    printf("please input filename1:\n");
    scanf("%s", filename1);									/*�����ļ�����·��������*/
    if ((fp1 = fopen(filename1, "a+")) == NULL)					/*�Զ�д��ʽ��ָ���ļ�*/
    {
        printf(" cannot open\n");
        exit(0);
    }
    printf("file1:\n");
    ch = fgetc(fp1);
    while (ch != EOF)
    {
        putchar(ch);										/*���ļ�1�е��������*/
        ch = fgetc(fp1);
    }
    printf("\nplease input filename2:\n");
    scanf("%s", filename2);									/*�����ļ�����·��������*/
    if ((fp2 = fopen(filename2, "r")) == NULL)					/*��ֻ����ʽ��ָ���ļ�*/
    {
        printf("cannot open\n");
        exit(0);
    }
    printf("file2:\n");
    ch = fgetc(fp2);
    while (ch != EOF)
    {
        putchar(ch);										/*���ļ�2�е��������*/
        ch = fgetc(fp2);
    }
    fseek(fp2, 0L, 0);										/*���ļ�2�е�λ��ָ���Ƶ��ļ���ʼ��*/
    ch = fgetc(fp2);
    while (!feof(fp2))
    {
        fputc(ch, fp1);									/*���ļ�2�е�����������ļ�1��*/
        ch = fgetc(fp2);									/*������ȡ�ļ�2�е�����*/
    }
    fclose(fp1);											/*�ر��ļ�1*/
    fclose(fp2);											/*�ر��ļ�2*/
}
