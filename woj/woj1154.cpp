#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	string str;
	int count=1;
	while(1)
	{
		cin>>str;
		if(str.compare("#")==0)
		break;
		for(int i=1;i<str.size();i=i+2)
		{
			str[i]=str[i]-32;
		}
		
		cout<<"Case "<<count<<": "<<str<<endl;
		count++;
	}
} 

 
