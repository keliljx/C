#include <stdio.h>
#include <string.h>
#include <stdlib.h>
FILE *in,  *out;											/*��������ָ��FILE���ͽṹ���ָ�����*/
char filename[50], ch, cfilename[50];
void space()											/* �ָ��ļ����� */
{
    char ext[6][6] =
    {
        "a.txt", "b.txt", "c.txt", "d.txt", "e.txt", "f.txt"
    };												/* �ָ�������ļ���չ�� */
    unsigned long int n = 1, k, byte = 0;							/* �����������Ϊ�޷��ŵĳ����α��� */
    unsigned int j = 0, i = 0;
    printf("Please input filename:\n");
    scanf("%s", filename);									/*�����ļ�����·��������*/
    strcpy(cfilename, filename);								/*�����ļ�����·�������Ƹ��Ƶ�cfilename��*/
    if ((in = fopen(filename, "r")) == NULL)						/* ��ֻ����ʽ�������ļ� */
    {
        printf("Cannot open file\n");
        exit(0);
    }
    printf("Please input file size after space(kb):\n");
    scanf("%d", &n);										/* ����ָ�󵥸��ļ��Ĵ�С */
    n = n * 1024;
    while (filename[j] != '.')
        j++;
    filename[j] = '\0';										/*��'.'ʱ,�ڸô����ַ���������*/
    if ((out = fopen(strcat(filename, ext[i]), "w")) == NULL)			/*���ɷָ���ļ�����·��������*/
    {
        printf("Cannot open file\n");
        exit(0);
    }
    fseek(in, 0, 2);										/*��λ��ָ���Ƶ��ļ�ĩβ*/
    k = ftell(in);											/* k��ŵ�ǰλ�ã�Ҳ���������ļ��Ĵ�С */
    fseek(in, 0, 0);
    while (k > 0)
    {
        ch = fgetc(in);
        fputc(ch, out);
        byte++;											/*�ֽ�������*/
        k--;											/*��С��1*/
        if (byte == n)										/*��ΪҪ��Ĵ�Сʱִ�����������*/
        {
            fclose(out);									/*���һ���ָ�����ļ�*/
            byte = 0;										/*byte������0*/
            strcpy(filename, cfilename);						/*filename�ָ���ʼ״̬*/
            while (filename[j] != '.')
                j++;	
            filename[j] = '\0';								/*��'.'ʱ,�ڸô����ַ���������*/
            i++;
            if ((out = fopen(strcat(filename, ext[i]), "w")) == NULL)
													/*���ɷָ���ļ�����·��������*/
            {
                printf("Cannot open file\n");
                exit(0);
            }
        }
    }
    fclose(in);											/* �ر��ļ� */
    printf("File succeed space!\n\n\n");
}
main()												/* ���������� */
{
    printf(" now file space!\n");
    space();
}
