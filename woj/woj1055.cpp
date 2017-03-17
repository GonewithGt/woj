#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;  
  
int main(){  
    string start;  
    string end;
    string gt;
    string data[101]; 
    int len=0;
    
    while(1)
    {
    	 getline(cin,start);
		// getchar();  
    	 if(start.compare("ENDOFINPUT")==0)
    	 break;
    	 else
    	 if(start.compare("START")==0)
    	 {
    	 	 getline(cin,gt);
    	 	 // getchar();
    	     getline(cin,end);
    	     // getchar();
    	 }
    	
    	 
    	 
    	 
    	 
    if(start.compare("START")==0&&end.compare("END")==0)
    {
    	data[len]=gt;
    	len++;
    }
    
}
    
    for(int k=0;k<len;k++)
    	 {
    	 	gt=data[k];
    	 	 for(int j=0;j<gt.size();j++){  
    	 	 
    	 	 /*
            if('A'<=gt[j]&&gt[j]<='Z')
            {
            	gt[j]=gt[j]+21;
            }
			
			if(gt[j]>'Z')
			gt[j]=gt[j]-26;  
			
				 */
				  if('A'<=gt[j]&&gt[j]<='Z')
				 
				 gt[j]=(((gt[j]-'A')-5)+5*26)%26+'A';
        }   
        
         cout<<gt<<'\0'<<endl;  
    	 }
    	
        
       
   
    return 0;  
}   

