#include <bits/stdc++.h>

#define ll long long
#define sc(N) scanf (" %d", &N)
#define scc(N) scanf (" %c", &N)
#define scs(N) scanf (" %s", N)
#define For(i,N) for (int i = 0; i < N; i++)
#define pb push_back
using namespace std;

vector <int> g[50005];
bool seen[50005];
int ara[50005], par[50005], n;

void bfs (int s, int f) {
    queue <int> q;
    q.push(s);
    For (i, 50005) {
        sort (g[i].begin(), g[i].end());
        seen[i] = 0;
        par[i] = -1;
    }
    seen[s] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (u == f) return;
        for (int i = 0; i < g[u].size(); i++) {
            int v = g[u][i];
            if (!seen[v]) {
                q.push(v);
                seen[v] = 1;
                par[v] = u;
            }
        }
    }
}
void pathPrint (int u) {
    if (par[u] == -1) {
        printf ("%d", u);
        return;
    }
    pathPrint (par[u]);
    printf (" %d", u);
}
int main()
{
    //freopen ("in.txt", "r", stdin);
    //freopen ("out.txt", "w", stdout);
    int tc, cs = 0;
    sc (tc);
    while (tc--) {
        sc (n);
        For (i, 50005) g[i].clear();
        For (i, n) {
            sc (ara[i]);
            if (i == 0) continue;
            g[ara[i]].pb (ara[i-1]);
            g[ara[i-1]].pb (ara[i]);
        }
        printf ("Case %d:\n", ++cs);

        bfs (ara[0], ara[n-1]);
        pathPrint(ara[n-1]);
        printf ("\n");
    }
    return 0;
}
