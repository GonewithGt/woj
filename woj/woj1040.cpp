#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#define N  200010
using namespace std;




int ifcontain(int num,int cou,int *data)
{

	for(int m=0;m<cou;m++)
	{
		if(data[m]==num)
		{
			return m;
		}
		
	}
	
	return cou;
}

int main()
{
	int t,n;
	int a;
	int ans=0;
	int data[10001];
    int count[10001];
	
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		ans=0;
		
		for(int gt=0;gt<10001;gt++)
	{
		data[gt]=0;
		count[gt]=0;
	}
		scanf("%d",&n);
	
		for(int j=0;j<n;j++)
		{
			scanf("%d",&a);
			int location=ifcontain(a,j,data);
			data[location]=a;
			count[location]=count[location]+1;	
		}
		
		for(int k=0;k<10001;k++)
		{
			if(count[k]>ans)
		    ans=count[k];
		
		}
		
		printf("%d\n",ans);
	}
}
