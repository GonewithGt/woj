#include<stdio.h>
 #include<string.h>
 
using namespace std;

void p1316(int n,int r){
     int tmp;
     int a[ 102 ];
     int k, tag, i;
     while (true)
     {
         scanf("%d %d", &n, &r);
         if (n == 0 && r == 0) break;
         if (n == 0)
         {
             printf("0\n");
             continue;
         }
         r *= -1;
         tag = 1;
         if (n < 0)
         {
             tag = 0;
             n *= -1;
         }
         k = 0;
         memset(a, 0, sizeof(a));
         while ( n != 0 )
         {
             tmp = n % r;
             a[k++] = tmp;
             n /= r;
         }
         i=0;
         while (i<102)
         {
             if (a[i] >= r)
             {
                 a[i] %= r;
                 a[i+1] ++;
             }
             
                         if (i%2==tag && a[i])
             {
                 a[i] = r-a[i];
                 a[i+1] ++;
             }
             i ++;
         }
         for (i = i-1; i >= 0; i --){
             if(a[i]!=0) break;
         }
         for (; i >= 0; i --)
         {
             if (a[i] <= 9) printf("%d", a[i]);
             else printf( "%c", 'A'+a[i]-10);
         }
         printf("\n");
     }
 }

int main()
 {
     int s, q;
     p1316(s,q);
     return 0;
 }
