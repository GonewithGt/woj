#include<stdio.h>
 #include<string.h>
 int record[110][110];
int a1[110],hbl[110];

void he(int a)
 {
     int m;
     int c,i,temp,divisor;
     m=hbl[a-1];
     c=0;
     for(i=0;i<=m;++i)
     {
         a1[i]=a1[i]*(4*a-2)+c;
         c=a1[i]/10000;
         a1[i]%=10000;
     }
     if(c>0)
     {
         ++m;
         a1[m]=c;
     }
     divisor=a+1,temp=a1[m];
     if(m!=0){
         for(i=m;i>=0;--i)
         {
             if(temp>divisor){
                 a1[i]=temp/divisor;
                 temp%=divisor;
             }
             else{
                 if(i!=m) a1[i]=0;
                 else --m;  
             }
             
             temp=temp*10000+a1[i-1];
         }
     }    
     else a1[0]/=divisor;
     
   
     hbl[a]=m;
     for(i=0;i<=hbl[a];++i)
     {
         record[a][i]=a1[i];
     }
 }

void p1268(int a){
     int i,n;
     for(i=2;i<=100;++i)
     {
         he(i);
     }
     while(scanf("%d",&n)&&n!=-1)
     {
         printf("%d",record[n][hbl[n]]);
         for(i=hbl[n]-1;i>=0;--i)
         {
             printf("%.4d",record[n][i]);
         }
         printf("\n");
     }
 }

int main()
 {
     int h;
     record[1][0]=1;
     hbl[1]=0;
     a1[0]=1;
     p1268(h);
 }
