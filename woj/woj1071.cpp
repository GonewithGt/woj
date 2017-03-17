#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <list>
#define N  200010
 
 using namespace std;

  int main() {
      int total = 0;
      cin >> total;

     int number = 0;
     cin >> number;
 
     list<int> * table = new list<int>();
 
     for(int i = 1; i <= total; ++i) {
          table->push_back(i);    
      }
     int shout = 1;  
     int last = 0;
  
     list<int>::iterator next;
     for(list<int>::iterator it = table->begin() ; !table->empty();) {
         if(shout++ == number) {
             last = *it;
             next = it++;;
            table->erase(it);
		//	cout<<last<<" ";   
            it = next;
             shout = 1;
         }
         else
         {
         	it++;
         }
              
 
 
         if(it == table->end())
             it = table->begin();
     }
 
      cout << last << endl;
      
      
      
      return 0;
	   }

