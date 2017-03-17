#include<stdio.h>
 
void p1103(){
     int t,n;
     char c;
     scanf("%d",&t);
    
     while(t--){
         scanf("%d",&n);
         scanf("%c",&c);
         float n1=(float)n/100.00;
         printf("%.2f%%\n",100.00*n1*n1/(1.00-2.00*n1*(1.00-n1)));
     }
 }

int main(){
     p1103();
     return 0;
 }
