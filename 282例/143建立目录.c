#include <dir.h>
#include <stdio.h>
main()
{
	if (!mkdir("temp"))									/*���ú���ӦtempΪ·��������һ��Ŀ¼*/
		printf("directory test is created\n");				/*Ŀ¼���������ʾ��Ϣ*/
	else
	{
		printf("unable to create new directory\n");			/*Ŀ¼δ����Ҳͬ�������ʾ��Ϣ*/
		exit(1);
	}
	getch();
}
