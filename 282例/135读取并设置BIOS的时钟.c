#include <bios.h>
#include <stdio.h>
main()
{
	long origin, new;
	origin = biostime(0, 0); 									/*����biostime������ȡʱ�ӵĵ�ǰֵ*/
	printf("\nthe current time is %ld \n", origin); 				/*����ȡ�ĵ�ǰֵ���*/
	new = biostime(1, 500); 								/*����bios��ʱ��*/
	printf("the new time is %ld", new); 						/*������ú��ʱ��*/
}
