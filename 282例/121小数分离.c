#include <stdio.h>
#include <math.h>
main()
{
	float number;
	double f, i;
	printf("input the number:");
	scanf("%f", &number); 									/*����Ҫ�ֽ��С��*/
	f = modf(number, &i); 									/*����modf�������з���*/
	printf("%f=%f+%f", number, i, f); 						/*�������Ľ����ָ����ʽ���*/
	getch();
        printf("\n");
	return 0;
}
