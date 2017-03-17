#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std; 
//#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define repf(i, a, b) for (int i = (a); i <= (b); ++i)
//#define repd(i, a, b) for (int i = (a); i >= (b); --i)
//#define swap(a, b) {int t = a; a = b; b = t;}
//#define mc(a) memset(a, 0, sizeof(a))
//#define mcv(a, v) memset(a, v, sizeof(a))
#define N 210
// #define test
int n, m, k, a[N], cap[N][N],flow[N][N], s, t, f, p[N]; // a[i]： s到i上的最小残量
 
void init()
{
    int ani = m + 1, temp;
    //repf(i, 1, m)
    for(int i=1;i<=m;i++)
    for(int j=0;j<n;j++)
        //rep(j, n)
        {
            //scanf("%d", &temp);
            cin>>temp;
            if(temp) cap[i][ani + j] = 1;
            cap[ani + j][t] = 1;
        }
     
    //scanf("%d", &k);
    cin>>k;
    for(int i=1;i<=m;i++) cap[0][i] = k;
}
 

                 
int main()
{
    #ifdef test
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif 
     
    while(cin>>m>>n)
    {
        memset(cap, 0, sizeof(cap)) ;
        s = 0; t = m + n + 1; f = 0;
        init();
        
        
    queue<int> q;
   // mc(flow);
   memset(flow, 0, sizeof(flow));
    f = 0;
    while(1)
    {
       // mc(a);
       memset(a, 0, sizeof(a));
        a[s] = 0x7fffffff;
        q.push(s);
        while(!q.empty())
        {
            int u = q.front(); q.pop();
            //repf(v, 1, t)
			 for(int v=1;v<=t;v++)
			if(!a[v] && cap[u][v] > flow[u][v])
            {
                p[v] = u; q.push(v);
                a[v] = min(a[u] , cap[u][v] - flow[u][v]);
            }
        }
         
        if(a[t] == 0) break;
        for(int u = t; u != s; u = p[u])
        {
            flow[p[u]][u] += a[t];
            flow[u][p[u]] -= a[t];
        }
        f += a[t];
    }
        // printf("%d\n", f);
        //f == n ? puts("Yes") : puts("No");
        f == n ? cout<<"Yes"<<endl : cout<<"No"<<endl;
    }
    return 0;
}

