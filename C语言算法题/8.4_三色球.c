main()
{
	int r,y,g,k=0;
	printf("red  yellow  green\n");
	for(r=0;r<=3;r++)			/*红球的可能个数*/
		for(y=0;y<=3;y++)
			for(g=2;g<=6;g++)
				if(r+y+g==8)	/*满足条件红黄绿三色球之和为8*/
				{
					printf("%d\t%d\t%d\t\n",r,y,g);
					k++;		/*累加可能的种类个数*/
				}
				printf("\n总共有%d中可能！\n",k);
}