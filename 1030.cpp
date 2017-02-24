#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll inf = 1e16;
const int N = 105;
int n, gold[N];
double dp[N];
double f (int u) {
    if (u >= n) return 0.0;
    if (dp[u] > -1) return dp[u];
    int step = min (6, n-u-1);
    double ret = 0.0;
    if (step > 0) {
        for (int i = 1; i <= step; i++) {
            ret += f(u+i); //total ways
        }
        ret /= (double) step; //expectation
    }
    //cout << ret+gold[u] << " " << u << endl;
    return dp[u] = gold[u] + ret;
}
int main ()
{
    #ifndef ONLINE_JUDGE
        freopen ("in.txt", "r", stdin);
    #endif // ONLINE_JUDGE
    //freopen ("out.txt", "w", stdout);
    int tc, cs = 0, x, deno, nume, gc;
    scanf (" %d", &tc);
    while (tc--) {
        scanf (" %d", &n);
        for (int i = 0; i < n; i++) {
            scanf (" %d", &gold[i]);
        }
        memset (dp, -1.0, sizeof (dp));
        printf ("Case %d: %.8f\n", ++cs, f(0));
    }
    return 0;
}
