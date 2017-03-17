#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char s[6]={0},e[4]={0},c[200]={0};
	int i,j;
	
	scanf("%c",&s[0]);
	 for(i=0;s[i]!='\n';)
	   {
	       i++;
	       scanf("%c",&s[i]);
	   }
	   s[i]='\0';
	    
	while(strcmp(s,"START")==0&&strcmp(s,"ENDOFINPUT")!=0)
	{
	   
	   scanf("%c",&c[0]);
	   for(i=0;c[i]!='\n';)
	   {
	       i++;
	       scanf("%c",&c[i]);
	   }
	   c[i]='\0';
	 
	    scanf("%c",&e[0]);
	   for(i=0;e[i]!='\n';)
	   {
	        i++;
	       scanf("%c",&e[i]);
	   }
	   e[i]='\0';
	   
	   for(i=0;c[i]!='\0';i++)
	   {
	       if(c[i]>='A'&&c[i]<='Z')
		   {
		         c[i]=(((c[i]-'A')-5)+5*26)%26+'A';
		   }
		   printf("%c",c[i]);
	   }
	  printf("\n"); 
	  
	 scanf("%c",&s[0]);
	 for(i=0;s[i]!='\n';)
	   {
	       i++;
	       scanf("%c",&s[i]);
	   }
	   s[i]='\0';
	   
	}
   // system("PAUSE");
	return 0;
}
