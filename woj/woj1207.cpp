#include<iostream>
 #include<string>
 
using namespace std;

string huiwen(string s){
       string s1 = "",s2 = "";
       int len,n;
       len = s.length();
       if (len%2 == 0){
                 n = len/2;
                 for (int i=0; i<n; i++){
                 s1 += s[n-1-i]; s2 += s[n+i];}
                 if (s1 > s2){
                         for (int i=0; i<n; i++) s[n+i] = s1[i];
                         }
                 else if (s1 == s2){}
                 else{
                       --n;
                       while(s[n] == '9' && n >=0){s[n] = '0';--n;}
                       if (n >=0){
                                 s[n] += 1;
                                 for (int i=len/2; i<len; i++) s[i] = s[len-1-i];
                                 }
                       else {
                           for (int i=0; i<len-1; i++) s[i] = '0';
                           s[len-1] = '1'; 
                           s.insert(0,1,'1');
                           }
                       }

                 }
       else{
             n = (len-1)/2;
             for (int i=0; i<n; i++) {s1 += s[n-1-i]; s2 += s[n+1+i];}
             if (s1 > s2){
               for (int i=0; i<n; i++) s[n+1+i] = s1[i];
               }
             else if (s1 == s2){}
             else{
                   while(s[n] == '9' && n >= 0){s[n] = '0';--n;}
                   if (n >=0){
                     s[n] += 1;
                     for (int i=(len-1)/2; i<len; i++) s[i] = s[len-i-1];
                     }
                   else{
                       for(int i=0; i<len-1; i++) s[i] = '0';
                       s[len-1] = '1';
                       s.insert(0,1,'1');
                       }
                   }
             }
       return s;
       }
       
void p1207(){
     string s;
     while(cin>>s)
     {
         cout << huiwen(s) << endl;
     }
 } 

int main(){
     p1207();
     return 0;
 }
