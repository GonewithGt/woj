#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Queue
{
      long v;
      long len;
}que[200001];

struct Vec
{
	long size;
	long data[10000]; 
//	int flag;
} ;


long n,m,k,s,t;
//long map[200001];
int flags[200001];
struct Vec map[200001];


long bfs()
{
     long i;
     if(s==t)
     return 0;
     long qh=0,qe=1;
     que[1].v=s;
     que[1].len=0;
     memset(flags,0,sizeof(flags));
     while(qh<qe)
     {
                 qh++;
                 for(i=0;i<map[que[qh].v].size;i++)
                 {
                          if(flags[map[que[qh].v].data[i]])
                          continue;
                          que[++qe].v=map[que[qh].v].data[i];
                          que[qe].len=que[qh].len+1;
                          flags[map[que[qh].v].data[i]]=1;
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
     //for(i=1;i<=n;i++)
     //map[i].data = (long *)malloc(sizeof(long)*200001);
     for(i=1;i<=m;i++)
     {
                      scanf("%ld%ld",&a,&b);
                      //if(!map[a].flag)
                     // map[a].data = (long *)malloc(sizeof(long)*200001);
                    //  if(!map[b].flag)
                     // map[b].data = (long *)malloc(sizeof(long)*200001);

                      map[a].data[map[a].size]=b;
                      map[a].size+=1;
                      map[b].data[map[b].size]=a;
                      map[b].size+=1;
    
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




