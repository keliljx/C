#include <stdio.h>
#include <dir.h>
#include <dos.h>
main()
{
    char str1[50], str2[50], filename[50]; 				/*��������Ϊ�ַ���*/
    int i, j = 0, k; 								/*�������Ϊ��������*/
    FILE *fp; 									/*����һ��ָ��FILE���ͽṹ���ָ�����*/
    struct ffblk fileinf;
    printf("please input filename which do you want to save:");
    gets(filename); 							
											/*��������ļ�·�������ƣ����ļ���������ͳ�Ƴ��Ľ��*/
    fp = fopen(filename, "w+");
    printf("Please input directory:\n");					/*��ʾ����Ŀ¼*/
    gets(str1);									/*����Ҫ����ͳ�Ƶ��ļ�����Ŀ¼*/
    k = chdir(str1); 								/*�л���ǰ����Ŀ¼,��ȷ����0*/
    if (k != 0)									/*���������0,��ʾ��Ϣ���˳�*/
    {
        printf("Change Path failure!\n");
        getch();
        exit( - 1);
    }

    printf("\nPlease input File type:\n");
    gets(str2); 											/*����Ҫ����ͳ�Ƶ��ļ������ͣ��磺*.doc*/
    i = findfirst(str2, &fileinf, FA_ARCH); 						/*����ƥ�������ĵ�һ���ļ�,��ȷ����0*/
    if (i != 0)											/*�������ֵ��Ϊ0,��ʾ��Ϣ���˳�*/
    {
        printf("File Not Find!\n");
        getch();
        exit( - 1);
    }
    else
    {
        printf("\n");
        printf("%s\n", fileinf.ff_name); 						/*����Ļ�ϴ�ӡ*/
        fputs(fileinf.ff_name, fp); 							/*������ļ�*/
        fputs("\n", fp); 									/*������з����ļ�*/
        while (j == 0)										/*ѭ������,ֱ��findnext������0*/
        {
            j = findnext(&fileinf);							/*������findfirst��ƥ����ļ�*/
            if (j == 0)
             /*����ҵ�*/
            {
                printf("%s\n", fileinf.ff_name);					/*����Ļ�ϴ�ӡ*/
                fputs(fileinf.ff_name, fp);						/*������ļ�*/
                fputs("\n", fp);								/*������з����ļ�*/
            } 
        }
    }
    fclose(fp); 											/*�ر��ļ�*/
}
