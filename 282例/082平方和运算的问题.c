#include<stdio.h>
main()
{
	long a[10], n, i; 											/*�������鼰����Ϊ��������*/
	p: printf("please input a number:\n");
	scanf("%ld", &n); 										/*�Ӽ���������һ����n*/
	if (n == 0)												/*����������Ϊ0����������*/
		goto p;
	while (n != 1 && n != 145)
	{
		printf("n=%ld->", n);
		i = 1;
		while (n > 0)
		{
			a[i++] = n % 10; 									/*��n�ĸ�λ���ִ�ŵ�����a��*/
			n /= 10;
		}
		n = 0;
		i--;
		while (i >= 1)											/*ʹ��while��佫����������*/
		{
			printf("%ld*%ld", a[i], a[i]);
			if (i > 1)
				printf("+");
			n += a[i] *a[i];
			i--;
		}
		printf("=%ld\n", n); 									/*��������õ�ƽ����n���*/
	}
	getch();
}
