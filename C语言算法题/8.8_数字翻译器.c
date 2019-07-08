char e1[19][10]={"one","two","three","four","five",
					"six","seven","eight","nine",
					"ten","eleven","twelve","thirteen",
					"fourteen","fifteen","sixteen",
					"seventeen","eighteen","nineteen"};		/*存储1~19的数组*/
char e2[8][7]={"twenty","thirty","forty","fifty","sixty",
				"seventy","eighty","ninety"};				/*存储20,30……90的数组*/
trans1(long m)												/*翻译千位数字*/
{
	long a1;
	if(m==0){printf("Zero\n");return;}
	a1=m/1000;                                              /*计算出千位数字*/
	if(a1!=0)
	{
		trans2(a1);											/*调用翻译百位*/
		printf(" thousand ");
	}
	a1=m%1000;
	if(a1!=0)
		trans2(a1);											/*翻译百位*/
}
trans2(long m)
{
	long a2;
	a2=m/100;												/*计算出百位数字*/
	if(a2!=0)
	{
		trans3(a2);											/*调用翻译十位和个位*/
		printf(" hundred ");
	}
	a2=m%100;
	if(a2!=0)
		trans3(a2);
}
trans3(long m)												/*翻译十位和个位*/
{
	long a3;
	if(m<=19)												/*输出数组e1内的数*/
		printf("%s ",e1[m-1]);
	else
	{
		a3=m/10;
		printf("%s ",e2[a3-2]);								/*输出数组e2内的数*/
		a3=m%10;
		if(a3!=0)
			printf("%s ",e1[a3-1]);
	}
}
main()
{
	long m;
	printf("请输入0~999999范围内的数！\n");
	scanf("%ld",&m);
	printf("\n翻译成：\n");
	trans1(m);
	printf("\n");

}