#include <stdio.h>
main()
{
	int a[20], max, min, i, j, k, n; 						/*�������鼰������������Ϊ��������*/
	j=0; k=0;
	printf("please input the nunber of elements:\n");
	scanf("%d", &n); 									/*����Ҫ�����Ԫ�ظ���*/
	printf("please input the element:\n");
	for (i = 0; i < n; i++)								/*��������*/
		scanf("%d", &a[i]);
	min = a[0];
	for (i = 1; i < n; i++)								/*�ҳ���������С����*/
		if (a[i] < min)
		{
			min = a[i];
			j = i; 									/*����С�����洢��λ�ø���j*/
		}
	max = a[0];
	for (i = 1; i < n; i++)								/*�ҳ����������е������*/
		if (a[i] > max)
		{
			max = a[i];
			k = i; 									/*�������˵�洢��λ�ø���k*/
		}
	printf("\nthe position of min is:%3d\n", j);			/*���ԭ��������С�����ڵ�λ��*/
	printf("the min number is:%3d\n", min);
	printf("the position of max is:%3d\n", k);				/*���ԭ��������������ڵ�λ��*/
	printf("the max number is:%3d\n", max);
	return 0;
}
