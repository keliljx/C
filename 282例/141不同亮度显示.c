#include <conio.h>
main()
{
	clrscr();
	highvideo(); 										/*���ú������ַ��Ը�������ʾ*/
	gotoxy(10, 1);
	cprintf("This is high intensity text");
	lowvideo(); 										/*���ú������ַ��Ե�������ʾ*/
	gotoxy(10, 10);
	cprintf("This is low intensity text");
	normvideo(); 										/*���ú������ַ�������������ʾ*/
	gotoxy(10, 20);
	cprintf("This is normal intensity text");
	getch();
}
