 #include <iostream>
 #include <cstdio>
 #include <cstring>
 #include <vector>
 #include <algorithm>
using namespace std;


struct Node
{
	int x;
	vector<int> y;
};

struct Node nodes[1001];

int main()
{
	int n=0;
	
	while(scanf("%d",&n)!=EOF)
	{
		
	//	struct Node nodes[1001];
		int a=0,b=0;
	    int tmp=0;
      	int len=0;
		for(int i=0;i<n;i++)
	{
		scanf("%d %d",&a,&b);
		tmp=len;
		for(int j=0;j<len;j++)
		{
			if(nodes[j].x==a)
		    tmp=j;
		   // printf("tmpt=%d",nodes[j].x);
		    
		}
		
		nodes[tmp].x=a;
		nodes[tmp].y.push_back(b); 
		
		//printf("b=%d",b);
		if(tmp==len)
		{
			len=len+1; 
		}
		
		//printf("tmp=%d len=%d\n",tmp,len);
		
	}
	
	for(int k=0;k<len;k++)
	{
		sort(nodes[k].y.begin(),nodes[k].y.end());
	}
	
	//printf("len=%d\n",len);
	
	int sum=0;
	if(len>=1)
	   sum=nodes[0].y[0]+nodes[0].y[nodes[0].y.size()-1];
	   
	  //printf("sum=%d\n",sum);
	int flag=1;
	for(int m=0;m<len;m++)
	{
		nodes[m].x=0;
		int siz=nodes[m].y.size();
		
		for(int l=0;l<siz;l++)
		{
				if(nodes[m].y[l]+nodes[m].y[siz-1-l]!=sum)
		{
			flag=0;
		}
		
	//	nodes[m].y[l]=0;
		}
		nodes[m].y.clear();
		
	
		
	}
	
	if(flag)
	{
		printf("YES\n");
	}	
	else
	printf("NO\n");
	}
	
}
