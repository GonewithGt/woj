#include <iostream>
 #include <cstdio>
 #include <cstring>
 #include <vector>
 #include <algorithm>
 
 using namespace std;
 
 
 
 


int main()
{
	int n;
	int direction;
	int count;
	int ans;
    int gt=0;
	while (1)

{

    scanf("%d", &n);
    
    count=0;
    ans=0;

    if (n == -1) //输入结束标志，n=0时不需要被处理

        break;
        
    else
    {
    	for(int i=0;i<n;i++)
    	{
    		scanf("%d",&direction);
    		if(direction==1)
    		{
    			count++;
    		}else if(direction==-1)
    		{
    			ans=ans+count;
    			//count=0;
    		}
    	}
    }
   
    gt++;
    printf("Case %d: ",gt);
    printf("%d\n", ans); //需要加上 \n ，每组处理完直接输出即可。

}

	
}

