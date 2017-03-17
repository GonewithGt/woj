#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

long n,m,k,s,t;
vector<long> map[200001];
bool hash[200001];

struct
{
      long v;
      long len;
}que[200001];

long bfs()
{
     long i;
     if(s==t)
     return 0;
     long qh=0,qe=1;
     que[1].v=s;
     que[1].len=0;
     memset(hash,false,sizeof(hash));
     while(qh<qe)
     {
                 qh++;
                 for(i=0;i<map[que[qh].v].size();i++)
                 {
                          if(hash[map[que[qh].v][i]])
                          continue;
                          que[++qe].v=map[que[qh].v][i];
                          que[qe].len=que[qh].len+1;
                          hash[map[que[qh].v][i]]=true;
                          if(que[qe].v==t)
                          return que[qe].len-1;
                 }
     }
     return -1;
}
    

int main()
{
     scanf("%ld%ld",&n,&m);
     long a,b,i,j;
     for(i=1;i<=m;i++)
     {
                      scanf("%ld%ld",&a,&b);
                      map[a].push_back(b);
                      map[b].push_back(a);
     }
     scanf("%ld",&k);
     for(i=1;i<=k;i++)
     {
                      scanf("%ld%ld",&a,&b);
                      s=a;t=b;
                      printf("%ld\n",bfs());
     }
     return 0;
}

