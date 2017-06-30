#include <bits/stdc++.h>
#define ll long long
#define sc(N) scanf (" %d", &N)
#define scc(N) scanf (" %c", &N)
#define scs(N) scanf (" %s", N)
#define For(i,N) for (int i = 0; i < N; i++)
const double EPS = 1e-9;
using namespace std;
vector <int> f[1005];
int level[1005];
bool seen[1005];
bool pri[1005];
void sieveOfEratosthenes (int limit) { //works in 10^7
   pri[0] = 0; pri[1] = 0;                        //prime number generator.. start
   for (int i = 2; i <= limit; i++) {
      pri[i] = 1;
   }
   for (int i = 2; i <= sqrt(limit); i++) {
      if (pri[i] == 0) continue;
      for (int j = 2; i*j <= limit; j++) {
         pri[i*j] = 0;
      }
   }
}
void factor (int lim) {
    for (int i = 4; i <= lim; i++) {
        for (int j = 2; j <= (i >> 1); j++) {
            if (i %j == 0 && pri[j]) {
                f[i].push_back (j);
            }
        }
    }
}
int bfs (int s, int t) {
    queue <int> q;
    q.push(s);
    level[s] = 0;
    memset (seen, 0, sizeof (seen));
    seen[s] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (u == t) return level[t];
        For (i, f[u].size()) {
            int v = u + f[u][i];
            if (v <= t && seen[v] == 0) {
                seen[v] = 1;
                level[v] = level[u] + 1;
                q.push(v);
            }
        }
    }
    return -1;
}
int main()
{
    //freopen ("in.txt", "r", stdin);
    sieveOfEratosthenes(1000);
    factor (1000);
    int tc, cs = 0, a, b;
    sc (tc);
    while (tc--) {
        sc (a); sc (b);
        printf ("Case %d: %d\n", ++cs, bfs (a, b));
    }
    return 0;
}
