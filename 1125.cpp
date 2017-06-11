#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n, m, d;
int ara[205];
ll dp[205][25][15];
ll fun (int i, int sum, int cnt) {
    if (sum < 0) sum += d; //for negative integers
    if (cnt == m) return sum==0;
    if (i > n) return 0;
    ll &ret = dp[i][sum][cnt];
    if (ret != -1) return ret;
    ret = 0;
    ret += fun (i+1, (sum+ara[i]) %d, cnt+1);
    ret += fun (i+1, sum %d, cnt);
    return ret;
}
int main()
{
    //freopen ("in.txt", "r", stdin);
    int tc, cs = 0, q;
    scanf (" %d", &tc);
    while (tc--) {
        scanf (" %d %d", &n, &q);
        for (int i = 1; i <= n; i++) scanf (" %d", &ara[i]);
        printf ("Case %d:\n", ++cs);
        while (q--) {
            scanf (" %d %d", &d, &m);
            memset (dp, -1, sizeof (dp));
            printf ("%lld\n", fun (1, 0, 0));
        }
    }
    return 0;
}
