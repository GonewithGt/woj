#include<iostream>
 #include<algorithm>
 #include<cstdlib>
 
using namespace std;

int main(){
     int gt=0,j=0;
     cin >> gt;
     for(j=0;j<gt;j++)
	 {
         string a,b;
         int k;
         cin >> a >> b >> k;
         int l = a.length();
         int s[l];
         long int res = 0;
         for (int i=0; i<l; i++)
         {
             s[i] = abs(a[i]-b[i]); 
             res += s[i];
         }
         sort(s,s+l);
         for(int i=l-1; i>(l-1-k); --i){
                 res -= (s[i]==0) ? -1 :s[i] ;
                 }
         cout << res <<endl;
     }
     return 0;
 }
