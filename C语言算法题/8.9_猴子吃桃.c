main()
{
	int sum=1,i;
	for(i=9;i>=1;i--)/*从第九天往回推*/
		sum=(sum+1)*2;/*递推公式*/
	printf("桃子的数量为%d个\n",sum);
}