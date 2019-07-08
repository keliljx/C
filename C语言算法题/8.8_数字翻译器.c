char e1[19][10]={"one","two","three","four","five",
					"six","seven","eight","nine",
					"ten","eleven","twelve","thirteen",
					"fourteen","fifteen","sixteen",
					"seventeen","eighteen","nineteen"};		/*�洢1~19������*/
char e2[8][7]={"twenty","thirty","forty","fifty","sixty",
				"seventy","eighty","ninety"};				/*�洢20,30����90������*/
trans1(long m)												/*����ǧλ����*/
{
	long a1;
	if(m==0){printf("Zero\n");return;}
	a1=m/1000;                                              /*�����ǧλ����*/
	if(a1!=0)
	{
		trans2(a1);											/*���÷����λ*/
		printf(" thousand ");
	}
	a1=m%1000;
	if(a1!=0)
		trans2(a1);											/*�����λ*/
}
trans2(long m)
{
	long a2;
	a2=m/100;												/*�������λ����*/
	if(a2!=0)
	{
		trans3(a2);											/*���÷���ʮλ�͸�λ*/
		printf(" hundred ");
	}
	a2=m%100;
	if(a2!=0)
		trans3(a2);
}
trans3(long m)												/*����ʮλ�͸�λ*/
{
	long a3;
	if(m<=19)												/*�������e1�ڵ���*/
		printf("%s ",e1[m-1]);
	else
	{
		a3=m/10;
		printf("%s ",e2[a3-2]);								/*�������e2�ڵ���*/
		a3=m%10;
		if(a3!=0)
			printf("%s ",e1[a3-1]);
	}
}
main()
{
	long m;
	printf("������0~999999��Χ�ڵ�����\n");
	scanf("%ld",&m);
	printf("\n����ɣ�\n");
	trans1(m);
	printf("\n");

}