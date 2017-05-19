#include <bits//stdc++.h>
using namespace std;
#define ll long long
ll dp[55][55][55];
int m;
ll fun (int n, int k) {
    if (k == 0) return n == 0;
    if (n < 0) return 0;
    ll &ret = dp[n][k][m];
    if (ret != -1LL) return ret;
    ll r = 0LL;
    for (int i = 1; i <= m; i++) r += fun (n-i, k-1);
    return ret = r;
}
int main ()
{
    int tc, cs = 0, n, k;
    scanf (" %d", &tc);
    memset (dp, -1, sizeof (dp));
    while (tc--) {
        scanf (" %d %d %d", &n, &k, &m);
        printf ("Case %d: %lld\n", ++cs, fun (n, k));
    }
    return 0;
}
