#include <stdio.h>
#include <cstdlib>

#define N 500010
using namespace std;



int main()
{
	int k=0;
	
	int *a;
    int *flag;
	a=(int *)malloc(N*sizeof(int));
	flag=(int *)malloc(100000000*sizeof(int));
	//memset(flag,0,sizeof(flag));
	/*
	
		for(int i=0;i<10000000;i++)
	{
		flag[i]=0;
	}
	
	for(int j=0;j<N;j++)
	{
		a[j]=0;
	}
	*/



	for(int m=1;m<=500000;m++)
	{
		int tmp1=a[m-1]-m;
		int tmp2=a[m-1]+m;
		
		if(tmp1>0&&!flag[tmp1])
		{
			a[m]=tmp1;
		
		
		}else
		{
			a[m]=tmp2;
		
		}
		
		flag[a[m]]=1;
		
		//printf("%d",a[m]);
		
	}
	
	while(1)
	{
		scanf("%d",&k);
	
	if(k==-1)
	break;
	
	printf("%d\n",a[k]);
	}
	
	return 1;
}
