#include <bits/stdc++.h>
#define ll long long
#define sc(N) scanf (" %d", &N)
#define scc(N) scanf (" %c", &N)
#define scs(N) scanf (" %s", N)
#define For(i,N) for (int i = 0; i < N; i++)
const double EPS = 1e-9;
using namespace std;
int dxk[]={2,1,-1,-2,-2,-1,1,2}; int dyk[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
char s[11][11];
int r, c;
bool vis[11][11];
int dist[11][11];
vector <int> vc;
bool valid (int x, int y) {
    if (x < 0 || y < 0 || x >= r || y >= c || vis[x][y]) return 0;
    return 1;
}
void bfs (int x, int y) {
    memset (vis, 0, sizeof (vis));
    memset (dist, -1, sizeof (dist));
    queue <int> q;
    q.push (x); q.push (y);
    vis[x][y] = 1;
    dist[x][y] = 0;
    while (!q.empty()) {
        int ux = q.front(); q.pop();
        int uy = q.front(); q.pop();
        for (int i = 0; i < 8; i++) {
            int vx = ux + dxk[i];
            int vy = uy + dyk[i];
            if (valid(vx, vy) ) {
                vis[vx][vy] = 1;
                q.push(vx);
                q.push(vy);
                dist[vx][vy] = dist[ux][uy] + 1;
            }
        }
    }
}
int main()
{
    //freopen ("in.txt", "r", stdin);
    int tc, cs = 0, n;
    sc (tc);
    while (tc--) {
        sc (r); sc (c);
        For (i, r)
            For (j, c) {
                scc (s[i][j]);
                if (s[i][j] != '.') {vc.push_back (i); vc.push_back (j);}
            }
        int ans = 1e9, sum;
        For (i, r)
        For (j, c) {
            bfs (i, j);
            sum = 0;
            for (int k = 0; k < vc.size(); k += 2) {
                int x = vc[k]; int y = vc[k+1];
                if (dist[x][y] == -1) {sum = -1; break;}
                if (dist[x][y] %(s[x][y] - 48) == 0) sum += (dist[x][y] / (s[x][y] - 48));
                else sum += (dist[x][y] / (s[x][y] - 48) + 1);
            }
            if (sum != -1) ans = min (ans, sum);
        }
        if (ans == 1e9) printf ("Case %d: -1\n", ++cs);
        else printf ("Case %d: %d\n", ++cs, ans);
        vc.clear();
    }
    return 0;
}
