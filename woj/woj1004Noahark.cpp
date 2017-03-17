#include <stdio.h>  
#include <math.h>  
#include <string.h>  
#define gt 1e-9  
  
double transform(double length,char *c)  
{        
       double ratio=1.0;  
       if(strcmp(c,"meters")==0)
	       ratio=100.0;  
       if(strcmp(c,"cubits")==0)
	        ratio=45.72;  
       if(strcmp(c,"feet")==0)  
	        ratio=30.48;  
       if(strcmp(c,"inches")==0)
	        ratio=2.54;  
       length=length*ratio;  
       
      // printf("length=%lf",length);
       return (length);  
             
}  
  
int main()  
{           
          double l=0.0,w=0.0,h=0.0;  
          double leng=0.0,wid=0.0; 
          char dl[20],dw[20],dh[20];  
    while(scanf("%lf",&l)!=EOF)  
         {  
         scanf("%s",dl);  
         scanf("%lf",&w);  
         scanf("%s",dw);  
         scanf("%lf",&h);  
         scanf("%s",dh); 
		 //printf("l=%lf",l); 
        leng=transform(l,dl); 
	//	printf("%s",dl); 
        wid=transform(w,dw);  
        //leng=3.3;
        //printf("%lf,%lf",leng,wid);
        if(fabs((leng-wid))<gt)
		     printf("Spin");  
        else   
            {  
              if(fabs((leng-6.0*wid))<gt)
			       printf("Excellent");  
              else 
			       printf("Neither");
			  }  
			  
			  //printf("%lf,%lf",leng,wid);
      
               printf("\n\n");  
         }  
  
      return 0;  
}  

