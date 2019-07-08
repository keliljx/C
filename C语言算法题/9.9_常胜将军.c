#include <stdio.h>
#include <stdlib.h>

int main()
{
    int computerGet,peopleGet,spare=21;
        printf("*****************************************************\n");
        printf("************我是常胜将军，你可以挑战我***************\n");
        printf("*****************************************************\n\n");
        printf("注意！游戏开始了、、、、、\n\n");
    while(1)
    {
        printf("************火柴还剩下%d根*****************************\n",spare);
        printf("************请输入你要拿取的火柴数：*******************\n");
        scanf("%d",&peopleGet);
        if(peopleGet<1||peopleGet>4||peopleGet>spare)
        {
            printf("请遵守游戏规则，你拿取的火柴数有问题！\n\n");
            continue;                                             
        }         
        spare=spare-peopleGet;
        if(spare==0)
        {
            printf("\n 计算机赢了！游戏结束！\n");
            break;            
        }
        computerGet=5-peopleGet;
        spare=spare-computerGet;
        printf("计算机拿取的火柴数：%d \n",computerGet);
        if(spare==0)
        {
            printf("\n 你赢了！游戏结束！\n");
            break;            
        }
    }
    system("PAUSE");	
    return 0;
}
