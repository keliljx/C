#include <stdio.h>
#include <dir.h>
main()
{
	char *filename="mingriXXXXXX",*p;					/*Ϊfilename��ֵ*/
	p=mktemp(filename);								/*���ú�������Ψһ�ļ���������ֵ����p*/
	printf("%s\n",p);
	getch();
}
