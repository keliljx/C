#include <stdio.h>
#include <stdlib.h>
void error(int e)/*�Զ���error�����жϳ��������*/
{
	if(e == 0)
		printf("input error\n");
	else
		printf("output error\n");
	exit(1);    /* �������� */
}
main()
{
    FILE *in,  *out; /*��һ�����ļ�����ָ��in��out*/
    int tab, i;
    char ch, filename1[30], filename2[30];
    printf("please input the filename1:");
    scanf("%s", filename1); /*�����ļ�·��������*/
    printf("please input the filename2:");
    scanf("%s", filename2); /*�����ļ�·��������*/
    if ((in = fopen(filename1, "rb")) == NULL)
    {
        printf("can not open the file %s��\n", filename1);
        exit(1);
    }
    if ((out = fopen(filename2, "wb")) == NULL)
    {
        printf("can not open the file %s��\n", filename2);
        exit(1);
    }
    tab = 0;
    ch = fgetc(in); /*��ָ�����ļ��ж�ȡ�ַ�*/
    while (!feof(in))
     /*����Ƿ��ж������*/
    {
        if (ferror(in))
            error(0);
        if (ch == '\t')
         /*��������Ʊ�����������ͬ��Ŀ�Ŀո��*/
        {
            for (i = tab; i < 8; i++)
            {
                putc(' ', out);
                if (ferror(out))
                    error(1);
            }
            tab = 0;
        }
        else
        {
            putc(ch, out);
            if (ferror(out))
             /*����Ƿ����������*/
                error(1);
            tab++;
            if (tab == 8)
                tab = 0;
            if (ch == '\n' || ch == '\r')
                tab = 0;
        }
        ch = fgetc(in);
    }

    fclose(in);
    fclose(out);
}
