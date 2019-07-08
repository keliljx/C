main()
{
  int x,y,z,x1,y1,z1,i,k,n,j=0;					/*定义变量的数据类型*/
  while(1)	
  {
    printf("please input an integer\n");
    scanf("%d",&n);						/*输入函数获得n的值*/
    if(n<=10||n>=100)						/*当输入的数小于等于10或大于等于100时输出错误*/
    {
      printf("data error\n");
      continue;							/*跳出本次循环*/
    }
    else 
    if(n%10==0)							/*当这个两位数对10取余等于0时输出错误*/
    {  
    printf("data error\n");
    continue;								/*跳出本次循环*/
    }
    else
    {
      x=n/10;							/*x为输入的两位数中的十位*/
      y=n%10;							/*y为输入的两位数中的个位*/
      z=10*y+x;							/*z为n的对调数*/
      break;								/*跳出循环*/
    }
  }
  for(i=11;i<100;i++)						/*i遍历所有的两位数*/
  {
    if(i%10==0)							/*除去所有的对调数是个位的数*/
    continue;								/*结束本次循环*/
    else
    {
      x1=i/10;							/*x1为i的十位*/
      y1=i%10;							/*y1为i的个位*/
      z1=10*y1+x1;						/*z1为i的对调数*/
      if(n+i==z+z1&&n!=z1)				/*当满足n加i等于n的对调数加i的对调数且n和i不互为对调数*/
      {
        printf("%d+%d=%d+%d\n",n,i,z,z1);/*输出题中要求的表达式形式*/
        j++;								/*j自加*/
      }
      else
      continue;							/*否则结束本次循环*/
    }
  }
  if(j==0)								/*判断j是否等于0*/
  printf("inexistence!!\n");					/*条件成立输出不存在*/
}
