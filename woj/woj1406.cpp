#include <iostream> 
#include <cstdlib>
#include <cstdio>

using namespace std; 
int main() 
{ 
    long long n=0,c=0; 
	long long ans=0;
	while(scanf("%lld%lld",&n,&c)!=EOF)
	{ 
	   // ans=0;
		if(n==0)
		{ 
		printf("0\n"); 
		continue; 
		} 
		long long  x=c/(2*n); 
		long long  y=x+1; 
		ans=x*(c-n*x)>=y*(c-n*y)?x:y;
		printf("%lld\n",ans); 
         } 
		return 0; 
} 

