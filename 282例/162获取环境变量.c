#include <stdio.h>
#include <dos.h>

int main(void)
{
   char *path, *ptr;
   int i = 0;
   
   puts(" This program is to get the information of environ.");
   /* ��õ�ǰ���������е�path��Ϣ */

   while (environ[i]) /*ѭ��������еĻ�������*/
       printf(" >> %s\n",environ[i++]);
   printf(" Press any key to quit...");
   getch();
   return 0;
}