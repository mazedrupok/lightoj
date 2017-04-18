#include <bits/stdc++.h>
using namespace std;
int dp[100005];
int a[101], c[101];
int temp[100005];
int main ()
{
    //freopen ("in.txt", "r", stdin);
    int tc, cs = 0, n, m;
    scanf (" %d", &tc);
    while (tc--) {
        scanf (" %d %d", &n, &m);
        for (int i = 0; i < n; i++) scanf (" %d", &a[i]);
        for (int i = 0; i < n; i++) scanf (" %d", &c[i]);
        memset (dp, 0, sizeof (dp));
        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            memset (temp, 0, sizeof (temp));
            for (int j = a[i]; j <= m; j++) {
                if (!dp[j] && dp[j - a[i]] && temp[j - a[i]] < c[i]) {
                    dp[j] = dp[j - a[i]];
                    temp[j] = temp[j - a[i]] + 1;
                }
            }
        }
        int cnt = 0;
        for (int i = 1; i <= m; i++) if (dp[i]) cnt++;
        printf ("Case %d: %d\n", ++cs, cnt);
    }

    return 0;
}
