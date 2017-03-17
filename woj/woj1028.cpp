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
 	int x1=0,y1=0,x2=0,y2=0; 
 	int ans;
 	scanf("%d",&t);
 	for(int i=0;i<t;i++)
 	{
 		scanf("%d %d %d %d %d",&n,&x1,&y1,&x2,&y2);
 		int xgap=abs(x1-x2);
 		int ygap=abs(y1-y2);
 		if(x1<=n&&y1<=n&&x2<=n&&y2<=n&&x1>=1&&y1>=1&&x2>=1&&y2>=1)
 		{
 			if(xgap==ygap)
 		ans=xgap;
 		else
 		if(abs(xgap-ygap)%2==0)
 		{
 			ans=xgap>ygap?xgap:ygap;
 		}
 		
 		else

 		ans=-1;
 		
 		}
 		printf("Case %d:\n",i+1);
 	    printf("%d",ans);
 		if(i!=t-1)
 		printf("\n\n");
 	}
 	
 	return 0;
 }
