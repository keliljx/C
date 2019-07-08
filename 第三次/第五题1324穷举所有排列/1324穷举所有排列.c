# include <stdio.h>
char a[11];
void init();
void print();
int n;
void search(int s);

int main()
{
    scanf("%d",&n);
    init();
    search(0);
    return 0;
}


void init()
{
    int i;
    for(i=0; i<n; i++)
    {
        a[i]='a'+i;
    }
}
void search(int m)
{
    int i;
    if(m==n-1)
    {
        print();
    }
    else
    {
        for(i=m; i<n; i++)
        {
            char t;
            t=a[m];
            a[m]=a[i];
            a[i]=t;
            search(m+1);
            t=a[m];
            a[m]=a[i];
            a[i]=t;
        }
    }
}

void print()
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("%c",a[i]);
    }
    printf("\n");
}
