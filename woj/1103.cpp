 #include <iostream>
 #include <cstdio>
 #include <cstring>
 #include <vector>
 #include <algorithm>
using namespace std;


int main()
{
	int t;
    float ans,tmp;
	
	scanf("%d",&t);
	int n=0;
	char c;
	
	for(int i=0;i<t;i++)
	{
		cin>>n>>c;
		tmp=(float)n/100.0;
		ans=tmp*tmp*100.0/(1-2*tmp*(1-tmp));
		
		printf("%.2f%%\n",ans);
	}
}
