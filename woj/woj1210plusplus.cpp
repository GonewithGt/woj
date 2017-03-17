#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std; 

int dp[10001];

void solve(string a,string b,int length1,int length2)
{
	int i,j;
	int tmp1=0,tmp2=0,tmp3=0;//tmp1=dp[i-1][j-1] tmp2=dp[i][j-1] tmp3=dp[i-1][j]
	  
        for(i=0;i<=length2;i++)  
       {  
            dp[i]=0;  
        } 
        
        for(i=1;i<=length1;i++)  
        {  
           
          for(j=1;j<=length2;j++)  
            {  
            	
            	tmp3=dp[j];
            	
                if(a[i-1]==b[j-1])  
                {  
                   dp[j]=tmp1+1;
                }  
               else  
               {  
				   dp[j]=tmp2>tmp3?tmp2:tmp3; 
               } 
               
			   tmp1=tmp3; 
			   tmp2=dp[j];
			}  
			
		   tmp1=0;
           tmp2=0;
           tmp3=0;
           
       }  
       //printf("%d\n",dp[length2]);  
       cout<<dp[length2]<<endl;
	
}
int main()  
{  
	int length1,length2;
	string a,b;  
    while(cin>>a>>b)
    {  
        length1=strlen(a.c_str());  
        length2=strlen(b.c_str());
        solve(a,b,length1,length2);
    }  
    return 0;  
}  


