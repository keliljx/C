#include <stdio.h>
#include <math.h>
main()
{
	float i, k; 										/*�������i��kΪ��������*/
	printf("please input a number:\n");
	scanf("%f", &i); 									/*����һ������������i*/
	printf("the result is:\n");
	printf("%f", ceil(i)); 								/*����ceil�����������С��i����С����*/
	printf("\n");
	return 0;
}
