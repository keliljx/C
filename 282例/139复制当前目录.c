#include <stdio.h>
#include <dos.h>
#include <dir.h>
main()
{
	char cdir[MAXDIR];
	strcpy(cdir, "c:\\");
	cdir[0] = 'A' + getdisk();								/*���ú������ص�ǰ������*/
	if (getcurdir(0, cdir + 3))								/*���ú�������ǰĿ¼������cdir+3��ʼ��������*/
	{
		printf("error");
		exit(1);
	}
	printf("the current directory is:%s\n", cdir);
	getch();
}
