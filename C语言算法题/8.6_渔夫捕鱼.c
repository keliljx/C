int all(int i,int n)/*��������ܹ������ж�������*/
{
	int s=i;		/*��ʼֵ*/
	while(n)		/*���ƴ���*/
	{
		s=5*s+1;	/*���ƹ�ʽ*/
		n--;
	}
	return s;
}
main()
{
	int sum;
	sum=all(6,4);	/*����ܹ�����*/
	printf("���������ٺϻﲶ��%d���㣡\n",sum);	
}