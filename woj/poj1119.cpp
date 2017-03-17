#include <stdio.h>
 #include <math.h>

 #define PI 3.141592653 
#define eps 0.000001


int main()
 {
     double a,b,c,d,h,gt;
     scanf("%lf%lf",&d,&h);
     while(scanf("%lf%lf%lf",&a,&b,&c) == 3)
     {
       if(a<=eps || b<=eps || c<=eps) break;
       a=tan(a*PI/180.0);
       b=tan(b*PI/180.0);
       c=tan(c*PI/180.0);
       gt=d*sqrt(2.0/(1.0/a/a+1.0/c/c-2.0/b/b))+h;
       
       if(gt-(int)gt>=0.5) printf("%d\n",(int)gt+1);
       else printf("%d\n",(int)gt);
     }
     return 0;
 }



