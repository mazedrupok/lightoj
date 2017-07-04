#include <bits/stdc++.h>
#define ll long long
#define sc(N) scanf (" %d", &N)
#define scc(N) scanf (" %c", &N)
#define scs(N) scanf (" %s", N)
#define For(i,N) for (int i = 0; i < N; i++)
#define pb push_back
#define mk make_pair
#define pr pair<int,int>
#define prr pair<pr,int>
#define ff first
#define ss second
using namespace std;

const int N = 10005;
const int inf = 1000000000; //10e9
int dx4[]={0,0,-1,1}; int dy4[]={1,-1,0,0}; //4 direction

int n, m, s, t, most;
vector <pr> g[5*N], rg[5*N];
int dist[N], dist2[N];

void haveFun () {
    For (i, N) {dist[i] = inf; dist2[i] = inf;}

    priority_queue <pr , vector<pr >, greater<pr > > q; //small to large
    q.push (mk(0, s));
    dist[s] = 0;
    while (!q.empty()) {
        int u = q.top().ss;
        q.pop();

        For (i, g[u].size()) {
            int v = g[u][i].ff;
            int w = g[u][i].ss;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                q.push (mk(dist[v], v) );
            }
        }
    }

    q.push (mk(0, t));
    dist2[t] = 0;
    while (!q.empty()) {
        int u = q.top().ss;
        q.pop();

        For (i, rg[u].size()) {
            int v = rg[u][i].ff;
            int w = rg[u][i].ss;
            if (dist2[v] > dist2[u] + w) {
                dist2[v] = dist2[u] + w;
                q.push (mk(dist2[v], v) );
            }
        }
    }
    int ans = -1;
    For (i, n) {
        int u = i+1;
        For (j, g[u].size()) {
            int v = g[u][j].ff;
            int w = g[u][j].ss;
            if (dist[u] + w + dist2[v] <= most) {
                ans = max (ans, w);
            }
        }
    }
    printf ("%d\n", ans);
}

int main()
{
    //freopen ("in.txt", "r", stdin);
    //freopen ("out.txt", "w", stdout);
    int tc, cs = 0, u, v, w;
    sc (tc);
    while (tc--) {
        scanf (" %d %d %d %d %d", &n, &m, &s, &t, &most);
        For (i, m) {
            scanf (" %d %d %d", &u, &v, &w);
            g[u].push_back (mk(v, w));
            rg[v].push_back (mk(u, w));
        }
        printf ("Case %d: ", ++cs);
        haveFun ();

        vector <pr > tt1[5*N], tt2[5*N];
        swap (tt1, g); swap (tt2, rg);
    }

    return 0;
}
