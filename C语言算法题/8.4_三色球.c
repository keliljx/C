main()
{
	int r,y,g,k=0;
	printf("red  yellow  green\n");
	for(r=0;r<=3;r++)			/*����Ŀ��ܸ���*/
		for(y=0;y<=3;y++)
			for(g=2;g<=6;g++)
				if(r+y+g==8)	/*���������������ɫ��֮��Ϊ8*/
				{
					printf("%d\t%d\t%d\t\n",r,y,g);
					k++;		/*�ۼӿ��ܵ��������*/
				}
				printf("\n�ܹ���%d�п��ܣ�\n",k);
}