#include <bits/stdc++.h>
using namespace std;
bool vis[1005];
int dp[1005][2];
vector <int> vc[1005];
int fun (int u, bool pre, int par) {
    int &ret = dp[u][pre];
    if (ret != -1) return ret;
    int cnt = pre;
    for (int i = 0; i < vc[u].size(); i++) {
        int v = vc[u][i];
        if (v == par) continue;
        int b = 0, a = fun (v, 0, u);
        if (pre == 0) b = fun (v, 1, u);
        cnt += max (a, b);
    }
    return ret = cnt;
}
int main ()
{
    int tc, cs = 0, n, m, x, y, res;
    scanf (" %d", &tc);
    while (tc--) {
        scanf (" %d %d", &n, &m);
        for (int i = 0; i < m; i++) {
            scanf (" %d %d", &x, &y);
            vc[x].push_back (y);
            vc[y].push_back (x);
        }
        memset (vis, 0, sizeof (vis));
        memset (dp, -1, sizeof (dp));
        res = 0;
        for (int i = 1; i <= n; i++) {
            if (dp[i][0] == -1 || dp[i][1] == -1)
                res += max (fun (i, 0, 0), fun (i, 1, 0));
        }
        printf ("Case %d: %d\n", ++cs, res);
        vector <int> tt[1005]; swap (tt, vc);
    }

    return 0;
}
