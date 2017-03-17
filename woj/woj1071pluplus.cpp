#include <iostream>
#include <list>
using std::cout;
using std::endl;
using std::cin;
using std::list;
 
int main()
{
    int total  = 0;
   // cout << "Please input total number of people : ";
    cin >> total;
 
    int number = 0;
   // cout << "Please input selected number : ";
    cin >> number;
 
    /* If number = 3
     * f(1) = 0
     * f(2) = 1 = (f(1) + 3) % 2
     * f(3) = 1 = (f(2) + 3) % 3
     * f(4) = 0 = (f(3) + 3) % 4
     * f(5) = 3 = (f(4) + 3) % 5
     * ...
     * f(n) = x = (f(n-1) + 3) % n
     * */
 
    int last = 0; // f(1) = 0
    for(int i = 2; i <= total; ++i)
    {
        last = (last + number) % i;
        
         cout << last + 1 << endl;
    }
    cout << "The last one is : " << last + 1 << endl;
 
    return 0;
}

