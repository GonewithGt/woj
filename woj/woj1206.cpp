#include <iostream>  
 #include <cstring>  
 #include <string>  
 #include <cstdio>  
 #include <algorithm>  
 using namespace std; 
   
int solve(int a,int b)
 {
     int r;
     if(a==0) return b;
     if(b==0) return a;
     if(a>=b)
     r=a%b;
     else
     {r=a;a=b;b=r; r=a%b;}
     while(r!=0)
     {a=b;b=r;r=a%b;}
     return b;
 }


int main()
 {
    
    int a,b,n;
     while (cin>>a>>b>>n)
     {  
         if (a==0 && b==0 && n==0)  {cout<<"Possible!"<<endl;continue;}
         if (a==0 && b==0 && n!=0)  {cout<<"Impossible!"<<endl;continue;}
         int r = solve(a,b);
         if (n%r == 0)
             cout<<"Possible!"<<endl;
         else  
             cout<<"Impossible!"<<endl; 
     }
     
     return 0;
 }
