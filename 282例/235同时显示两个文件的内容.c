#include <stdio.h>
#include<conio.h>
main()
{
    FILE *fp1,  *fp2;										/*��������ָ��FILE���ͽṹ���ָ�����*/
    char filename1[50], filename2[50], a;						/*��������ͱ���Ϊ�ַ���*/
    printf("please input filename1:\n");
    scanf("%s", filename1); 								/*�����һ���ļ�����·��������*/
    printf("please input filename2\n");
    scanf("%s", filename2); 								/*����ڶ����ļ�����·��������*/
    fp1 = fopen(filename1, "r");								/*��ֻ����ʽ������ĵ�һ���ļ�*/
    fp2 = fopen(filename2, "r");								/*��ֻ����ʽ������ĵڶ����ļ�*/
    gotoxy(3, 5); 										/*����궨λ*/
    printf("file1:\n");
    a = fgetc(fp1);
    while (!feof(fp1))
    {
        printf("%c", a);									/*�����һ���ļ��е�����*/
        a = fgetc(fp1);
    }
    gotoxy(3, 13);										/*����궨λ*/
    printf("file2:\n");
    a = fgetc(fp2);
    while (!feof(fp2))
    {
        printf("%c", a);									/*����ڶ����ļ��е�����*/
        a = fgetc(fp2);
    }
    fclose(fp1);											/*�رյ�һ���ļ�*/
    fclose(fp2);											/*�رյڶ����ļ�*/
}
