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

    if (n == -1) //���������־��n=0ʱ����Ҫ������

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
    printf("%d\n", ans); //��Ҫ���� \n ��ÿ�鴦����ֱ��������ɡ�

}

	
}

