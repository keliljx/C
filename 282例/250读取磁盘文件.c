#include <stdio.h>
main()
{
    FILE *fp;						/*����һ��ָ��FILE���ͽṹ���ָ�����*/
    char ch, filename[50];				/*�������������Ϊ�ַ���*/
    printf("please input file`s name;\n");
    gets(filename);					/*�����ļ�����·��������*/
    fp = fopen(filename, "r");			/*��ֻ����ʽ��ָ���ļ�*/
    ch = fgetc(fp);					/*fgetc��������һ���ַ�����ch*/
    while (ch != EOF)					/*��������ַ�ֵ����EOFʱ����ѭ��*/
    {
        putchar(ch);					/*��������ַ��������Ļ��*/
        ch = fgetc(fp);				/*fgetc������������һ���ַ�����ch*/
    }
    fclose(fp);						/*�ر��ļ�*/
    printf("\n");
}
