#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 200;
const int M = 2500;
int add[N];
int dp[M][M];

int main()
{
    int n,m;
    string s;
    while(~scanf("%d%d",&n,&m))
    {
        cin>>s;
        char c;int x,y;
        for(int i=0;i<n;i++)
        {
            cin>>c>>x>>y;
            add[c]=min(x,y);
        }
        memset(dp,0,sizeof(dp));
        for(int k=1;k<s.size();k++)
        {
            for(int i=0,j=k;j<s.size();i++,j++)
            {
                dp[i][j]=0x3f3f3f3f;
                if(s[i]==s[j])
                    dp[i][j]=dp[i+1][j-1];
                else
                {
                    dp[i][j]=min(dp[i+1][j] + add[s[i]],dp[i][j]);
                    dp[i][j]=min(dp[i][j-1] + add[s[j]],dp[i][j]);
                }
            }
        }
        printf("%d\n",dp[0][s.size()-1]);
    }
    return 0;
}

