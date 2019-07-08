main()
{
	int x,y,z;
	printf("满足百钱买白鸡条件的鸡翁、鸡母、鸡雏的个数！\n");
	printf("鸡翁x\t鸡母y\t鸡雏z\t\n");
	for(x=4;x<=19;x+=4)
	{
		y=25-7*x/4;
		z=75+3*x/4;
		if(y>0&&y<=32&&z<=98)
			printf("  %d\t%d\t%d\t\n",x,y,z);
	}
}