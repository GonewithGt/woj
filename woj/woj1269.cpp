#include <stdio.h>
int main()
{
    int n=0,m=0;
    int gt=0,tmp=0,i=0;
    int j=0;
    while(scanf("%d%d",&n,&m)!=EOF && n>0)
    {
    	j=0;
    	int a[n];
        gt=1;
        while((gt*(gt-1))/2<m)gt++;
        tmp=(gt*(gt-1))/2;
        for(i=1;i<=n-gt;i++)
        {
        	a[j]=i;
        	j++;
        }
           // printf("%d ",i);
        //printf("%d ",n-tmp+m);
        
        a[j]=n-tmp+m;
        j++;
        for(i=n;i>=n-gt+1;i--)
        {
            if(i!=n-tmp+m)
                //printf("%d ",i);
                {
                	a[j]=i;
                	j++;
                }
        }
        
        for(i=0;i<n;i++)
        {
        	if(i!=n-1)
        	printf("%d ",a[i]);
        	else
        	printf("%d",a[i]);
        }
        printf("\n");
    }
    return 0;
}

