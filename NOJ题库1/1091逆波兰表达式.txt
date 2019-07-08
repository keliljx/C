# include <stdio.h>
char cal(char a,char b,char c);
int main(){
    char s[20];
     int i,j;
	 scanf("%s",s);
	 i=0;
	 while(1){
		 while(s[i] != '\0' && s[i] >='0' && s[i] <='9'){
	    i++;
		 }
		 if(s[i] == '\0'){break;}
     s[i-2] = cal(s[i-2],s[i-1],s[i]);
      j=i+1;
	  while(s[j] != '\0'){
	     s[j-2] = s[j];
		 j++;
	  }
	  s[j-2]=s[j];
	  i=i-2;
	 }
      printf("%c\n",s[0]);

 return 0;
}

char cal(char a,char b,char c){
    int val,m,n;
	m=a-'0';
	n=b-'0';
	switch(c){
	case '+':val=m+n;break;
		case '-':val=m-n;break;
			case '*':val=m*n;break;
				case '/':val=m/n;break;
	}
   return (val+'0');
}
