#include<stdio.h>
 
int GtoB(int m){
     int r,res=0;
     if(m==0) return 0;
     while(m>1){
         res^=(m%2);
         m/=2;
     }
     return res^1;
 }
 
int solve(int m)
{
	int count=0;//count 1
	while(m>=1){
         if(m%2==1)
         ++count;
         m/=2;
     }
     
     if(count%2)
     return 1;
     else
     return 0;
}

int main(){
	
	int n;
     while(scanf("%d",&n)!=EOF)
     {
     	int b[n][n];//,g[n][n]
     	int gt,i,j;
     for(i=0;i<n;i++)
         for(j=0;j<n;j++){
             scanf("%d",&gt);
             b[i][j]=solve(gt);
         }
     for(i=0;i<n;i++){
         for(j=0;j<n;j++){
			 if(j==n-1) printf("%d\n",b[i][j]);
                 else printf("%d ",b[i][j]);
         }
     }
     }
    
     return 0;
 }
