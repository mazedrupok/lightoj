#include <bits/stdc++.h>
using namespace std;
int dp[101][101];
int n, a[101];
int fun (int lo, int hi) {
    if (lo > hi) return 0;  //invalid case
    if (lo == hi) return 1; //have only 1 dress
    int &ret = dp[lo][hi];
    if (ret != -1) return ret;
    int best = 1 + fun (lo+1, hi); //not dress off

    for (int i = lo+1; i <= hi; i++) {
        if (a[lo] == a[i]) {
            best = min (best, fun (lo+1, i-1) + fun (i, hi)); //divided in sub-program
        }
    }
    return ret = best;
}
int main ()
{
    int tc, cs = 0;
    scanf (" %d", &tc);
    while (tc--) {
        scanf (" %d", &n);
        for (int i = 0; i < n; i++) scanf (" %d", &a[i]);
        memset (dp, -1, sizeof (dp));
        printf ("Case %d: %d\n", ++cs, fun (0, n-1));
    }

    return 0;
}
