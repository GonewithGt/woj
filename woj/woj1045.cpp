#include<iostream>  
#include<cstring>  
#include<stdio.h>  
using namespace std;  
  
int main(){  
    string gt;  
    int t;  
    scanf("%d",&t);  
    
    getline(cin,gt);  
    for(int i=0;i<t;i++){  
        getline(cin,gt);  
        if(gt[0]<='z'&&gt[0]>='a')
		gt[0]=gt[0]-32;  
        
		for(int j=1;j<gt.size();j++){  
            if('A'<=gt[j]&&gt[j]<='Z'&&gt[j-1]!=' ')
			gt[j]=gt[j]+32;  
        }   
        cout<<gt<<endl;  
    }  
    return 0;  
}   

