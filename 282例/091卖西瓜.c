#include<stdio.h>
void main()
{
    int day, x1, x2;
    day = 0; 												/*����*/
    x1 = 1020; 												/*�ϵ�������*/
    while (x1)
    {
        x2 = x1 / 2-2; 										/*����һ�������*/
        x1 = x2;
        day++;												/*������1*/
    }
    printf("day=%d\n", day); 									/*��������1*/
}
