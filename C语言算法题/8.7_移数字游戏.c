#include<stdio.h>
paixu(int f[])
{
	int i,j,t;
	for(i=0;i<7;i++)			/*ð������*/
		for(j=0;j<7-i;j++)
			if(f[j]>=f[j+1])	/*�������ֱȽ�*/
			{
				t=f[j];			/*����*/
				f[j]=f[j+1];
				f[j+1]=t;
				printf("*%d-->*0\t",j+1);/*����ƶ�����*/
				printf("*%d-->*%d\t",j+2,j+1);
				printf("*0-->*%d\t",j+2);
			}
			printf("\n");
} 
show(int a[])
{/*��ʾ�Ź���*/

	printf("%d--%d--%d\n",a[0],a[1],a[2]);
	printf("|%c | %c|\n",92,47);
	printf("%d--#--%d\n",a[7],a[3]);
	printf("|%c | %c|\n",47,92);
	printf("%d--%d--%d\n",a[6],a[5],a[4]);
}
main()
{
	int i,m[8];
	printf("������˳������8��������1~8��\n");
	for(i=0;i<8;i++)
		scanf("%d",&m[i]);
	printf("���ʼ���ݾ���Ϊ��\n");
	show(m);
	printf("\n�ƶ����裺\n");
	paixu(m);
	printf("�����ƶ������\n");
	show(m);
	getche();
}