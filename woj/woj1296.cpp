
#include <cstdio>
#include <iostream>
using namespace std;
 



int main(){
	
	int n;
     while(cin>>n&&n!=0)
     {
     	if(n % 2 == 0)
     	cout<<"No Solution!"<<endl;
         else
         cout<<n-1<<endl; 
            
     }
     return 0;
 }



