#include <stdio.h>
#include <stdlib.h>
 int main()
{
    int i = 1, j = 0, n = 0, a[14] ={0};							/*Ϊ������Ԫ�ظ���ֵΪ0*/
    while (i <= 13)
    {
        while (1)
        {
            j++;
            if (j > 13)									/*��j����13�ǣ�����������1*/
                j = 1;
            if (!a[j])										/*�����λ��Ԫ��Ϊ0��n��1*/
                n++;
            if (n == i)
            {
                a[j] = i;									/*��i��ֵ��������ָ��λ����*/
                n = 0;									/*������������0*/
                break;									/*�����ڲ�ѭ��*/
            }
        }
        i++;											/*������1*/
    }
    printf("the original order of cards is:\n");
    for (i = 1; i <= 13; i++)
        printf("%3d", a[i]);									/*����˿���ԭ��˳��*/
    system("PAUSE");	
  return 0;
}
