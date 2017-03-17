 #include <iostream>
 #include <cstdio>
 #include <cstring>
 #include <vector>
 #include <algorithm>
using namespace std;


int main()
{
	int n;
	int m;
	int tmp;
	int min;
	while(scanf("%d",&n)!=EOF)
	{
		scanf("%d",&m);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&tmp);
			if(i==0)
			{
				min=tmp;
			}else
			{
				if(tmp<min)
				{
					min=tmp;
				}
			}
		}
		
		printf("%d",m/min);
	}
}
