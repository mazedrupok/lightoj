#include <bits/stdc++.h>
#define ll long long
#define mk make_pair
#define ff first
#define ss second
using namespace std;
vector <pair<int,int> > g[1000];
int dfs (int u, int par) {
    int v, w, ret = 0;

    for (int i = 0; i < g[u].size(); i++) {
        v = g[u][i].ff;
        if (v == par) continue;
        w = g[u][i].ss;
        if (w == 1) ret ^= (1 + dfs (v, u));     //colon principle
        else        ret ^= ((w%2) ^ dfs (v, u)); //1 xor if w is odd
    }
    return ret;
}
int main()
{
    int n, u, v, w;
    int tc, cs = 0;
    scanf (" %d", &tc);
    while (tc--) {
        scanf (" %d", &n);
        for (int i = 1; i < n; i++) {
            scanf (" %d %d %d", &u, &v, &w);
            g[u].push_back (mk(v, w));
            g[v].push_back (mk(u, w));
        }
        int test = dfs (0, -1);
        if (test) printf ("Case %d: Emily\n", ++cs);
        else printf ("Case %d: Jolly\n", ++cs);

        vector <pair<int,int> > tt[1000];
        swap (tt, g);
    }
    return 0;
}
