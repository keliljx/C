#include <stdio.h>
#include <stdlib.h>

int main()
{
    int computerGet,peopleGet,spare=21;
        printf("*****************************************************\n");
        printf("************���ǳ�ʤ�������������ս��***************\n");
        printf("*****************************************************\n\n");
        printf("ע�⣡��Ϸ��ʼ�ˡ���������\n\n");
    while(1)
    {
        printf("************���ʣ��%d��*****************************\n",spare);
        printf("************��������Ҫ��ȡ�Ļ������*******************\n");
        scanf("%d",&peopleGet);
        if(peopleGet<1||peopleGet>4||peopleGet>spare)
        {
            printf("��������Ϸ��������ȡ�Ļ���������⣡\n\n");
            continue;                                             
        }         
        spare=spare-peopleGet;
        if(spare==0)
        {
            printf("\n �����Ӯ�ˣ���Ϸ������\n");
            break;            
        }
        computerGet=5-peopleGet;
        spare=spare-computerGet;
        printf("�������ȡ�Ļ������%d \n",computerGet);
        if(spare==0)
        {
            printf("\n ��Ӯ�ˣ���Ϸ������\n");
            break;            
        }
    }
    system("PAUSE");	
    return 0;
}
