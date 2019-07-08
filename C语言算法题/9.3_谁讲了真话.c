#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a, b, c;
    for (a = 0; a <= 1; a++)									/*对a,b,c说真话1说假话0两种情况逐一探测*/
        for (b = 0; b <= 1; b++)
            for (c = 0; c <= 1; c++)
                if ((a && !b || !a && b) && (b && !c || !b && c) && (c && !(a +
                    b) || !c && (a + b)))						/*满足括号内条件的进行输出*/
    {
        printf("the result(1-truth,0-lie):\n");
        printf("A is %d\nB is %d\nC is %d\n", a, b, c);			/*输出最终结果1代表说真话，0代表说假话*/
    }
         system("PAUSE");	
  return 0;
}
