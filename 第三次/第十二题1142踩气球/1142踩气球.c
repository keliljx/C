#include<stdio.h>
int flag1, flag2;	//分别表示n, m是否已被成功分解
void dfs(int n, int m, int fac){
	if(flag1)	//如果n, m均可分解且因子不同
		return;
	if(n == 1 && m == 1){	//n, m均分解完
		flag1 = 1;
		flag2 = 1;
		return;
	}
	if(m == 1){ //m分解完
		flag2 = 1;
	}
	if (fac < 2)
		return;
	if(n % fac == 0)	//精华之处，对同一个因子不同时分解n, m，难点解决
		dfs(n / fac, m, fac - 1);
	if(m % fac == 0)
		dfs(n, m / fac, fac - 1);
	dfs(n, m, fac - 1);
}

int main(){
	int n, m,i;
	int a[1000];
	int num=0;
	while(1){
	    scanf("%d%d", &m, &n);
        if(m==0&&n==0)
        {
            break;
        }
		if(m > n){ //交换m, n
			int t= m ;
			m =  n;
			n = t;
		}
		flag1 = 0;
		flag2 = 0;
		dfs(n, m,100);
		if(flag1 || !flag2)	//如果n成功分解货m无法成功分解
			a[num]=n;
		else
			a[num]=m;
        num++;
	}

	for(i=0;i<num;i++)
    {
        printf("%d\n",a[i]);
    }
	return 0;
}
