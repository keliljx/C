#include <ctype.h>
#include <stdio.h>
main()
{
	char ch, ch1;
	while (1)
	{
		printf("input the character('q' to quit):");
		ch = getchar(); 									/*�Ӽ����л��һ���ַ�*/
		ch1 = getchar(); 									/*ch1���մӼ���������Ļس�*/
		if (ch == 'q' || ch == 'Q')								/*�ж�������ַ��ǲ���q��Q*/
			break;										/*�����q��Q����ѭ��*/
		if (isalpha(ch))										/*���������Ƿ�����ĸ*/
			printf("\n%c is a letter.\n\n", ch);
		else
			printf("\n%c is not a letter.\n\n", ch);
	}
}
