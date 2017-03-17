#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#define N  200010
using namespace std;

int Father[N];
int keys[N];
int len;
int Find_Set(int x)
{
    while (x != Father[x]) x = Father[x];
    return x;
}

void Union(int x, int y)
{
    x = Find_Set( x );
    y = Find_Set( y );
    if(x == y) return ;
    Father[x] = y; 
    if(y>len) len=y;
}


int main()
 {
 
 	int n,i;
 	while(1)
 	{
 		scanf("%d",&n);
 		if(n==0)
 		break;
 		
 		
 		len=1;
        for(i=0;i<N;i++)
        {
            Father[i]=i; keys[i]=0;
        }
        for(i=1;i<=n;i++)
        {
            int tmp,f;
            //cin>>tmp;
            scanf("%d",&tmp);
            Father[tmp]=Find_Set(tmp);
            if(tmp== Father[tmp])
            {
                keys[tmp]=i;
                Union(tmp,tmp+1);
            }
            else
            {
                keys[Father[tmp]]=i;
                Union(Father[tmp],Father[tmp]+1);
            }
        }
        if(keys[len]==0) len--;
           // cout<<len<<endl;
            
            printf("%d\n",len);
 	for(int gt=1;gt<len;gt++)
 	{
 		printf("%d ",keys[gt]);
 	}
 	
 	
 	printf("%d\n",keys[len]);
 	}

 	
 	
 }

