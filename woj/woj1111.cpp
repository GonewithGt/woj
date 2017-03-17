#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<algorithm>
#define N 10010

using namespace std;

//const int MAX=10010;
double eps=1e-5;
double numbers[N];



int main()

{

        int n, k;

        while(scanf("%d %d", &n, &k)==2) {
        	
        	if(n==0&&k==0)
        	break;

                double max=0;

                for(int i=0;i<n;i++) {

                        scanf("%lf", numbers+i);

                        if(numbers[i]>max)

                                max=numbers[i];

                }


                double left=0;
				double right=max;

                while(right-left>eps) {

                        double middle=(right+left)/2;
                        int sum=0;

                        for(int i=0;i<n;i++)

                        {

                                sum=sum+numbers[i]/middle;

                        }

                        //printf("sum %d\n", sum);

                        if(sum>=k)

                                left=middle;

                        else

                                right=middle;

                }

                printf("%.2lf\n", int(right*100)*0.01);

        }


    return 0;

}

