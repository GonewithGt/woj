
#include<iostream>
 #include<string.h>
 using namespace std;

int hbl(int a,int b)
 {
if(a%b!=0) return hbl(b,a%b);
else return b;
 }

void p1122(int n)
 {
int sum,ans[32],num,total[32];
bool mark[32][32];
unsigned long long result;
while(cin>>n&&n)
 {
   memset(mark,false,sizeof(mark));
   sum=0;
   for(int i=n;i>=1;i--)
   {
   cin>>total[i];
   sum+=total[i];
   for(int j=1;j<=total[i];j++)
     mark[i][j]=true;
   }
   
   for(int i=1;i<=sum;i++)
   ans[i]=i;
   result=1;
   for(int i=1;i<=n;i++)
   for(int j=1;j<=total[i];j++)
   {
     if(mark[i][j])
     {
     num=1;
     for(int x=i-1;x>=1;x--)
       if(mark[x][j])
       num++;
     for(int y=j+1;y<=total[i];y++)
       if(mark[i][y])
       num++;
     }  
     for(int x=1;num!=1&&x<=sum;x++)
     if(hbl(ans[x],num)!=1)
     {
       int tmp=hbl(ans[x],num);
       ans[x]/=tmp;
       num/=tmp;
     }
   }
   for(int i=1;i<=sum;i++)
   result*=ans[i];
   cout<<result<<endl;
 }
 }

int main()
 {
int n;
 p1122(n);
return 0;
 }


