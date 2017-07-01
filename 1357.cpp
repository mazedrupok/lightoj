#include <bits/stdc++.h>

#define ll long long
#define sc(N) scanf (" %d", &N)
#define scc(N) scanf (" %c", &N)
#define scs(N) scanf (" %s", N)
#define For(i,N) for (int i = 0; i < N; i++)
#define pb push_back
#define N 100005
using namespace std;

vector <int> g[N];
int child[N];
bool seen[N];
ll p;
void dfs (int u) {
    seen[u] = 1;
    int cnt = 0;
    For (i, g[u].size()) {
        int v = g[u][i];
        if (!seen[v]) {
            dfs (v);
            p += (1LL * cnt * (1+child[v])); //child nodes multiplied
            cnt += (1 + child[v]); //counting child nodes
        }
    }
    child[u] = cnt;
}
int main()
{
    //freopen ("in.txt", "r", stdin);
    //freopen ("out.txt", "w", stdout);
    int tc, cs = 0, n, x, y;
    sc (tc);
    while (tc--) {
        sc (n);
        For (i, n-1) {
            sc (x); sc (y);
            g[x].pb (y);
        }
        memset (seen, 0, sizeof (seen));
        p = 0;
        dfs (1);
        printf ("Case %d: %d %lld\n", ++cs, n-1, p);
        vector <int> tt[100005]; swap (tt, g);
    }
    return 0;
}
