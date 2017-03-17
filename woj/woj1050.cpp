#include <iostream>
 #include <cstdio>
 #include <cstring>
 #include <algorithm>

#define MAX  100000
//#define VNUM  10+1                                             //����û��IDΪ0�ĵ�,so id�ŷ�Χ1~10
using namespace std;

int main()
{
	int t,n;
	int i,j,k=0;
	int VNUM;
	int start=1;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		VNUM=n+1;
		
        int edge[VNUM][VNUM];
        int lowcost[VNUM];                                         //��¼Vnew��ÿ���㵽V���ڽӵ����̱�
        int addvnew[VNUM];                                             //���ĳ���Ƿ����Vnew
        int adjecent[VNUM];                                        //��¼V����Vnew���ڽ��ĵ�
       int tmp;
		for(i=1;i<VNUM;i++)
		{
			for(j=1;j<VNUM;j++)
		{
			
			scanf("%d",&tmp);
			edge[i][j]=tmp;
			//printf("%d",edge[i][j]);
		}
		 lowcost[i]=0;
		 addvnew[i]=0;
		 adjecent[i]=0;
		}
		
		int sumweight=0;
 

     for(i=1;i<VNUM;i++)                                      //�����Ǵ�1��ʼ
     {
        lowcost[i]=edge[start][i];
        addvnew[i]=-1;                                         //�����е�����Vnew֮��,V֮�ڣ�����ֻҪ��Ӧ��Ϊ-1���ͱ�ʾ��Vnew֮��
     }

     addvnew[start]=0;                                        //����ʼ��start����Vnew
     adjecent[start]=start;
                                                 
     for(i=1;i<VNUM-1;i++)                                        
     {
        int min=MAX;
        int v=-1;
        for(j=1;j<VNUM;j++)                                      
        {
            if(addvnew[j]==-1&&lowcost[j]<min)                 //��Vnew֮��Ѱ�����·��
            {
                min=lowcost[j];
                v=j;
            }
        }
        if(v!=-1)
        {
           // printf("%d %d %d\n",adjecent[v],v,lowcost[v]);
            addvnew[v]=0;                                      //��v��Vnew��

            sumweight+=lowcost[v];                             //����·������֮��
            for(j=1;j<VNUM;j++)
            {
                if(addvnew[j]==-1&&edge[v][j]<lowcost[j])      
                {
                    lowcost[j]=edge[v][j];                     //��ʱv�����Vnew ��Ҫ����lowcost
                    adjecent[j]=v;                             
                }
            }
        }
    }
    printf("%d\n",sumweight);
		
	}
	
	
}
