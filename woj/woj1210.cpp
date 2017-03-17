//#include<iostream>
//#include<cstdio> 
#include<stdio.h> 
#include<string.h>
#include<stdlib.h>
//using namespace std; 
//int f[1001][1001];//**1001*1001太大不能定义在主函数，否则直接停止编译**//  
//int **f;
int *p;
int main()  
{  
	int i,j,len1,len2;
	//string a,b;  
	/*
	f=(int **)malloc(10001*sizeof(int *));
    if (NULL==f) return 0;
    for (i=0;i<10001;i++) {
        f[i]=(int *)malloc(10001*sizeof(int));
        if (NULL==f[i]) return 0;
    }
    */

    //char a[10001],b[10001];
	char *a=(char *)malloc(10001*sizeof(char *));
	char *b=(char *)malloc(10001*sizeof(char *)); 
   
    
  while(~scanf("%s %s",a,b))  
   // while(cin>>a>>b)
    {  
        len1=strlen(a);  
        len2=strlen(b);
        /*
	f=(int **)malloc((len1+1)*sizeof(int *));
    if (NULL==f) return 0;
    for (i=0;i<len1+1;i++) {
        f[i]=(int *)malloc((len2+1)*sizeof(int));
        if (NULL==f[i]) return 0;
    }
    
    
       for(i=0;i<=len1;i++)  
       {  
            f[i][0]=0;  
       }  
       for(i=0;i<=len2;i++)  
       {  
            f[0][i]=0;  
        }  
        
    */
    
    p=(int *)malloc((len2+1)*sizeof(int));
    int tmp1=0,tmp2=0,tmp3=0;

   // char a[10001],b[10001]; 
	  
        for(i=0;i<=len2;i++)  
       {  
            p[i]=0;  
        } 
        
        for(i=1;i<=len1;i++)  
        {  
           tmp1=0;
           tmp2=0;
           tmp3=0;
          for(j=1;j<=len2;j++)  
            {  
            	
            	tmp3=p[j];
            	
                if(a[i-1]==b[j-1])  
                {  
                   //f[i][j]=f[i-1][j-1]+1;  
                   p[j]=tmp1+1;
                }  
               else  
               {  
                  // f[i][j]=f[i-1][j]>f[i][j-1]?f[i-1][j]:f[i][j-1]; 
				   p[j]=tmp2>tmp3?tmp2:tmp3; 
               } 
               
			   tmp1=tmp3; 
			   tmp2=p[j];
			   
               
               
           }  
           
       }  
       printf("%d\n",p[len2]);  
    }  
    return 0;  
}  


