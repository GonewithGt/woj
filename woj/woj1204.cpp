#include<stdio.h>
int t[500000];
int main()  
{  

	int n;
	while(scanf("%d",&n) != EOF){
		
		
	int gt=0,tmp=0,count=0,count1=0,tmp1=0,x=0,y=0,ans=0;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&t[i]);
		
		if(i==n-1)
		{
			tmp1=gt;
			count1=count;
		}
		
		//scanf("%d",&tmp);
		if(count==0)
		{
			gt=t[i];
			count++;
		}else if(gt==t[i])
		{
			count++;
		} else
		{
			count--;
		}	
	}
	
	//printf("gt=%d\n tmp1=%d\n",gt,tmp1);
	
	if(count==0)
	{
		for (int i=0; i<n; i++)
               {
                   if (t[i] == tmp1) x++;
                   if (t[i] == t[n-1]) y++;
                   }
        ans=x>y?tmp1:t[n-1];
	}else
	{
		ans=gt;
	}
	printf("%d\n",ans);
		
	}
	
	return 0; 
	
}  

