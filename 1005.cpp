#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int n;
bool col[31] = {0};
ll dp[31][901];
ll fun (int i, int remain) {
    if (remain == 0) return 1;
    if (i == 0) return 0;
    ll &ret = dp[i][remain];
    if (ret != -1) return ret;

    ret = 0;
    for (int p = 1; p <= n; p++) {
        if (col[p] == 0) {
            col[p] = 1;
            ret += fun (i-1, remain-1);
            col[p] = 0;
        }
    }
    ret += fun (i-1, remain);

    return ret;
}

int main ()
{
    int tc, cs = 0, k;
    scanf (" %d", &tc);
    while (tc--) {
        scanf (" %d %d", &n, &k);
        memset (col, 0, sizeof (col));
        memset (dp, -1, sizeof (dp));
        printf ("Case %d: %lld\n", ++cs, fun (n, k));
    }
    return 0;
}
