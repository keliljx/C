#include <stdio.h>
#include <stdlib.h>
	void move(char x,char y){
	printf("%c-->%c",x,y);
	printf("\n");
	}
	/*将n个盘子从第一座借助第二座移到第三座*/
	void hanoit(int n,char one,char two,char three){
	if(n==1){                                /*如果只有一个盘子*/
			move(one,three);
	}
	else{
			hanoit(n-1,one,three,two);      /*将一上的盘子借助三移到二上*/
			move(one,three);
			hanoit(n-1,two,one,three);      /*将二上的盘子借助一移到三上*/
	}
	}	
int main()
{
    int m;
	printf("请输入你要移动的盘子数：");
	scanf("%d",&m);
	printf("移动%d个盘子的步骤如下",m);
	hanoit(m,'A','B','C');
    system("PAUSE");	
    return 0;
}
