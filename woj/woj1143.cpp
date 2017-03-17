#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
	int p,m,n;
	int ans;
	while(1)
	{
		scanf("%d%d%d",&p,&m,&n);
		if(p==0&&m==0&&n==0)
		{
		 break;
		}
		ans=p>m*n?p:m*n;
		printf("%d\n",ans);
		
	}
}
