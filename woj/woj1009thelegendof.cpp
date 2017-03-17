#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std; 
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repf(i, a, b) for (int i = (a); i <= (b); ++i)
#define repd(i, a, b) for (int i = (a); i >= (b); --i)
#define swap(a, b) {int t = a; a = b; b = t;}
#define mc(a) memset(a, 0, sizeof(a))
#define mcv(a, v) memset(a, v, sizeof(a))
#define N 105
// #define test
typedef struct Node{
    int p, s; 
    char l[3];
}node;
node e[N][N];
int n, m, dist[N], g[N][N], fa[N], plove, slove;
 
inline bool relax(int u, int v)
{
    if(dist[u] + g[u][v] < dist[v]) 
    {
        dist[v] = dist[u] + g[u][v];
        return true;
    }
    return false;
}
 
inline bool judge(node e)
{
    return ((plove > e.p) && (slove > e.s));
}
 
void spfa(int s)
{
    int vis[n + 5];
    mc(vis);
    queue<int> q;
    q.push(0);
    vis[0] = true;
    dist[0] = 0;
     
    while(!q.empty())
    {
        int temp = q.front();
        q.pop();
        rep(i, n) 
            if(g[temp][i] && judge(e[temp][i]) && relax(temp, i) && !vis[i] )
            {
                q.push(i);
                fa[i] = temp; // save path
                vis[i] = true;
            }
        vis[temp] = false;
    }
}
 
void sprint()
{
    int k = n - 1, top = 0;
    node st[N];
    while(k)
    {
        st[top++] = e[fa[k]][k];
        k = fa[k];
    }
    repd(i, top - 1, 0) printf("%s", st[i].l);
}
 
int main()
{
    #ifdef test
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
     
    while(scanf("%d%d", &n, &m) == 2)
    {
        mc(g); mc(e); mcv(fa, -1);
        rep(i, n) dist[i] = 0x7fffffff;
        int a , b, p, s, c;
        char l[3];
        rep(i, m) {
            scanf("%d%d%d%d%d %s", &a, &b, &p, &s, &c, l);
            g[a][b] = g[b][a] = c;
            e[a][b].p = e[b][a].p = p;
            e[a][b].s = e[b][a].s = s;
            strcpy(e[a][b].l, l);
            strcpy(e[b][a].l, l);
        }
        scanf("%d%d", &plove, &slove);
 
        spfa(0);
        sprint();
        puts("");
        // printf("%d\n", dist[n - 1]);
    }
    return 0;
}
 

