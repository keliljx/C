#include<stdio.h>
int flag1, flag2;	//�ֱ��ʾn, m�Ƿ��ѱ��ɹ��ֽ�
void dfs(int n, int m, int fac){
	if(flag1)	//���n, m���ɷֽ������Ӳ�ͬ
		return;
	if(n == 1 && m == 1){	//n, m���ֽ���
		flag1 = 1;
		flag2 = 1;
		return;
	}
	if(m == 1){ //m�ֽ���
		flag2 = 1;
	}
	if (fac < 2)
		return;
	if(n % fac == 0)	//����֮������ͬһ�����Ӳ�ͬʱ�ֽ�n, m���ѵ���
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
		if(m > n){ //����m, n
			int t= m ;
			m =  n;
			n = t;
		}
		flag1 = 0;
		flag2 = 0;
		dfs(n, m,100);
		if(flag1 || !flag2)	//���n�ɹ��ֽ��m�޷��ɹ��ֽ�
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
