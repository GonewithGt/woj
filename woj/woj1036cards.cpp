 #include <iostream>
 #include <cstdio>
 #include <cstring>
 #include <vector>
 #include <algorithm>
 
 
 
 


int main()
{
	int n;
	double dp[501];
	
    //unsigned long long dp[501];
	dp[0]=0;
	dp[1]=1;
	dp[2]=2;
	dp[3]=4;
	double ans;
	while (1)

{

    scanf("%d", &n);

    if (n == 0) //���������־��n=0ʱ����Ҫ������

        break;
        
        if(n<=3)
        {
        	ans=dp[n];
        }
        else
        {
        	for(int i=4;i<=n;i++)
        	{
        		dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
        	}
        	ans=dp[n];
        }

   

    printf("%f\n", ans); //��Ҫ���� \n ��ÿ�鴦����ֱ��������ɡ�

}

	
}

