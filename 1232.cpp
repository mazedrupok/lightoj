#include <bits/stdc++.h>
using namespace std;
int ara[101], dp[10001], n;
const int mod = 100000007;
int main ()
{
    //freopen ("in.txt", "r", stdin);
    int tc, cs = 0, k;
    scanf (" %d", &tc);
    while (tc--) {
        scanf (" %d %d", &n, &k);
        for (int i = 0; i < n; i++) scanf (" %d", &ara[i]);
        memset (dp, 0, sizeof (dp));

        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = ara[i]; j <= k; j++) {
                dp[j] += dp[j - ara[i]];
                dp[j] %= mod;
            }
        }
        printf ("Case %d: %d\n", ++cs, dp[k]);
    }

    return 0;
}
