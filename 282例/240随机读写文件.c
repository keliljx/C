#include <stdio.h>
struct student_type											/*����ṹ��洢ѧ����Ϣ*/
{
    char name[10];
    int num;
    int age;
}stud[10];
void save(char *name, int n)										/*�Զ��庯��save*/
{
    FILE *fp;
    int i;
    if ((fp = fopen(name, "wb")) == NULL)							/*��ֻд��ʽ��ָ���ļ�*/
    {
        printf("cannot open file\n");
        exit(0);
    }
    for (i = 0; i < n; i++)
        if (fwrite(&stud[i], sizeof(struct student_type), 1, fp) != 1)		/*��һ�����������fp��ָ���ļ���*/
            printf("file write error\n");							/*���д���ļ����ɹ������������*/
    fclose(fp);											/*�ر��ļ�*/
}
main()
{
    int i, n;											/*��������Ϊ��������*/
    FILE *fp;											/*����һ��ָ��FILE���ͽṹ���ָ�����*/
    char filename[50];										/*����Ϊ�ַ���*/
    printf("please input filename:\n");
    scanf("%s", filename);									/*�����ļ�����·��������*/
    printf("please input the number of students:\n");
    scanf("%d", &n);										/*����ѧ����*/
    printf("please input name,number,age:\n");
    for (i = 0; i < n; i++)									/*����ѧ����Ϣ*/
    {
        printf("NO%d", i + 1);
        scanf("%s%d%d", stud[i].name, &stud[i].num, &stud[i].age);
        save(filename, n);									/*���ú���save*/
    } if ((fp = fopen(filename, "rb")) == NULL)					/*��ֻ����ʽ��ָ���ļ�*/
    {
        printf("can not open file\n");
        exit(0);
    }
    for (i = 0; i < n; i += 2)
    {
        fseek(fp, i *sizeof(struct student_type), 0);					/*����i�ı仯���ļ���ʼ��������ļ�*/
        fread(&stud[i], sizeof(struct student_type), 1, fp);	
        printf("%-10s%5d%5d\n", stud[i].name, stud[i].num, stud[i].age);
    }
    fclose(fp);											/*�ر��ļ�*/
}
