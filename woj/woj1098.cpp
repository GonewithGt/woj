 #include <iostream>
 #include <cstdio>
 #include <string>
 #include <algorithm>
using namespace std;

int count(string str,string str1)
{
	
	int len1=str.size();
	int len2=str1.size();
	int count[len1+1];
	int out=0;
	for(int i=0;i<len1;i++)
	count[i]=0;
	if(len1<len2)
	return 0;
	else
	{
		for(int j=len2;j<len1;j++)
		{
			if(str.compare(j-len2,len2,str1)==0)
			count[j]=count[j-len2]+1;
			if(count[j]>out)
			out=count[j];
		} 
	}
	
	return out;
}

int main()
{
	int t;
	cin>>t;
	string str;
	string str1="dongfangxu";
	string str2="zap";
	for(int i=0;i<t;i++)
	{
		int a=0;
		int b=0;
		//getline(cin,str);
		cin>>str;
		a=count(str,str1);
		b=count(str,str2);
		//cout<<"a="<<a<<"b="<<b;
		if(a>=b)
		{
			printf("dongfangxu!\n");
		}else
		{
			printf("zap!\n");
		}
	}
	
	return 1;
}
