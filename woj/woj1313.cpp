#include<iostream>  
 #include<cmath>  
 #include<stdio.h>  
 using namespace std; 

void p1313(int s)
 {
     int result[100];  
     int k=0;  
     while(s!=0)  
     {  
         int a[1000]={0};  
         for(int i=1;;i++)  
         {  
             int tmp=1;  
             int flag=0;  
             for(int j=0;j<i;j++){  
                 if(tmp*s>=1000)flag=1;  
                 tmp=(tmp*(s%1000))%1000; 
                   
             }  
             if(flag==1&&a[tmp]==0)  
                 {  
                 a[tmp]=i;  
                 }  
             else if(flag==1&&a[tmp]!=0)  
             {  
                 result[k++]=a[tmp]+i;  
                 break;  
             }  
         }  
         cin>>s;  
     }  
     for(int i=0;i<k;i++){  
         cout<<result[i]<<endl;  
     }  
 }

int main()  
 {  
     int b;  
     cin>>b;  
     p1313(b);
     return 0;        
 } 
