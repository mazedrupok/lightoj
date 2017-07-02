#include <bits/stdc++.h>
#define ll long long
#define sc(N) scanf (" %d", &N)
#define scc(N) scanf (" %c", &N)
#define scs(N) scanf (" %s", N)
#define For(i,N) for (int i = 0; i < N; i++)
#define pb push_back
#define mk make_pair
#define pr pair<int,int>
#define ff first
#define ss second
#define N 100005
using namespace std;

vector <int> g[N];
bool seen[N], Eseen[N], Oseen[N];

void bfs (int src) {
    memset (seen, 0, sizeof (seen));
    memset (Eseen, 0, sizeof (Eseen)); //even seen
    memset (Oseen, 0, sizeof (Oseen)); //odd seen
    queue <pr > q;
    q.push (mk(src, 0));
    while (!q.empty()) {
        pr u = q.front(); q.pop();

        For (i, g[u.ff].size()) {
            int v = g[u.ff][i];
            bool tm = !u.ss;
            if (!seen[v]) {
                q.push(mk(v,tm));
                seen[v] = 1;
                if (tm) Oseen[v] = 1;
                else Eseen[v] = 1;
            }
            else {
                if (tm == 0 && Eseen[v] == 0) {
                    Eseen[v] = 1;
                    q.push (mk(v,tm));
                }
                else if (tm == 1 && Oseen[v] == 0) {
                    Oseen[v] = 1;
                    q.push (mk(v,tm));
                }
            }
        }
    }
}
int main()
{
    //freopen ("in.txt", "r", stdin);
    //freopen ("out.txt", "w", stdout);
    int tc, cs = 0, n, m, x, y;
    sc (tc);
    while (tc--) {
        sc (n); sc (m);
        For (i, m) {
            sc (x); sc (y);
            g[x].pb (y);
            g[y].pb (x);
        }
        bfs (1);
        int cnt = 0;
        For (i, n+1) if (Eseen[i]) cnt++;
        printf ("Case %d: %d\n", ++cs,  cnt);

        vector <int> tt[100005]; swap (tt, g);
    }
    return 0;
}
