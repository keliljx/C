#include <stdio.h>
struct index 									/*�����Ľṹ*/
{
    int key;
    int start;
    int end;
} index[4]; 								/*����ṹ������*/
int search(int key, int a[]) 						/*�Զ���ʵ�ַֿ����*/
{
    int i, j;
    i = 0;
    while (i < 3 && key > index[i].key)			/*ȷ�����Ǹ�����*/
        i++;
    if (i >= 3)									/*���ڷֵõĿ������򷵻�0*/
        return -1;
    j = index[i].start; 							/*j���ڿ鷶Χ����ʼֵ*/
    while (j <= index[i].end && a[j] != key)			/*��ȷ���Ŀ��ڽ��в���*/
        j++;
    if (j > index[i].end)						/*������ڿ鷶Χ�Ľ���ֵ����˵��û��Ҫ���ҵ���,j��0*/
        j = -1;
    return j;
}
void main()
{
    int i, j = -1, k, key;                   /*�������*/
	int a[]={42,63,82,89,111,146,219,254,325,336,348,795,876,951,998};/*��֪��һ����*/
	printf("��֪��һ����\n");
	for(i=0;i<15;i++)
		printf("%d ",a[i]);      /*�����֪����*/
	printf("\n");
    for (i = 0; i < 3; i++)
    {
        index[i].start = j+1; 					/*ȷ��ÿ���鷶Χ����ʼֵ*/
        j = j + 1;
        index[i].end = j + 4; 					/*ȷ��ÿ���鷶Χ�Ľ���ֵ*/
        j = j + 4;
        index[i].key = a[j]; 					/*ȷ��ÿ���鷶Χ��Ԫ�ص����ֵ*/
    }
    printf("����������Ҫ���ҵ���:\n");
    scanf("%d", &key); 							/*����Ҫ��ѯ����ֵ*/
    k = search(key, a); 						/*���ú������в���*/
    if (k >= 0)
        printf("���ҳɹ�����Ҫ�ҵ����������е�λ����:%d\n", k+1);			/*����ҵ��������������λ��*/
    else
        printf("����ʧ�ܣ���Ҫ�ҵ������������С�\n");							/*��δ�ҵ��������ʾ��Ϣ*/
}
