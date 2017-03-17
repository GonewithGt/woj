#include<stdio.h>  
#include<stdlib.h>  
#include<string.h>   
int main()   
{    
    char *a[13]={"Adam","Seth","Enosh","Kenan","Mahalalel",  
                    "Jared","Enoch","Methuselah","Lamech","Noah",  
                    "Shem","Ham","Japheth"};   
    int b[13]={1,2,3,4,5,  
              6,7,8,9,10,  
              11,11,11};   
    int c[9]={930,912,905,910,895,  
             962,365,969,777};  
    char str1[100],str2[100];  
    while(scanf("%s%s",str1,str2)!=EOF)  
    {   
    int i=0,j=0;  
    int x,y;   
    x = 0;y = 0;   
    for(i=0;i<13;i++)  
        {   
             if(!strcmp(a[i],str1))  
             x=i;  
        }   
    for(j=0;j<13;j++)  
       {  
            if(!strcmp(a[j],str2))  
            y=j;  
        }  
   
       if(b[x]<b[y])  printf("Yes\n");    
        else printf("No\n");  
          
    if(x>8||y>8) printf("No enough information\n");   
    else   
    {  
        if(c[x]>c[y]) printf("Yes\n");   
        else printf("No\n");   
    }  
      
        }   
    //system("pause");  
    return 0;  
}   

