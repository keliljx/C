#include <stdio.h>
main()
{
    FILE *fp; /*����һ��ָ��FILE���ͽṹ���ָ�����*/
    char str[100], s[100], filename[50]; /*��������Ϊ�ַ���*/
    printf("please input string!\n");
    gets(str); /*����ַ���*/
    printf("please input filename:\n");
    scanf("%s", filename); /*�����ļ�����·��������*/
    if ((fp = fopen(filename, "wb")) != NULL)
     /*��ֻд��ʽ��ָ���ļ�*/
    {
        fputs(str, fp); /*���ַ�����str�е��ַ��������fpָ����ļ�*/
        fclose(fp);
    }
    else
    {
        printf("cannot open!");
        exit(0);
    }
    if ((fp = fopen(filename, "rb")) != NULL)
    {
        while (fgets(s, sizeof(s), fp))
         /*��fp��ָ���ļ��ж����ַ�������s��*/
            printf("%s", s);
         /*���ַ������*/

        fclose(fp); /*�ر��ļ�*/
    }
}
