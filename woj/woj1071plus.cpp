
#include <iostream>
 #include <list>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
 
int main(int argc, char* argv[])
{  

while(1)
{
	int total=0;  
    ///cout<<"Please input the total num:";  
   // cin>>total;
    
   if(scanf("%d",&total)==EOF)
    	break;    
    int keyNum=0;  
    //cout<<"Please input the key num:";  
    cin>>keyNum;    
      
    list<int>* table=new list<int>();    
    for(int i=1; i<=total; ++i)  
    {   
        table->push_back(i);  
    }    
      
     int shout=1;    
     for(list<int>::iterator it=table->begin(); table->size()!=1;)  
     {   
         if(shout++==keyNum)   
         {    
             cout<<*it<<" ";    
             it=table->erase(it);    
             shout=1;    
         }   
         else   
         {    
             ++it;   
         }      
          
         if(it==table->end())   
         {    
             it=table->begin();   
         }  
     }    
    // cout<<"The last one is:";   
     cout<<*table->begin()<<endl;    
     
}
    
     return 0; 
 }

