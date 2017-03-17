#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 300000000
//≥¨ø’º‰  Õ∞≈≈–Ú 
int main()
{
	int gt;
	int *array=(int *)malloc(N*sizeof(int));
	memset(array,0,N);
	int i=0,max=0;
	while(scanf("%d",&gt)!=EOF&&gt!=0)
	{
		array[gt]=gt;
		i++;
	}
	for(int j=1;j<N;j++)
	{
		if(array[j]!=0)
		printf("%d ",array[j]);
	}
	return 0;
}

