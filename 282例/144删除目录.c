#include <dir.h>
#include <stdio.h>
main()
{
	char *name[10]; 											/*�����ַ�������洢�ļ���*/
	printf("please input directory name:\n");
	scanf("%s", name); 										/*�����ļ���*/
	printf("Press any key,and the directory will be removed\n");
	getch();
	if (!rmdir(name))											/*ɾ��Ŀ¼*/
		printf("Directory is removed.\n");							/*ɾ���ɹ������ʾ��Ϣ*/
	else
		printf("can not remove");								/*ɾ�����ɹ������ʾ��Ϣ*/
	getch();
}
