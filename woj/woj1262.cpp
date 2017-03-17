#include <stdio.h>
 
int n,ans;
int a[8][8];

void  hbl(int i)
 {
     int temp;
     temp=a[i][n-1];
     int j;
     for(j=n-2;j>=0;j--)
         a[i][j+1]=a[i][j];
     a[i][0]=temp;
 }

void slv(int i)
 {
     if (i!=n)
     {
         int k;
         for(k=0;k<n;k++)
         {
             hbl(i);
             slv(i+1);
         }
     }
     else
     {
         int sum;
         int max;
         int j;
         max=0x80000000;
         for (i=0;i<n;i++)
         {
             sum=0;
             for (j=0;j<n;j++)
             {
                 sum+=a[j][i];
             }
             if (sum>max)
             {
                 max=sum;
             }
         }
         if(max<ans)
         {
             ans=max;
             return ;
         }
     }
 }

void p1262(){
     int i,j;
     while(scanf("%d",&n)==1 && n!=-1)
     {
         for (i=0;i<n;i++)
         {
             for (j=0;j<n;j++)
             {
                 scanf("%d",&a[i][j]);
             }
         }
         ans=0x7fffffff;
         slv(0);
         printf("%d\n",ans);
     }
 }

int main()
 {
     p1262();
     return 0;
 }
