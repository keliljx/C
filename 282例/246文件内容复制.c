#include <stdio.h>
main()
{
    FILE *in,*out;									/*��������ָ��FILE���ͽṹ���ָ�����*/
    char ch, infile[50], outfile[50];							/*�������鼰����Ϊ��������*/
    printf("Enter the infile name:\n");
    scanf("%s", infile);								/*���뽫Ҫ�����Ƶ��ļ�����·��������*/
    printf("Enter the outfile name:\n");
    scanf("%s", outfile);								/*�����½��Ľ����ڸ��Ƶ��ļ�����·��������*/
    if ((in = fopen(infile, "r")) == NULL)					/*��ֻд��ʽ��ָ���ļ�*/
    {
        printf("cannot open infile\n");
        exit(0);
    }
    if ((out = fopen(outfile, "w")) == NULL)
    {
        printf("cannot open outfile\n");
        exit(0);
    }
    ch = fgetc(in);
    while (ch != EOF)
    {
        fputc(ch, out);								/*��inָ����ļ������ݸ��Ƶ�out��ָ����ļ���*/
        ch = fgetc(in);
    }
    fclose(in);
    fclose(out);
}
