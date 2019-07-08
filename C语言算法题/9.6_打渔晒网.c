#include <stdio.h>
#include <stdlib.h>
int leap(int a) 								/*�Զ��庯��leap����ָ������Ƿ�Ϊ����*/
{
    if (a % 4 == 0 && a % 100 != 0 || a % 400 == 0)		/*�����ж�����*/
        return 1;							/*�������귵��1*/
    else
        return 0;							/*�������귵��0*/
}
int number(int year, int m, int d)					/*�Զ��庯��number�����������ھ�2000��1��1�չ��ж�����*/
{
    int sum = 0, i, j, k, a[12] =
    {
        31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
    };								/*����a���ƽ��ÿ�µ�����*/
    int b[12] =
    {
        31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
    };							 	/*����b�������ÿ�µ�����*/
    if (leap(year) == 1)					/*�ж��Ƿ�Ϊ����*/
        for (i = 0; i < m - 1; i++)
            sum += b[i];					/*�����꣬�ۼ�����bǰm-1���·�����*/
    else
        for (i = 0; i < m - 1; i++)
            sum += a[i];					/*�������꣬�ۼ�����aǮm-1���·�����*/
    for (j = 2000; j < year; j++)
        if (leap(j) == 1)
            sum += 366;					/*2000�굽��������������ļ�366*/
    else
        sum += 365;						/*2000�굽�������ݲ�������ļ�365*/
    sum += d; 							/*��ǰ���ۼӵĽ���������ڣ����������*/
    return sum; 							/*���������������*/
}
int main()
{
    int year, month, day, n;
    printf("please input year,month,day\n");
    scanf("%d%d%d", &year, &month, &day); 	/*����������*/
    n = number(year, month, day); 			/*���ú���number*/
    if ((n % 5) < 4 && (n % 5) > 0)		/*��������1��2��3ʱ˵���ڴ��������ɹ��*/
        printf("%d:%d:%d is fishing\n", year, month, day);
    else
        printf("%d:%d:%d is basking\n", year, month, day);
        
         system("PAUSE");	
  return 0;
}
