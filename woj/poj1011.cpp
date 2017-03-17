#include<stdio.h>  
#include<iostream>  
 
using namespace std;  
long long combine(long long n, long long k){  
     long long  a=1, b=1,c=1;  
     if (k > n - k)  k = n - k;  
     //rep(i, k) 
	 for (long long  i = 1; i <= k; ++i)  
         a *= n+1-i;  
     for (long long  i = 1; i <= k; ++i)  
         b *= i;  
     return a/b;  
 }  
   
long long solve(long long  n){  
     if (n == 0)  
         return 1;  
     if (n >= 0 && n <= 3)  
         return 1;  
     long long x = n/ 3;  
     long long ans = 0;  
     
	 for (long long  i = 1; i <= x; ++i)   
         ans += solve(3 * i - 1)*solve(n - 3 * i)*combine(n - 1, 3 * i - 1);  
     if (n % 3 == 2)  
         ans += solve(n - 1);  
     return ans;  
 }  

int main(){
     long long gt;
     while (cin>>gt)  
     {  
         if (!gt)  
             cout << 0 << endl;  
         else  
         {  
             long long ansgt = solve(gt);  
             cout << ansgt << endl;  
         }  
     }  
 }
