#include <iostream> 
#include <cstdlib>
#include <cstdio>

using namespace std; 

int main()
{
	int t=0;
	int a,b,h;
	double ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&a,&b,&h);
		ans=(double)h*(double)b/(double)a;
		printf("%.2f",ans);
	} 
}
