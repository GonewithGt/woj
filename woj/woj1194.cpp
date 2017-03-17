#include <iostream>  
 #include <cstring>  
 #include <string>  
 #include <cstdio>  
 #include <algorithm>  
 using namespace std;  
   
int f[2][10][1<<10],g[12][12],len[10][10];  
string s[10];  

void p1194()
 {
     int i,j,k,m,n,x,l1,l2,p,ans,tmp;  
     while (1)  
     {  
         scanf("%d",&n);  
         if (n<=0) break;  
         memset(len,0,sizeof(len));  
         for (i=0;i<n;i++)  
             cin >> s[i];  
         for (i=0;i<n;i++)  
             for (j=0;j<n;j++)  
             if (i!=j)  
             {  
                 l1=s[i].size();  
                 l2=s[j].size();  
                 memset(g,0,sizeof(g));  
                 for (k=0;k<l1;k++)  
                     for (p=0;p<l2;p++)  
                     {  
                         tmp=0;  
                         for (x=0;k+x<l1 && p+x<l2;x++)  
                             if (s[i][k+x]==s[j][p+x]) tmp++;  
                         len[i][j]=max(len[i][j],tmp);  
                     }  
   
             }  
         m=1<<n;  
         x=0;  
         memset(f[x],255,sizeof(f[x]));  
         for (i=0;i<n;i++)  
             f[x][i][1<<i]=0;  
         for (p=1;p<n;p++)  
         {  
             x^=1;  
             memset(f[x],255,sizeof(f[x]));  
             for (i=0;i<n;i++)  
                 for (j=0;j<m;j++)  
                 if (f[x^1][i][j]>=0)  
                     for (k=0;k<n;k++)  
                     if (((j>>k)&1)==0)  
                         f[x][k][j|(1<<k)]=max(f[x][k][j|(1<<k)],f[x^1][i][j]+len[i][k]);  
         }  
         ans=0;  
         for (i=0;i<n;i++)  
             ans=max(ans,f[x][i][m-1]);  
         printf("%d\n",ans);  
     }  
 }
   
int main()  
 {  
     p1194();
     return 0;
 }  
