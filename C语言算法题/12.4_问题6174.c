int num[2000],count;
 main()
{
	printf("����һ��������\n");
	scanf("%d",&num[0]);
	printf("%d",num[0]);
	count=1;
	while(1)
	{int i;int f=0;
		num[count]=next(num[count-1]);/*��num[count=1]���򣬼���õ���һ��ֵ*/
		printf("->%d",num[count]);/*�����һ��ֵ*/		
		for(i=0;i<count;i++)
			if(num[i]==num[count])/*�ӵ�0����ʼ�Ƚϣ����Ƿ�����ͬ������*/
			{
				f=1;break;/*������ͬ�ģ�f=1*/
			}
			if(f)/*����������ѭ��*/
				break;
			count++;
	}
	printf("\n");

}
int next(int x)
{
	int a,b,n,i,j;
	char s[10];
	sprintf(s,"%d",x);/*������ת�����ַ���*/
	n=strlen(s);		/*�ַ�������*/
	for(i=0;i<n;i++)	/*ð������*/
		for(j=i+1;j<n;j++)
			if(s[i]>s[j])
			{
				char t=s[i];s[i]=s[j];s[j]=t;
			}
			sscanf(s,"%d",&b);/*���ַ���sת��������b*/
			for(i=0;i<n/2;i++)/*��ת�ַ���*/
			{
				char t=s[i];
				s[i]=s[n-1-i];
				s[n-1-i]=t;
			}
			sscanf(s,"%d",&a);/*�����ַ���ת��������a*/
			return a-b;/*���ز�ֵ������һ����*/
} 