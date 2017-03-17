#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int a[500005]={0};
bool hash[10000000]={false};

int main()
{
    int i;
    for(i = 1;i<= 500000;i++)
    {
        if(a[i-1]-i>0 && !hash[a[i-1]-i])
        a[i] = a[i-1]-i;
        else
        a[i] = a[i-1]+i;
        hash[a[i]] = true;//hash[a[i]] = true,标志为已经出现过
    }
    while(~scanf("%d",&i),i>=0)
    printf("%d\n",a[i]);

    return 0;
}

