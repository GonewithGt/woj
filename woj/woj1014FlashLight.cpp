#include<stdio.h>
#include<math.h>

int main()
{
    int a1,a2,a3,b1,b2,b3,c1,c2,c3;
    while(scanf("%d%d%d",&a1,&a2,&a3)!=EOF)
    {
      scanf("%d%d%d",&b1,&b2,&b3);  
      scanf("%d%d%d",&c1,&c2,&c3);
      printf("%.2f\n",(double)abs(a1*(b2*c3-b3*c2)-b1*(a2*c3-a3*c2)+c1*(a2*b3-a3*b2)));
    };
   return 0;  
}
