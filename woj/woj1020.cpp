 #include <iostream>
 #include <cstdio>
 #include <cstring>
 #include <vector>
 #include <algorithm>
 
 using namespace std;
 
 //int a[1001];
 
 int main()
 {
 	int t;
 	int n;
 	scanf("%d",&t);
 	for(int i=0;i<t;i++)
 	{
 		scanf("%d",&n);
 		int a[n];
 		int pre=0,num=0;
 		for(int j=0;j<n;j++)
 		{
 			scanf("%d",&num);
 			a[j]=num-pre;
 			pre=num;
 		}
 		
 		sort(a,a+n);
 		printf("Case %d:\n",i+1);
 		if(n>1)
 		{
 			for(int k=0;k<n-1;k++)
 		     printf("%d ",a[k]);
 		     
 		     
 		}
 		
 		printf("%d",a[n-1]);
 		
 		printf("\n");
 	}
 	
 	return 0;
 }
