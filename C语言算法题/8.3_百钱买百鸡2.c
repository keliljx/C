main()
{
	int x,y,z;
	printf("�����Ǯ��׼������ļ��̡���ĸ�������ĸ�����\n");
	printf("����x\t��ĸy\t����z\t\n");
	for(x=4;x<=19;x+=4)
	{
		y=25-7*x/4;
		z=75+3*x/4;
		if(y>0&&y<=32&&z<=98)
			printf("  %d\t%d\t%d\t\n",x,y,z);
	}
}