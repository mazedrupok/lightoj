#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int inf = 1e9;
const int N = 102;
int ara[N];
int dp[N][N];
int fun (int l, int r) {
    if (l > r) return 0;
    if (dp[l][r] != -1) return dp[l][r];
    int p = 0, mx = -inf;
    for (int i = l; i <= r; i++) {
        p += ara[i];
        mx = max (mx, p - fun (i+1, r));
    }
    p = 0;
    for (int i = r; i >= l; i--) {
        p += ara[i];
        mx = max (mx, p - fun (l, i-1));
    }
    return dp[l][r] = mx;
}

int main()
{
    int tc, cs = 0, res, n;
    scanf (" %d", &tc);
    while (tc--) {
        scanf (" %d", &n);
        for (int i = 0; i < n; i++) scanf (" %d", &ara[i]);
        memset (dp, -1, sizeof (dp));
        res = fun (0, n-1);
        printf ("Case %d: %d\n", ++cs, res);
    }

    return 0;
}
