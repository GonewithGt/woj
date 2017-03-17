#include <stdio.h>
#include <stdlib.h>

int main()
{
	
	long long int ans;

	long long int a,b,c;

	while(scanf("%lld%lld%lld",&a,&b,&c)==3)
	{
		
		if(a==0&&b==0&&c==0)
		break;
		
		ans = 1;
	
		while(b>=1)
		{ 
	
			if(b%2==1) 
				ans = a*ans%c; 
			
			a=a*a%c;
			b=b/2;
		}
		
		printf("%lld\n", ans);
	}
	
//	system("pause");
	return 0;

}
