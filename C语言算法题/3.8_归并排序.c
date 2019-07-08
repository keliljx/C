#include<stdio.h>
void merge(int r[], int s[], int x1, int x2, int x3) 		/*ʵ��һ�ι鲢������*/
{
    int i, j, k;
    i = x1; 										/*��һ���ֵĿ�ʼλ��*/
    j = x2 + 1; 									/*�ڶ����ֵĿ�ʼλ��*/
    k = x1;
    while ((i <= x2) && (j <= x3))
     											/*��i��j��������Ҫ�ϲ��Ĳ�����*/
        if (r[i] <= r[j])
     											/*ɸѡ�������н�С��Ԫ�طŵ�����s��*/
    {
        s[k] = r[i];
        i++;
        k++;
    }
    else
    {
        s[k] = r[j];
        j++;
        k++;
    }
    while (i <= x2)
    											/*��x1~x2��Χ�ڵ�δ�Ƚϵ���˳�μӵ�����r��*/
        s[k++] = r[i++];
    while (j <= x3)
     											/*��x2+1~x3��Χ�ڵ�δ�Ƚϵ���˳�μӵ�����r��*/
        s[k++] = r[j++];
}

void merge_sort(int r[], int s[], int m, int n)
{
    int p;
    int t[20];
    if (m == n)
        s[m] = r[m];
    else
    {
        p = (m + n) / 2;
        merge_sort(r, t, m, p);
            									/*�ݹ����merge_sort������r[m]~r[p]�鲢�������t[m]~t[p]*/
        merge_sort(r, t, p + 1, n);					/*�ݹ����merge_sort������r[p
            +1]~r[n]�鲢�������t[p+1]~t[n]*/
        merge(t, s, m, p, n); 						/*���ú�����ǰ�����ֹ鲢��s[m]~s[n]*/
    }
}

main()
{
    int a[11];
    int i;
    printf("please input 8 numbers:\n");
    for (i = 1; i <= 8; i++)
        scanf("%d", &a[i]);
     									/*�Ӽ���������8����*/
    merge_sort(a, a, 1, 8);					 /*����merge_sort�������й鲢����*/
    printf("the sorted numbers:\n");
    for (i = 1; i <= 8; i++)
        printf("%5d", a[i]);
   									/*�������Ľṹ���*/
	getch();
}

