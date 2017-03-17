
#include <stdio.h>
#include <string.h>

char str[2001];
int main()
{
    long long ans;
    long squares[2001], i,  j, k, n, m, s, pos,min, dp[2001], pre[2001];
    
    while (scanf("%ld %ld\n", &n, &m) != EOF)
    {
        for (i = 1; i <= m; i++)
            squares[i] = 0;
        for (s = 1, ans = 0; s <= n; s++)
        {
            gets(str);
            for (i = 0; i < m; i++)
            {
                if (str[i] == 'w')
                    squares[i + 1]++;
                else
                    squares[i + 1] = 0;
            }
            for (i = 1, squares[0] = pre[0] = 0; i <= m; i++)
            {
                if (squares[i] >= squares[i - 1])
                {
                    dp[i] = dp[i - 1] + squares[i];
                    pre[i] = 0;
                }
                else
                {
                    pre[i] = pre[i - 1] + 1;
                    pos = i - pre[i];
                    while ( squares[pos - 1] >= squares[i]&&pos > 0 )
                        pos = pos - pre[pos - 1] - 1;
                    if (pos <= 0)
                    {
                        dp[i] = squares[i] * i;
                        pre[i] = 0;
                    }

                    else
                    {
                        dp[i] = squares[i] * (i - pos + 1) + dp[pos - 1];
                        pre[i] = i - pos - 1;
                    }
                }
                ans += dp[i];
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
