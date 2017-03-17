#include <iostream>
 #include <cstdio>
 #include <cstring>
 #include <vector>
 #include <algorithm>
 
 using namespace std;
 
 
 
 


int main()
{
	long long int n;
	
	scanf("%d",&n);
	
	long long  ans=0;
	long long  tmp=0;
	
	for(int i=0;i<2*n+1;i++)
	{
		scanf("%d",&tmp);
	//	printf("\n");
		if(i==0)
		ans=tmp;
		else
		ans=ans^tmp;
		
	//	printf("%lld\n",ans);
	} 
	
	printf("%lld\n",ans);


	
}

