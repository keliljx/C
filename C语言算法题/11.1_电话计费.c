#include <stdio.h>
#include <stdlib.h>
FILE *fin;
int main()
{
   char str[80];
   int h1,h2,m1,m2,s1,s2;
   long t_start,t_end, interval;
   int c;
   double fee = 0;  
   fin = fopen("dial.txt","r");
   if (!fin)
	   return -1;
   while (!feof(fin)) {  
	   if (!fgets(str,80,fin))  break;     
	   if (str[0]=='i')   continue;
	   h1 = (str[2] - 48) * 10 + str[3] - 48;
	   m1 = (str[5] - 48) * 10 + str[6] - 48;
       s1 = (str[8] - 48) * 10 + str[9] - 48;
       h2 = (str[11] - 48) * 10 + str[12] - 48;
	   m2 = (str[14] - 48) * 10 + str[15] - 48;
       s2 = (str[17] - 48) * 10 + str[18] - 48;  
   	   t_start = h1*60*60 + m1*60 + s1;    /* ͨ����ʼʱ�� */
	   t_end = h2*60*60 + m2*60 + s2;      /* ͨ������ʱ�� */  
       if (t_end<t_start)                  /* ��ͨ����ʼ�ͽ���ʱ����� */
		   interval = 24*60*60-t_start + t_end;
	   else
		   interval = t_end - t_start; 
       c = interval/60;                    /* ����������������ʾ��ͨ��ʱ�� */
	   if (interval % 60)
		  c++,c+=1,c=c+1;
	   fee += c * 0.08;
   }
   fclose(fin);
   printf("�����㱾�µĵ绰�����ǣ�\n");
   printf("fee = %.2lf\n",fee);
  system("PAUSE");	
  return 0;
}
