#include <bits/stdc++.h>
#define ll long long
#define sc(N) scanf (" %d", &N)
#define scc(N) scanf (" %c", &N)
#define scs(N) scanf (" %s", N)
#define For(i,N) for (int i = 0; i < N; i++)
#define pb push_back
#define mk make_pair
#define pr pair<int,int>
#define prr pair<pr, int>
#define ff first
#define ss second
using namespace std;

const int N = 105;
const int inf = 0x3f3f3f3f;
int dx4[]={0,0,-1,1}; int dy4[]={1,-1,0,0}; //4 direction

int n, m, s, t, capacity;
vector <pr> g[N];
int price[N], taka[N][N];

int haveFun () {
    memset (taka, 0x3f, sizeof (taka));
    priority_queue <prr, vector<prr>, greater<prr> > q; //small to large
    taka[s][0] = 0; //start node with 0 liter oil = 0 taka
    q.push (mk(mk(0, 0), s) ); //taka, liter, node
    while (!q.empty()) {
        int ta = q.top().ff.ff;  //previous expense
        int oil = q.top().ff.ss; //remaining liter
        int u = q.top().ss;      //current node
        q.pop();

        if (u == t) return ta; //taka[u][oil]
        For (i, g[u].size()) {
            int v = g[u][i].ff; //next node
            int w = g[u][i].ss; //next path cost
            if (w > capacity) continue;

            if (oil >= w && taka[v][oil-w] > taka[u][oil]) {
                taka[v][oil-w] = taka[u][oil];
                q.push (mk(mk(taka[v][oil-w], oil-w), v) );
            }
        }
        if (oil < capacity && taka[u][oil+1] > taka[u][oil] + price[u]) {
            taka[u][oil+1] = taka[u][oil] + price[u]; //taking 1 liter and checking next
            q.push (mk(mk(taka[u][oil+1], oil+1), u) );
        }
    }
    return -1;
}

int main()
{
    //freopen ("in.txt", "r", stdin);
    //freopen ("out.txt", "w", stdout);
    int tc, cs = 0, u, v, w, q;
    sc (tc);
    while (tc--) {
        sc (n); sc (m);
        For (i, n) sc (price[i]);
        For (i, m) {
            sc (u); sc (v); sc (w);
            g[u].push_back (mk(v, w));
            g[v].push_back (mk(u, w));
        }
        printf ("Case %d:\n", ++cs);
        sc (q);
        while (q--) {
            sc (capacity); sc (s); sc (t);
            int test = haveFun ();
            if (test == -1) printf ("impossible\n");
            else printf ("%d\n", test);
        }

        vector <pr > tt1[N]; swap (tt1, g);
    }

    return 0;
}
