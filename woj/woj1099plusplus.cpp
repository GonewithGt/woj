 #include <stdio.h>
 
int main()
 {
     
     int gt=1,N=2<<30;

       int a=0,b=0,i=0;

     while(scanf("%d %d",&a,&b)==2)
     {
         
        if(a<0&&b<0)
         break;
         
        int st[20];
        for(int k=0;k<20;k++)
        {
        	st[k]=0;
        }
         i=0;
       
    	while(a!=0)
    	{
    
    		st[i]=a%2;
    		a=a/2;
    		i++;
    	} 
    	
    
         
         gt = 1;
         
         for(int j=i;j>=0;--j)
    	{
    		
    		int tmp=st[j];
    		switch(tmp)
    			{
    		case 0:
    			gt=gt*gt;
    			break;
    		case 1:
    			gt=gt*gt*2;
    			break;
    			}
    			
    	  if(gt>N)
    		gt=gt%b;
    	
    	}

        
         
         gt=gt%b;
         
         if(gt==0)
         {
         	gt=b-1;
         }else
         {
         	gt=gt-1;
         }
         
        printf("%d\n",gt);
     }
     
     return 0;

 }
