#include <iostream>
 #include <cstdio>
 #include <cstring>
 #include <algorithm>
using namespace std;

int main()
 {
     int t=0;
     int n=0;
     int ans=0;
     while(1)
     
     {

     	
     	
         ans=0;
         scanf("%d",&n);
         
         if(n==0)
     	    break;
         if(n==1)
         {
             printf("%d\n",ans);
             continue;
         }
         
         int array[n+1];
         int tmp=0;
         for(int j=0;j<n;j++)
         {
             scanf("%d",&tmp);
             array[j]=tmp;
             
         }
     for(int m=0;m<n-1;m++)
         for(int k=m+1;k<n;k++)
     {
             if(array[m]>array[k])
             ans++;
     }
       
     printf("%d\n",ans);

     }
 }
