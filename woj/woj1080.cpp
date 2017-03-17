
#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;
 

int main()
{
	int t=0;
	long long n=0;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%lld",&n);
		//n=0;
	
		if(n%14==0)
		{
			printf("snoopy wins the game!\n");
		}else
		{
			printf("flymouse wins the game!\n");
		}
	}
} 
