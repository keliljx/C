main()
{
	int x,y,z;
	printf("�����Ǯ��׼������ļ��̡���ĸ�������ĸ�����\n");
	printf("����x\t��ĸy\t����z\t\n");
	for(x=1;x<=19;x++)
		for(y=1;y<=32;y++)
			for(z=3;z<=98;z+=3)
			if(x+y+z==100&&5*x+3*y+z/3==100)
			{
			printf("  %d\t%d\t%d\t\n",x,y,z);
				break;
			}
	

}