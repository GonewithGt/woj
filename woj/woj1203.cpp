#include<iostream>
#include<cstring>
#include<cstdlib>
#include<deque>
using namespace std; 

int main()  
{  

	int n;
	while(cin>>n){
		
		deque<int> gt;
	for(int i=0;i<n;i++)
	{
		int tmp;
		cin>>tmp;
		if(gt.empty())
		{
			gt.push_back(tmp);
		}else
		{
			if(gt.front()==tmp)
			{
				gt.push_back(tmp);
			}else
			{
				gt.pop_back();
			}
		}
	}
	
	cout<<gt.front()<<endl;
		
	}
	
	return 0; 
	
}  

