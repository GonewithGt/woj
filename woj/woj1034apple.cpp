#include <iostream>
 #include <cstdio>
 #include <cstring>
 #include <vector>
 #include <algorithm>
 
 using namespace std;
 
 int main()
 {
 	long long n;
 	long long  ans=0;
 	while(scanf("%lld",&n)!=EOF)
 	{
 		ans=(n*n*n+5*n+6)/6;
 		printf("%lld\n",ans);
 	}
 }
