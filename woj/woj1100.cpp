 #include <iostream>
 #include <string>
 #include <cstdio>
 #include <cstdlib>
 using namespace std;


int main()
{
	int t;
//	int countnu=0;	
	int ans=0;
//	int tmp=0;
	int gt=0;
	
	int len=0;
	cin>>t;
	char *str;
	string str1[8]={"littleken","knuthocean","dongfangxu","zap","kittig","robertcui","forest","flirly"};//9 10 10 3 6 9 6 6
	string str2[8]={"li","kn","do","za","ki","ro","fo","fl"};
	int count[8];
	//string str2="zap";
	str=(char *)malloc(1000001*sizeof(char));
	for(int i=0;i<t;i++)
	{
	
		//getline(cin,str);
		
		for(int t=0;t<1000001;t++)
		{
			str[t]=0; 
		}
		
		ans=0;
		gt=0;
		len=0;
			for(int s=0;s<8;s++)
		{
			count[s]=0;
		
		}
		
		//cin>>str;
		scanf("%s",str);
		
		for(int k=0;k<1000001;k++)
		{
			if(str[k]>='a'&&str[k]<='z')
			{
				len++;
			}
		}
		
		//cout<<str;
		/*
		for(int j=1;j<str.size()-1;j++)
		{
			
			for(int k=0;k<8;k++)
			{
				if(str.compare(j,2,str2[k])==0)
				count[k]=count[k]+1;
			}
			
		}*/
		
		for(int j=0;j<len;)
		{
			//9 10 10 3 6 9 6 6
			
		//	"li","kn","do","za","ki","ro","fo","fl"
			if(str[j]=='l'&&str[j+1]=='i')
			{
				j=j+9;
				count[0]=count[0]+1; 
			}
			if(str[j]=='k'&&str[j+1]=='n')
			{
				j=j+10;
				count[1]=count[1]+1;
			}
			if(str[j]=='d'&&str[j+1]=='o')
			{
				j=j+10;
				count[2]=count[2]+1;
			}
			if(str[j]=='z'&&str[j+1]=='a')
			{
				j=j+3;
				count[3]=count[3]+1;
			}
			if(str[j]=='k'&&str[j+1]=='i')
			{
				j=j+6;
				count[4]=count[4]+1;
			}
			if(str[j]=='r'&&str[j+1]=='o')
			{
				j=j+9;
				count[5]=count[5]+1;
			}
			if(str[j]=='f'&&str[j+1]=='o')
			{
				j=j+6;
				count[6]=count[6]+1;
			}
			if(str[j]=='f'&&str[j+1]=='l')
			{
				j=j+6;
				count[7]=count[7]+1;
			}
		
			
		}
		
		
		
		for(int m=0;m<8;m++)
		{
			//cout<<count[m]<<endl;
			if(count[m]>ans)
			{
					ans=count[m];
			         gt=m;
			}
		
		}
	
		cout<<str1[gt]<<"\n";
		//cout<<"a="<<a<<"b="<<b;
		
	}
	
	return 1;
}
