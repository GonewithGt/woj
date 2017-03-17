#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int partion(int *p, int n)
{
     int idx=n/2;
     swap(p[idx], p[n-1]);
     int i=-1;    
     int j=0;    
     for(j=0; j<n; j++)
     {
            if(p[j]>p[n-1])
            {
				swap(p[++i], p[j]);
            }
     }
     swap(p[++i], p[n-1]);
     return i; 
}

int getMaxK(int *p, int n, int k)
{
	int mid;
     if(k<=0)
            return -1;
     if(n<k)
            return -1;
	 mid=partion(p, n);  
     if(mid == n-k)     
		 return p[mid];
     else if(mid<n-k)
		 return getMaxK(p+mid+1, n-mid-1, k);  
     else
		 return getMaxK(p, mid, k-(n-mid));   
}

int main()
{
	//int num,a[] = {12012, 3, 945, 965, 66, 232, 65, 7, 8, 898, 56, 878, 170, 13, 5};
	int n=0,k=0;
	int t=0;
	int *a;
	int ans=0;
	a=(int *)malloc(5000001*sizeof(int));
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		for(int i=0;i<n;i++)
		{
			scanf("%d",&t);
			a[i]=t;
		}
		ans=getMaxK(a, n, k);
	    printf("%d\n",ans);
		
	}
	

//	system("pause");
	return 0;
}
