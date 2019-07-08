#include <stdio.h>
int main()
{
    int a,b,c;
    for(a=0; a<=1; a++)
        for(b=0; b<=1; b++)
            for(c=0; c<=1; c++)
                if((a==1&&b==0 || a==0&&b==1) && (b==1&&c==0 || b==0&&c==1) && (c==1&&a+b==0 || c==0&&a+b==1))
                {
                    if(a==1)
                        printf("0\n");
                    else if(b==1)
                        printf("1\n");
                    else if(c==1)
                        printf("2\n");
                }
    return 0;
}
