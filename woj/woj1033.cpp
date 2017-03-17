 #include <iostream>
 #include <cstdio>
 #include <cstring>
 #include <vector>
 #include <algorithm>
 
 using namespace std;
 
 //int a[1001];
 int canexpress(int m,int a,int b)
 {
 	int flag=0;
 	
 	for(int i=0;i<a&&i*b<=m;i++)
 	{
 		if((m-i*b)%a==0)
 		{
 			//	printf("canbe=%d",m);
 			 flag=1;
 		}
 	       
 	}
 	
 	
 	return flag;
 	
 }
 
 int main()
 {
 	int a,b,m,n;
    while(scanf("%d%d%d%d",&a,&b,&m,&n)!=EOF)
    {
    	if(m>n)
    	{
    		int gt=m;
    	     n=m;
    	     m=gt;
    	}
    	
    	int ans=n-m+1;
    //	printf("ans=%d",ans);
        int tmp=n;
    	int tmp2=(a-1)*(b-1);
    	if(tmp2<=n&&tmp2>=m)
    	{
    		tmp=tmp2;
    		ans=ans-(n-tmp2);
    	}
    	
    //	printf("tmp=%d",tmp);
    	for(int j=m;j<=tmp;j++)
    	{
    		if(canexpress(j,a,b))
    		{
    				ans--;
    		}
    	
    	}
    	
    	printf("%d\n",ans);
    }
    
 	
 	return 0;
 }
