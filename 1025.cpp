#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int inf = 1e9;
const int N = 62;
char s[N];
ll dp[N][N];
ll fun (int l, int r) {
    if (l > r) return 0;
    if (l == r) return 1;
    ll &p = dp[l][r];
    if (p != -1) return p;
    p = 0;
    if (s[l] == s[r]) p = 1 + fun (l+1, r-1);
    p += (fun (l+1, r) + fun (l, r-1) - fun (l+1, r-1));
    return p;
}
int main ()
{
    #ifndef ONLINE_JUDGE
        freopen ("in.txt", "r", stdin);
    #endif // ONLINE_JUDGE
    int tc, cs = 0, n;
    ll res;
    scanf (" %d", &tc);
    while (tc--) {
        scanf (" %s", s);
        memset (dp, -1, sizeof (dp));
        res = fun (0, strlen(s)-1);
        printf ("Case %d: %lld\n", ++cs, res);
    }

    return 0;
}
