#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a, b, c;
    for (a = 0; a <= 1; a++)									/*��a,b,c˵�滰1˵�ٻ�0���������һ̽��*/
        for (b = 0; b <= 1; b++)
            for (c = 0; c <= 1; c++)
                if ((a && !b || !a && b) && (b && !c || !b && c) && (c && !(a +
                    b) || !c && (a + b)))						/*���������������Ľ������*/
    {
        printf("the result(1-truth,0-lie):\n");
        printf("A is %d\nB is %d\nC is %d\n", a, b, c);			/*������ս��1����˵�滰��0����˵�ٻ�*/
    }
         system("PAUSE");	
  return 0;
}
