#include <bits/stdc++.h>
using namespace std;
int dp[1005][2][2], home[1005], n;
int fun (int pos, bool prev, bool start) {
    if (pos > n ) return 0;
    if (pos == n) {
        if (start == 0 && prev == 0) return home[pos];
        else return 0;
    }
    int &ret = dp[pos][prev][start];
    if (ret != -1) return ret;
    int a = 0, b = 0;
    if (prev == 0) a = home[pos] + fun (pos+1, 1, start);
    b = fun (pos+1, 0, start);
    return ret = max (a, b);
}
int main ()
{
    int tc, cs = 0;
    scanf (" %d", &tc);
    while (tc--) {
        scanf (" %d", &n);
        for (int i = 1; i <= n; i++) scanf (" %d", &home[i]);
        memset (dp, -1, sizeof (dp));
        int a = fun (2, 0, 0);
        int b = home[1] + fun (2, 1, 1);
        printf ("Case %d: %d\n", ++cs, max(a, b) );
    }
    return 0;
}
