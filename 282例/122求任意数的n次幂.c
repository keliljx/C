#include <stdio.h>
#include <math.h>
main()
{
	float x, n;
	int i;
	printf("please input the base:\n");
	scanf("%f", &x); 											/*�������x*/
	printf("please input the power:\n");
	scanf("%f", &n); 											/*���������*/
	for (i = 1; i <= 5; i++)
	{
		printf("%.1f^%.1f is %.3f\n", x, n, pow(x, n));				/*������Ľ�����*/
		n += 1;
	}
	getch();
}
