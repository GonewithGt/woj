#include<iostream>
#include<cstring>
#include<cstdlib>
#include<deque>
using namespace std; 

int main()  
{  

	int n;
	while(cin>>n){
		int gt=0,tmp=0,count=0;
	
	for(int i=0;i<n;i++)
	{
		cin>>tmp;
		if(count==0)
		{
			gt=tmp;
			count++;
		}else if(gt==tmp)
		{
			count++;
		} else
		{
			count--;
		}
	}
	
	cout<<gt<<endl;
		
	}
	
	return 0; 
	
}  

