
#include<iostream>
#include<queue>
#include<cstring>
#include<cstdlib> 
#define MAX 100001
using namespace std;


int *path;   
int *visit;
//queue<int> que;

int bound(int num)
{
    if(num<0||num>100000)
        return 1;
    return 0;
}

int BFS(int st,int end)
{
    queue<int> que;
    int t,tmp;
    que.push(st);
    visit[st]=1;
    while(!que.empty())
    {
        t=que.front();
        que.pop();
        for(int i=0;i<3;++i) 
        {
            if(i==0)
                tmp=t+1;
            else if(i==1)
                tmp=t-1;
            else
                tmp=t*2;
            if(bound(tmp))         
                continue;
            if(!visit[tmp])
            {
                path[tmp]=path[t]+1;
                if(tmp==end)
                    return path[tmp];
                visit[tmp]=1;
                que.push(tmp);
            }
        }
    }
}

int main()
{
	path=(int *)malloc(MAX*sizeof(int));
	visit=(int *)malloc(MAX*sizeof(int));
    int st,end;
    int ans;
    while(scanf("%d%d",&st,&end)!=EOF)
    {
        memset(visit,0,sizeof(visit));
        if(st>=end)
        {
        	ans=st-end;
        }
           // cout<<st-end<<endl;
        else
        {
        		ans = BFS(st,end);
        }
        
        
           printf("%d\n",ans);
            //cout<<BFS(st,end)<<endl;
    }
    return 0;
}
