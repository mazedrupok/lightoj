#include <bits/stdc++.h>
using namespace std;
int dp[10005];
int fn (int n) {
    if (dp[n] != -1) return dp[n]% 10000007;
    dp[n-1] = fn(n-1)% 10000007;
    dp[n-2] = fn(n-2)% 10000007;
    dp[n-3] = fn(n-3)% 10000007;
    dp[n-4] = fn(n-4)% 10000007;
    dp[n-5] = fn(n-5)% 10000007;
    dp[n-6] = fn(n-6)% 10000007;
    return dp[n] = (dp[n-1] + dp[n-2] + dp[n-3] + dp[n-4] + dp[n-5] + dp[n-6])% 10000007;
}
int main()
{
    int n, caseno = 0, cases, a, b, c, d, e, f;
    scanf("%d", &cases);
    while( cases-- ) {
        scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &n);
        memset (dp, -1, sizeof (dp));
        dp[0] = a;
        dp[1] = b;
        dp[2] = c;
        dp[3] = d;
        dp[4] = e;
        dp[5] = f;
        printf("Case %d: %d\n", ++caseno, fn(n) % 10000007);
    }
    return 0;
}
