#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int rank[13]={1,2,3,4,5,6,7,8,9,10,11,11,11}; 
	char *names[13]={"Adam","Seth","Enosh","Kenan","Mahalalel",  "Jared","Enoch","Methuselah","Lamech","Noah",  "Shem","Ham","Japheth"};
	int age[9]={930,912,905,910,895,962,365,969,777};
	char name1[20];
	char name2[20];
	while(scanf("%s %s",name1,name2)!=EOF)
	{
		int i=0,j=0,k=0;
		for(i=0;i<13;i++){
			if(!strcmp(names[i],name1))
			break;
		}
		for(j=0;j<13;j++){
		   if(!strcmp(names[j],name2))
			break;
		}
		
		printf("i=%d j=%d",i,j);
		
		if(rank[i]<rank[j])  printf("Yes\n");    
        else printf("No\n");  
          
    if(i>8||j>8) printf("No enough information\n");   
    else   
    {  
        if(age[i]>age[j]) printf("Yes\n");   
        else printf("No\n");   
    }  
		
	}
    
	 
}
