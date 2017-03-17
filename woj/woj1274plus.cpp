

#include<stdio.h>

#define N 1125

int sushu[N]={2,3,5,7,11};
__int64 dp[N][50];
int num=5;

int panduan(int n){
	int i,j;
	for(i=0;sushu[i]*sushu[i]<=n;i++){
		if(n%sushu[i]==0) return 0;
	}
	return 1;
}

void Init(){
	int gap,i,j;
	for(gap=2,i=13;i<N;i+=gap){
		gap=6-gap;
		if(panduan(i)) {
			//printf("%d==%d\n",num,i);
			sushu[num++]=i;
		}
	}
}

int main(){
	
	int sum=0,n=0;
	int i=0,j=0,k=0;
	Init();
	dp[0][0]=1; 
	for(i=0;i<num;i++){
		for(j=N;j>=sushu[i];j--){
			for(k=15;k>0;k--){
				dp[j][k]+=dp[j-sushu[i]][k-1];
			}
		}
	}
	while(scanf("%d%d",&sum,&n),sum+n){
		printf("%I64d\n",dp[sum][n]);
	}
	return 0;
}
