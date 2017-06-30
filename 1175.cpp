#include <bits/stdc++.h>

#define ll long long
#define sc(N) scanf (" %d", &N)
#define scc(N) scanf (" %c", &N)
#define scs(N) scanf (" %s", N)
#define For(i,N) for (int i = 0; i < N; i++)
const double EPS = 1e-9;
int dx4[]={0,0,-1,1}; int dy4[]={1,-1,0,0}; //4 direction
using namespace std;
int r, c;
char s[205][205];
int dist[205][205];
bool valid (int x, int y) {
    if (x < 0 || y < 0 || x >= r || y >= c) return 0;
    return 1;
}
void bfs (int x, int y) {
    queue <int> q;
    q.push(x); q.push(y);
    dist[x][y] = 0;
    while (!q.empty()) {
        int ux = q.front(); q.pop();
        int uy = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int vx = ux + dx4[i];
            int vy = uy + dy4[i];
            if (valid (vx, vy) == 0) continue;
            if (s[vx][vy] == '#') continue;
            if (dist[ux][uy]+1 < dist[vx][vy]) {
                dist[vx][vy] = dist[ux][uy] + 1;
                q.push (vx);
                q.push (vy);
            }
        }
    }
}
int bfs1 (int x, int y) {
    queue <int> q;
    q.push(x); q.push(y);
    dist[x][y] = 0;
    while (!q.empty()) {
        int ux = q.front(); q.pop();
        int uy = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int vx = ux + dx4[i];
            int vy = uy + dy4[i];
            if (valid (vx, vy) == 0) {
                return dist[ux][uy] + 1;
            }
            if (s[vx][vy] == '#') continue;
            if (dist[ux][uy]+1 < dist[vx][vy]) {
                dist[vx][vy] = dist[ux][uy] + 1;
                q.push (vx);
                q.push (vy);
            }
        }
    }
    return -1;
}
int main()
{
    //freopen ("in.txt", "r", stdin);
    int tc, cs = 0, x, y;
    sc (tc);
    while (tc--) {
        sc (r); sc (c);
        For (i, r)
        For (j, c) {
            scc (s[i][j]);
            dist[i][j] = 1e9;
        }

        For (i, r)
        For (j, c) {
            if (s[i][j] == 'F') {
                bfs (i, j);
            }
            if (s[i][j] == 'J') {x = i; y = j;}
        }
        int res = bfs1 (x, y);
        if (res == -1) printf ("Case %d: IMPOSSIBLE\n", ++cs);
        else printf ("Case %d: %d\n", ++cs, res);
    }
    return 0;
}
