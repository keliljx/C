#include <stdio.h>											/*��׼�������ͷ�ļ�*/
#include <stdlib.h>
#include <string.h>
void encrypt(char *soucefile, char *pwd, char *codefile);				/*���ļ����м��ܵľ��庯��*/
void encrypt(char *s_file, char *pwd, char *c_file) 					/*�Զ��庯��encrypt���ڼ���*/
{
    int i = 0;
    FILE *fp1,  *fp2; 									/*����fp1��fp2��ָ��ṹ�������ָ��*/
    register char ch;
    fp1 = fopen(s_file, "rb");
    if (fp1 == NULL)
    {
        printf("cannot open s_file.\n");
        exit(1); 										/*������ܴ�Ҫ���ܵ��ļ�,���˳�����*/
    }
    fp2 = fopen(c_file, "wb");
    if (fp2 == NULL)
    {
        printf("cannot open or create c_file.\n");
        exit(1); 										/*������ܽ������ܺ���ļ�,���˳�*/
    }
    ch = fgetc(fp1);
    while (!feof(fp1))										/*�����ļ��Ƿ����*/
    {
        ch = ch ^ *(pwd + i);								/*������򷽷����м���*/
        i++;
        fputc(ch, fp2);									/*����д��fp2�ļ�*/
        ch = fgetc(fp1);
        if (i > 9)
            i = 0;
    }
    fclose(fp1); 											/*�ر�Դ�ļ�*/
    fclose(fp2); 											/*�ر�Ŀ���ļ�*/
}
main(int argc, char *argv[]) 										/*����main()�����������в���*/
{
    char sourcefile[50]; 										/*�û������Ҫ���ܵ��ļ���*/
    char codefile[50];
    char pwd[10]; 											/*������������*/
    if (argc != 4)												/*�ݴ���*/
    {
        printf("please input encode file name:\n");
        gets(sourcefile); 										/*�õ�Ҫ���ܵ��ļ���*/
        printf("please input Password:\n");
        gets(pwd); 											/*�õ�����*/
        printf("please input saved file name:\n");
        gets(codefile); 										/*�õ����ܺ���Ҫ���ļ���*/
        encrypt(sourcefile, pwd, codefile);
    }
    else
    {
        strcpy(sourcefile, argv[1]);
        strcpy(pwd, argv[2]);
        strcpy(codefile, argv[3]);
        encrypt(sourcefile, pwd, codefile);
    }
}

