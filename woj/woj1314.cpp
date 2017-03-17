#include <iostream>
 #include <cstdio>
 #include <cstring>
 #include <algorithm>
using namespace std;



int dfs(int n,int count)
{
	printf("  %d \n",n);
	count++;
	if(n==1)
	{
		return count;
	}
	
	if(n%2==0)
	{
		n=n/2;
		dfs(n,count);
	}else
	{
		n=3*n+1;
		dfs(n,count);
	}
}

int main()
 {
 	int i,j,ans,tmp;
     while(cin>>i>>j)
     {
     	ans=0;
     	if(i==0&&j==0)
     	break;
     	
     	for(int k=i;k<=j;k++)
     	{
     		tmp=dfs(k,0);
     		printf("k=%d\n\n",k);
     		if(tmp>ans)
     		ans=tmp;
     	}
     	
     	printf("ans=%d\n",ans);
     }
     
     
 }
