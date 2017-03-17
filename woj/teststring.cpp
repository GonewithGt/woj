#include<iostream>  
#include<cstring>
#include<cstdlib>
using namespace std; 

int main()
{
	string word;
	while(cin>>word)
		cout<<word<<strlen(word.c_str())<<endl;
		
	return 0;
} 
