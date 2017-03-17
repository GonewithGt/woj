 #include <iostream>
 #include <cstdio>
 #include <cstring>
 #include <vector>
 #include <algorithm>
 
 //#define N 100001*2
 
 int length;
 
 void insert(int *tmp,int nu,int location)
 {
 	while(1)
 	{
 		if(tmp[location]==0)
 	{
 		tmp[location]=nu;
 		
 		if(location>length)
 		length=location;
 		
 		break;
 	}
 	location++;
 
 	}
 	
 }

 int main()
 {
 	int *a;
 	
 	int n;
 	int l;
 	int len;
 	while(1)
 	{
 		scanf("%d",&n);
 		if(n==0)
 		break;
 	a=(int *)malloc((2*n+1)*sizeof(int));
 //	int a[2*n+1];
 	len=2*n+1;
 	for(int i=1;i<=2*n+1;i++)
 	a[i]=0;
 	
 	for(int j=1;j<=n;j++)
 	{
 		scanf("%d",&l);
 	    insert(a,j,l);
 	   // printf("%d",j);
 	}
 	
 
 	
 	printf("%d\n",length);
 	for(int gt=1;gt<length;gt++)
 	{
 		printf("%d ",a[gt]);
 	}
 	
 	
 	printf("%d",a[length]);
 	}
 	
 	
 }
