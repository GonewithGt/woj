
#include <stdio.h> 
 
int node,edge,src,dst;  
int ver[6000],flow[6000],next[6000];  
int head[1000],work[1000],dis[1000],q[1000],score[1000];

int min(int a,int b){
     if(a<b) return a;
     else return b;
     }  

void init(int _node,int _src,int _dst)  

 {  
     int i;
     node=_node,src=_src,dst=_dst;  
     for(i=0;i<node;++i)head[i]=-1;  
     edge=0;  
 }  
   
void add(int u,int v,int c)  
 {  
     ver[edge]=v,flow[edge]=c,next[edge]=head[u],head[u]=edge++;  
     ver[edge]=u,flow[edge]=0,next[edge]=head[v],head[v]=edge++;  
 }

int bfs()  
 {  
     int i,u,v,l,r=0;  
     for(i=0;i<node;++i)dis[i]=-1;  
     dis[q[r++]=src]=0;  
     for(l=0;l<r;++l)  
         for(i=head[u=q[l]];i>=0;i=next[i])  
             if(flow[i]&&dis[v=ver[i]]<0)  
             {  
                 dis[q[r++]=v]=dis[u]+1;  
                 if(v==dst)return 1;  
             }  
     return 0;  
 }
   
int dfs(int u,int exp)  
 {  
     int i,v,tmp;
     if(u==dst)return exp;  
     for(i=work[u];i>=0;i=next[i])  
         if(flow[i]&&dis[v=ver[i]]==dis[u]+1&&(tmp=dfs(v,min(exp,flow[i])))>0)  
         {  
             flow[i]-=tmp;  
             flow[i^1]+=tmp;  
             return tmp;  
         }  
     return 0;  
 }
   
int flo()  
 {  
     int i,ret=0,del;  
     while(bfs())  
     {  
         for(i=0;i<node;++i) work[i]=head[i];  
         if(del=dfs(src,1000000000)) ret+=del;  
     }  
     return ret;  
 }

void p1124(){
     int i,u,v,m,n,sum;  
     while(scanf("%d%d",&n,&m)== 2)  
     {  
         for(i=1;i<=n;++i)scanf("%d",&score[i]);  
         init(n+m+2,0,n+m+1);  
         sum=0;  
         for(i=1;i<=m;++i)  
         {  
             scanf("%d%d",&u,&v);  
             if(u!=n&&v!=n)
             {  
                 sum+=2;  
                 add(src,i,2);  
                 add(i,m+u,2);  
                 add(i,m+v,2);  
             }
             else score[n]+=2;
         }  
         for(i=1;i<n;++i)  
         {  
             if(score[i]>=score[n]-1)break;  
             add(m+i,dst,score[n]-1-score[i]);  
         }  
         if(i!=n||flo()!=sum) printf("NO\n");
         else printf("YES\n");
     }  
 }
   
int main()  
 {  
     p1124();
     return 0;  
 }



