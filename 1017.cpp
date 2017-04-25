#include <bits/stdc++.h>
using namespace std;
#define ll long long
int w, n;
int dp[101][101];
int ara[101];
int fun (int pos, int k) {
    if (k <= 0 || pos >= n) return 0;
    int &ret = dp[pos][k];
    if (ret != -1) return ret;

    int mx = 0;
    for (int i = pos; ara[i] - ara[pos] <= w && i < n; i++) {
        mx = max (mx, i-pos+1 + fun (i+1, k-1));
    }
    mx = max (mx, fun (pos+1, k));
    return ret = mx;
}

int main ()
{
    //freopen ("in.txt", "r", stdin);
    int tc, cs = 0, x, k;
    scanf (" %d", &tc);
    while (tc--) {
        scanf (" %d %d %d", &n, &w, &k);
        for (int i = 0; i < n; i++) {
            scanf (" %d %d", &x, &ara[i]);
        }
        sort (ara, ara+n);
        memset (dp, -1, sizeof (dp));
        printf ("Case %d: %d\n", ++cs, fun (0, k));
    }

    return 0;
}
