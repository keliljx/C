#include <stdio.h>
#include <math.h>
main()
{
	float a, b, c;
	printf("please input two orthogonal sides:\n");
	scanf("%f,%f", &a, &b);									/*�Ӽ�������������ֱ�Ǳ�*/
	c = hypot(a, b);										/*����hypot����������б��ֵ����c*/
	printf("hypotenuse is:%f\n", c);							/*��б��ֵ���*/
	getch();
}
