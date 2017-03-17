# include <stdio.h>
# include 
# include <string.h>
# include <math.h>
# include <iostream>
using namespace std;
int cot;
int used[1500];
int prime[1500];
void sushu()///素数打表
{
    memset(used,0,sizeof(used));
    cot=0;
    for(int i=2; i<=1120; i++)
    {
        if(!used[i])
        {
            prime[cot++]=i;
            for(int j=2*i; j<=1120; j+=i)
                used[j]=1;
        }
    }
}
int main()
{
    int n,k,i,j,p;
    int dp[1500][20];
    while(~scanf("%d %d",&n,&k),n+k)
    {
        sushu();
        memset(dp,0,sizeof(dp));
        ///01背包
        dp[0][0]=1;
        for(i=0;i<cot;i++) for(j="k;j" {="">=1;j--)
            {
                for(p=n;p>=prime[i];p--)
                    dp[p][j]+=dp[p-prime[i]][j-1];
            }
        }
        printf("%d\n",dp[n][k]);
    }
    return 0;
}

