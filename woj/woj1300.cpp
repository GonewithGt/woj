#include <cstdio>
#include <iostream>
using namespace std;
 

int main(){
     int gt;
     
     cin>>gt;
     
      for(int i=0;i<gt;i++){
         int n;
        
         cin>>n;
         if (n%7 != 0 && n%7 != 1) 
         cout<<"Sproblvem"<<endl;
         else
         cout<<"Dzs"<<endl;
     }
     return 0;
 }
