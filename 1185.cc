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
bool color[N][3];
void dfs (int u, int col) {
    if(col != -1) color[u][col] = 1;
    int nextColor;
    if (col == 1) nextColor = 2;
    else nextColor = 1;
    For (i, g[u].size()) {
        int v = g[u][i];
        if (!color[v][nextColor]) dfs (v, nextColor);
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
        memset (color, 0, sizeof (color));
        dfs (1, -1);
        int cnt = 0;
        For (i, n+1) if (color[i][2]) cnt++;
        printf ("Case %d: %d\n", ++cs,  cnt);

        vector <int> tt[100005]; swap (tt, g);
    }
    return 0;
}
