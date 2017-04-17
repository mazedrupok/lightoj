#include <bits/stdc++.h>
using namespace std;
int m, n;
int ara[15];
int dp[15][15];
int fun (int i, int prev) {
    if (i > n) return 0;
    if (i == n) return 1;
    int &ret = dp[i][prev];
    if (ret != -1) return ret;
    int cnt = 0;
    for (int j = 0; j < m; j++) {
        if (prev == 0) cnt += fun (i+1, ara[j]);
        else if (abs (prev - ara[j]) <= 2) cnt += fun (i+1, ara[j]);
    }
    return ret = cnt;
}
int main ()
{
    //freopen ("in.txt", "r", stdin);
    int tc, cs = 0;
    scanf (" %d", &tc);
    while (tc--) {
        memset (dp, -1, sizeof (dp));
        scanf (" %d %d", &m, &n);
        for (int i = 0; i < m; i++) scanf (" %d", &ara[i]);
        printf ("Case %d: %d\n", ++cs, fun (0, 0));
    }

    return 0;
}
