#include<iostream>
#include<stdio.h>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<string.h>
using namespace std;     
int path[1005],num; 
bool dfs(int x,int step)
{ 
      int i;
      if (num>step) return false;
      if (path[num]==x) return true;
      if (path[num]<<(step-num)  < x) return false;
      for (i=0;i<=num;i++)
      {
             num++;
             path[num]=path[num-1]+path[i];
             if (path[num]<=10000 && dfs(x,step)) return true; 
             path[num]=path[num-1]-path[i];  
             if (path[num]>0 && dfs(x,step)) return true;           
             num--;
      } 
      return false;    
}
int main()
{  
      int i,gt;  
      while (~scanf("%d",&gt) && gt) 
      {
            for (i=0;;i++)
            {
                 path[num=0]=1;
                 if (dfs(gt,i)) break;
            }
            printf("%d\n",i);
      }
      return 0;
}

