#include <stdio.h>
main()
{
    FILE *fp1,  *fp2;									/*��������ָ��FILE���ͽṹ���ָ�����*/
    char filename1[50], filename2[50], ch;					/*�������鼰����Ϊ�ַ���*/
    long character, space, other, digit;						/*�������Ϊ������*/
    character = space = digit = other = 0;					/*�����α����ĳ�ֵ��Ϊ0*/
    printf("Enter file name \n");
    scanf("%s", filename1);								/*����Ҫ����ͳ�Ƶ��ļ���·��������*/
    if ((fp1 = fopen(filename1, "r")) == NULL)
     /*��ֻ����ʽ��ָ���ļ�*/
    {
        printf("cannot open file\n");
        exit(1);
    }
    printf("Enter file name for write data:\n");
    scanf("%s", filename2);								/*�����ļ�������ͳ�ƽ���ŵ��Ǹ��ļ���*/
    if ((fp2 = fopen(filename2, "w")) == NULL)				/*�Կ�д��ʽҪ���ͳ�ƽ�����ļ�*/
    {
        printf("cannot open file\n");
        exit(1);
    }
    while ((ch = fgetc(fp1)) != EOF)						/*֪���ļ����ݽ�����ֹͣwhileѭ��*/
        if (ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z')
            character++;								/*��������ĸʱ�ַ�������1*/
    else if (ch == ' ')
        space++;									/*�������ո�ʱ�ո�����1*/
    else if (ch >= '0' && ch <= '9')
        digit++;									/*����������ʱ��������1*/
    else
        other++;									/*���������ַ�ʱ�����ַ�����1*/
    close(fp1);										/*�ر�fp1ָ����ļ�*/
    fprintf(fp2, "character:%ld space:%ld digit:%ld other:%ld\n", character,
        space, digit, other);								/*��ͳ�ƽ��д��fpָ��Ĵ����ļ���*/
    fclose(fp2);										/*�ر�fp2ָ����ļ�*/
}
