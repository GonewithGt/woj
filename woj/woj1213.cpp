#include <iostream>
 #include <cstdio>
 #include <cstring>
 #include <vector>
 #include <algorithm>
 
 using namespace std;
 
 
 struct point
 {
 	int x;
 	int y;
 };
 


int main()
{
	int n=0;
	
	scanf("%d",&n);
	
	struct point points[n+1];
	int a,b;
	
	for(int i=0;i<n;i++)
	{
		cin>>a>>b;
		points[i].x=a;
		points[i].y=b;
		
	} 
	
	
	
	printf("%lld\n",ans);


	
}

