/*
�ж������ķ�������һ�����ֱ�ȥ��2��sqrt(�����)��
����ܱ����������������������������֮��������
*/
#include<stdio.h>
#include<math.h>
int main()
{
    int n,i,k;
    scanf("%d",&n);
    k=sqrt(n);


    for(i=2; i<=k; i++)//ע���2��ʼ������1��ʼ���򶼷���
        if(n%i==0)
            break;
    if(i>k)
        printf("Yes\n");
    else
        printf("No\n");




    return 0;
}
