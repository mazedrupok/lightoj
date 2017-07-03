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
 
int n, m, k, most;
vector <pair<pr, int> > g[3*N];
int dist[N][15];
void bfs (int src = 0) {
    memset (dist, 63, sizeof (dist));
    priority_queue <prr, vector<prr >, greater<prr> > q;
    q.push (mk(mk(0,0), src)); //distance, already taken which need to be Built, node
    dist[src][0] = 0;
    while (!q.empty()) {
        int u = q.top().ss;
        int d = q.top().ff.ff;
        int tak1 = q.top().ff.ss; //count, which need to be taken
        q.pop();
 
        if (dist[u][tak1] < d) continue; //already less distance
 
        For (i, g[u].size()) {
            int v = g[u][i].ff.ff;
            int w = g[u][i].ff.ss;
            int tak2 = g[u][i].ss + tak1;
            if (tak2 > most) continue;
 
            if (dist[v][tak2] > dist[u][tak1] + w) {
                dist[v][tak2] = dist[u][tak1] + w;
                q.push (mk(mk(dist[v][tak2], tak2), v) );
            }
        }
    }
    int ans = inf;
    For (i, most+1) ans = min (ans, dist[n-1][i]);
    if (ans == inf) printf ("Impossible\n");
    else printf ("%d\n", ans);
}
 
int main()
{
    //freopen ("in.txt", "r", stdin);
    //freopen ("out.txt", "w", stdout);
    int tc, cs = 0, u, v, w;
    sc (tc);
    while (tc--) {
        scanf (" %d %d %d %d", &n, &m, &k, &most);
        For (i, m) {
            scanf (" %d %d %d", &u, &v, &w);
            g[u].push_back (mk(mk(v, w), 0));
        }
        For (i, k) {
            scanf (" %d %d %d", &u, &v, &w);
            g[u].push_back (mk(mk(v, w), 1));
        }
        printf ("Case %d: ", ++cs);
        bfs ();
 
        vector <pair<pr, int> > ttt[3*N];
        swap (ttt, g);
    }
 
    return 0;
}
