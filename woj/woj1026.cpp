#include <iostream>
 #include <cstdio>
 #include <cstring>
 #include <vector>
 #include <algorithm>
 
 using namespace std;
 

 
 //int a[1001];
 
 int main()
 {
 	int t;
 	int n;
 	scanf("%d",&t);
 	for(int i=0;i<t;i++)
 	{
 		scanf("%d",&n);
 		int a[n][n];
 		int dp[n][n+2];
 	//	rep(rows,n)
 	//	rep(columes,n)
 	int tmp;
 	   for(int rows=0;rows<n;rows++)
 	   for(int columes=0;columes<n;columes++)
 	   {
 	   		scanf("%d",&tmp);
 	   		a[rows][columes]=tmp;
 	   }
 		
 		
 		
 		
 	//	rep(m,n)
 	for(int m=0;m<n;m++)
 		{
 			dp[m][0]=0;
			 dp[m][n]=0; 
			 dp[m][n+1]=0;
			 	dp[n-1][m+1]=a[n-1][m];
 		}
 		
 		
 		
 		
 		
 		
 		for(int ig=n-2;ig>=0;--ig)
 		for(int jt=1;jt<n+1;jt++)
 		{
 			int max=dp[ig+1][jt]>dp[ig+1][jt-1]?dp[ig+1][jt]:dp[ig+1][jt-1];
 			dp[ig][jt]=(max>dp[ig+1][jt+1]?max:dp[ig+1][jt+1])+a[ig][jt-1];
 		}
 	    int ans=0;
 	    for(int g=0;g<n+1;g++)
 	    {
 	    	if(dp[0][g]>ans)
 	    	ans=dp[0][g];
 	    }
 	    
 	    for(int a=0;a<n;a++)
 	    {
 	    	for(int b=0;b<n+2;b++)
 	    printf("%d  ",dp[a][b]);
 	    
 	     printf("\n");
 	    }
 	    
 	   
 	    
 	    printf("Case %d:\n",i+1);
 	    
 	    	printf("%d",ans);
 		if(i!=t-1)
 		printf("\n\n");
 	    
 		
 		
 	}
 	
 
 }
