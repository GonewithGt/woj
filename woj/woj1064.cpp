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
			return 1;
		}
		
	}
	
	return 0;
}

int main()
{
	int t,n;
	int a;
	int ans=0;
	int data[10001];
   // int count[10001];
	
	
		
	
		while(scanf("%d",&n)!=EOF)
		{
			
				for(int gt=0;gt<10001;gt++)
	{
		data[gt]=0;
	}
		int count=0;

	
		for(int j=0;j<n;j++)
		{
			scanf("%d",&a);
			if(!ifcontain(a,count,data))
			{
				data[count]=a;
					count++;
			}
		
		}
		
		sort(data,data+count);
		
		for(int m=0;m<count-1;m++)
		{
			printf("%d ",data[m]);
		}
		
		
		printf("%d",data[count-1]);
		printf("\n");
		
	}
}
