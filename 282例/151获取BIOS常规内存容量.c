#include <stdio.h> 
#include <bios.h>
main() 
{ 
	int memsize;											/*�������ͱ���*/
	memsize=biosmemory();								/*��ȡBIOS�����ڴ�����*/
	printf("\nBIOS regular memory size is %dKb",memsize);		/*���BIOS�����ڴ�����ֵ*/
	getch();
}
