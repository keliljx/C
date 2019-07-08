int main()
{
	int x,a,b,c;
	scanf("%d%d%d",&a,&b,&c);/*输入军队三次整队后的队尾人数*/
for(x=10;x<=100;x++)
	if(x%3==a&&x%5==b&&x%7==c)/*判断军队人数是否满足此条件*/
	{
		printf("x=%d\n",x);	/*输出满足条件的军队人数*/
		break;				/*找到最小的军队人数，跳出循环*/
	}		
if(x>100)					/*若在遍历x所有数后，仍没有符合条件的，则输出无答案*/
   printf("no answer\n");
return 0;
}