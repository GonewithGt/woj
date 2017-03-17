#include<iostream>
 #include<stdio.h>
 using namespace std;

char a[128][128];
int r , c ;

void sear(int m , int n)
 {
     if (m < r && m >=0 && n < c && n >= 0)\
     {
         if (a[m][n] == 'O')
         {
             a[m][n] = 'X' ;
             sear(m+1,n);
             sear(m+1,n+1);
             sear(m+1,n-1);
             sear(m,n+1);
             sear(m,n-1);
             sear(m-1,n);
             sear(m-1,n-1);
             sear(m-1,n+1);
         }
         else return;
     }
     else return;
 }

void p1167()
 {
     while (scanf("%d%d",&r,&c) == 2 && r*c != 0)
     {
         int res ;
         res = 0 ;
         for (int i = 0 ; i < r ; ++i)
             cin >> a[i];

         for (int i = 0 ; i < r ; ++i)
             for (int j = 0 ; j < c ; ++j)
             {
                 if (a[i][j] == 'O')
                 {
                     res ++ ;
                     sear(i,j);
                 }
             }
         cout << res << endl;
     }
 }

int main ()
 {
     p1167();
     return 0;
 }
