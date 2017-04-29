#include <bits/stdc++.h>
using namespace std;
int dp[101][10001];
int p[101], c[101], w[101];
int fun (int i, int mg) {
    if (i < 0 || mg <= 0) return 0;
    int &ret = dp[i][mg];
    if (ret != -1) return ret;
    int best = 0;
    best = max (best, fun (i-1, mg));
    if (mg - w[i] >= 0) best = max (best, p[i] + fun (i, mg - w[i]));
    return ret = best;
}

int main ()
{
    int tc, cs = 0, n, W, sum;
    scanf (" %d", &tc);
    while (tc--) {
        scanf (" %d %d", &n, &W);
        sum = 0;
        for (int i = 0; i < n; i++) {
            scanf (" %d %d %d", &p[i], &c[i], &w[i]);
            sum += (c[i]*w[i]);
        }
        printf ("Case %d: ", ++cs);
        if (sum > W) printf ("Impossible\n");
        else {
            memset (dp, -1, sizeof (dp));
            printf ("%d\n", fun (n-1, W-sum));
        }
    }

    return 0;
}
