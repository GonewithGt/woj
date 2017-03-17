 #include <iostream>
 #include <cstdio>
 #include <cstring>
 #include <algorithm>
using namespace std;

void swap(int *a, int *b)  
{  
    int    temp;  
    temp = *a;  
      *a = *b;  
      *b = temp;  
}  


int main()
{
	int t=0;
	int n=0;
	int ans=0;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		ans=0;
		
		scanf("%d",&n);
		if(n<=1)
		{
			printf("%d",ans);
			continue;
		}
		
		int array[n+1];
     	int tmp=0;
		for(int j=0;j<n;j++)
		{
			scanf("%d",&tmp);
			array[j]=0;
			
		}
	//	for(int m=0;m<n-1;m++)
	//	for(int k=m+1;k<n;k++)
	//	{
	//		if(array)
	//	}
	     int flag;
		
		
		for (int k = 0; k < n && flag; k++)  
    {  
        flag = 0;      
       for (int gt = n-1; gt > k; gt--)  
        {  
            if (array[gt] < array[gt-1])  
            {  
                swap(&array[gt], &array[gt-1]);
				ans++;  
                flag = 1;   
            }  
        }  
    }    
    
    printf("%d\n",ans);

	}
}
