#include<string> 

#include<fstream> 

using namespace std; 

  

int cowSolitaire(int *a,int n){  

 

int *f=new int[(n+2)*(n+2)],i,j,Score; 

 

fill(f,f+(n+2)*(n+2),0); 

 

for(i=n;i>=1;i--)  

 

 

for(j=1;j<=n;j++){  

 

 

 

int q=f[(i+1)*(n+2)+j] > f[i*(n+2)+j-1]?f[(i+1)*(n+2)+j] : f[i*(n+2)+j-1]; 

 

 

 

f[i*(n+2)+j] =q+a[(i-1)*n+j-1]; 

 

 

}  

 

 

Score=f[(n+2)+n]; 

 

 

delete[]f;  

 

 

return Score; 

} 

  

int main(){ 

 

int n;  

 

ifstream f1("\inputdata.txt"); 

 

ofstream f2("\outputdata.txt"); 

  

 

f1>> n;  

 

int *A=new int[n*n],i,j; 

 

string item; 

 

for(i=0;i<n;i++)  

 

 

for(j=0;j<n;j++){ 

 

 

 

f1>>item;  

 

 

 

switch(item[0]){  

 

 

 

 

case'A':A[i*n+j]=1;break; 

 

 

 

 

case'T':A[i*n+j]=10;break; 

 

 

 

 

case'J':A[i*n+j]=11;break; 

 

 

 

 

case'Q':A[i*n+j]=12;break; 

 

 

 

 

case'K':A[i*n+j]=13;break; 

 

 

 

 

default:A[i*n+j]=item[0]-'0'; 

 

 

 

} 

 

 

}  

 

 

f2<<cowSolitaire(A,n)<<endl; 

 

 

delete[]A;  

 

 

f1.close();f2.close(); 

 

 

return 0; 

}  

