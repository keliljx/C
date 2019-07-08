# include<stdio.h>
# include<math.h>
int main()
{
    float x1,y1,x2,y2,x3,y3;
    scanf("%f %f",&x1,&y1);

    scanf("%f %f",&x2,&y2);

    scanf("%f %f",&x3,&y3);
    printf("\n");
    float a = (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
    float b = (x3-x1)*(x3-x1)+(y3-y1)*(y3-y1);
    float c = (x3-x2)*(x3-x2)+(y3-y2)*(y3-y2);
    if(a==b+c||b==a+c||c==a+b)
        printf("1\n");
    else
        printf("0\n");


    return 0;
}
