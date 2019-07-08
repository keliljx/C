#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;
int n;
double xp,yp,zp,x1,y1_,z1,x2,y2,z2;
double p1x,p1y,p1z,p2x,p2y,p2z;
double len_p1,len_12,len_p2,v_cos1,v_cos2,v_sin,ans;
double temp1,temp2;


int  main()
{

    scanf("%d",&n);
    while(n--)
    {
        scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf",&xp,&yp,&zp,&x1,&y1_,&z1,&x2,&y2,&z2);
        len_p1 = sqrt(pow(xp - x1, 2) + pow(yp - y1_,2) +  pow(zp - z1,2));
        len_p2 = sqrt(pow(xp - x2, 2) + pow(yp - y2,2) +  pow(zp - z2,2));
        len_12 = sqrt(pow(x1 - x2, 2) + pow(y1_ - y2,2) +  pow(z1 - z2,2));

        if(len_p1 == 0 || len_p2 == 0)
            ans = 0;
        else if(len_12 == 0)
            ans = len_p1;
        else
        {
            p1x = xp - x1;
            p1y = yp - y1_;
            p1z = zp - z1;
            p2x = xp - x2;
            p2y = yp - y2;
            p2z = zp - z2;
            temp1 = sqrt(pow(p1x, 2) + pow(p1y, 2) + pow(p1z, 2));
            temp2 = sqrt(pow(p2x, 2) + pow(p2y, 2) + pow(p2z, 2));
            p1x /= temp1;
            p1y /= temp1;
            p1z /= temp1;
            p2x /= temp2;
            p2y /= temp2;
            p2z /= temp2;
            if(p1x == p2x && p1y == p2y && p1z == p2z || (((p1x + p2x) == 0) && ((p1y + p2y) == 0)
                    &&((p1z + p2z) == 0)))
                ans = min(len_p1, len_p2);
            else
            {
                v_cos1 = (pow(len_p1,2) + pow(len_12,2) - pow(len_p2, 2)) / (2 * len_p1 * len_12);
                v_cos2 = (pow(len_p2,2) + pow(len_12,2) - pow(len_p1, 2)) / (2 * len_p2 * len_12);
                v_sin = sqrt(1 - pow(v_cos1, 2));
                ans = len_p1 * v_sin;
                if(len_p1 * v_cos1 > len_12 || len_p2 * v_cos2 > len_12)
                    ans = min(len_p2, len_p1);
            }
        }
        printf("%0.2lf\n",ans);
    }

    return 0;
}
