#include<stdio.h>
main()
{
	char c; 										/*����cΪ�ַ���*/
	int letters = 0, space = 0, digit = 0, others = 0;		/*����letters��space��digit��others���ĸ�����Ϊ��������*/
	printf("please input some characters\n");
	while ((c = getchar()) != '\n')						/*������Ĳ��ǻس�ʱִ��whileѭ���岿��*/
	{
		if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
			letters++;								/*���������Ӣ����ĸʱ����letters��1*/
		else if (c == ' ')
			space++;								/*��������ǿո�ʱ����space��1*/
		else if (c >= '0' && c <= '9')
			digit++;								/*�������������ʱ����digit��1*/
		else
			others++;							/*������ļ�����Ӣ����ĸ�ֲ��ǿո�������Ǳ���others��1*/
	}
	printf("char=%d space=%d digit=%d others=%d\n",letters,space,digit,others);		/*������ͳ�ƽ�����*/
}

