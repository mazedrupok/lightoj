#include <bits/stdc++.h>

#define ll long long
#define sc(N) scanf (" %d", &N)
#define scc(N) scanf (" %c", &N)
#define scs(N) scanf (" %s", N)
#define For(i,N) for (int i = 0; i < N; i++)
const double EPS = 1e-9;

using namespace std;

int p = 0;
int seen[1005], ara[1005];
vector <int> g[10005];

void dfs (int u) {
    seen[u] = p;
    For (i, g[u].size()) {
        int v = g[u][i];
        if (!seen[v]) dfs (v);
    }
}
int main()
{
    //freopen ("in.txt", "r", stdin);
    int tc, cs = 0, n, m, u, v;
    sc (tc);
    while (tc--) {
        sc (n); sc (m);
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            sc (ara[i]);
            sum += ara[i];
        }
        For (i, m) {
            sc (u); sc (v);
            g[u].push_back (v);
            g[v].push_back (u);
        }

        memset (seen, 0, sizeof (seen));
        bool flag = true;
        int prev = -1;
        for (int i = 1; i <= n; i++) {
            if (!seen[i]) {
                p++;
                dfs (i);
                int temp = 0, cnt = 0;
                for (int j = 1; j <= n; j++) {
                    if (seen[j] == p) {
                        temp += ara[j];
                        cnt++;
                    }
                }
                if (temp %cnt) {flag = false; break;}
                temp /= cnt;
                if (prev != -1 && temp != prev) {flag = false; break;}
                prev = temp;
            }
        }
        if (flag ) printf ("Case %d: Yes\n", ++cs);
        else       printf ("Case %d: No\n", ++cs);
        vector <int> tt[10005]; swap (g, tt);
    }
    return 0;
}
