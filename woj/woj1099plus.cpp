 #include <stdio.h>
 //#include <iostream>
 //#include <cstring>
// #define N 2<<31
 using namespace std;
 
int main()
 {
     
     int gt=1,N=2<<30;

       int a=0,b=0,i=0;

     while(scanf("%d %d",&a,&b)==2)
     {
         
        if(a<0&&b<0)
         break;
         
        int st[20];
        // memset(st,0,20*sizeof(int));
        for(int k=0;k<20;k++)
        {
        	st[k]=0;
        }
         i=0;
        //stack<int> s;
    	while(a!=0)
    	{
    	//	s.push(a%2);
    		st[i]=a%2;
    		a=a/2;
    		i++;
    	} 
    	
    	//cout<<"a="<<i<<endl;
         
         gt = 1;
         
         for(int j=i;j>=0;--j)
    	{
    		//int i=s.top();
    		//s.pop();
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

         //ans=(power(2,a)-1)%b;
         
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
