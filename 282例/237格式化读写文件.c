#include <stdio.h>
main()
{
    int i, flag = 1;								/*�������Ϊ��������*/
    char str[80], filename[50];						/*��������Ϊ�ַ���*/
    FILE *fp; 									/*����һ��ָ��FILE���ͽṹ���ָ�����*/
    printf("please input filename:\n");
    scanf("%s", filename);							/*�����ļ�����·��������*/
    if ((fp = fopen(filename, "w")) == NULL)				/*��ֻд��ʽ��ָ���ļ�*/
    {
        printf("cannot open!");
        exit(0);
    }
    while (flag == 1)
    {
        printf("\nInput string:\n");
        scanf("%s", str);								/*�����ַ���*/
        fprintf(fp, "%s", str);							/*��str�ַ���������%s��ʽд��fp��ָ�ļ���*/
        printf("\nContinue:?");
        if ((getchar() == 'N') || (getchar() == 'n'))				/*����n��������*/
            flag = 0;									/*��־λ��0*/
    }
    fclose(fp);										/*�ر��ļ�*/
    fp = fopen(filename, "r");							/*��ֻд����ʽ��ָ���ļ�*/
    while (fscanf(fp, "%s", str) != EOF)						/*��fp��ָ���ļ�����%s��ʽ�����ַ���*/
    {
        for (i = 0; str[i] != '\0'; i++)
            if ((str[i] >= 'a') && (str[i] <= 'z'))
                str[i] -= 32;							/*��Сд��ĸת��ΪСд��ĸ*/
        printf("\n%s\n", str);							/*���ת������ַ���*/
    }
    fclose(fp);										/*�ر��ļ�*/
}
