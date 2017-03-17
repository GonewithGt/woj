#include <stdio.h>
 #define MAX 500000
 
int s[MAX];
int t[MAX];

void p1204(int n){
     while (scanf("%d",&n) != EOF){
           int top = 0;
           for (int i=0; i<n; i++)
           {
           
               scanf("%d",&t[i]);
               s[top] = t[i];
               if (top == 0) ++top;
               else if (s[top] != s[top-1]) --top;
               else top++;
               }
           if (top >= 1) printf("%d\n",s[0]);
           else{
               int x=0,y=0;
               for (int i=0; i<n; i++)
               {
                   if (t[i] == s[0]) x++;
                   if (t[i] == s[1]) y++;
                   }
               if (x>y) printf("%d\n",s[0]);
               else printf("%d\n",s[1]);
               }
           }
 }

int main(){
     int num;
     p1204(num);
     return 0;
 }
