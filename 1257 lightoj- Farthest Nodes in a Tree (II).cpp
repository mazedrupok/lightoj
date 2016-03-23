#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector <int> g[30009];
vector <int> cost[30009];
int visit[30009], start;
ll mx = -1;
void as_dfs (int u, ll dis) {
   if (dis > mx) {
      mx = dis;
      start = u;
   }
   for (int i = 0; i < g[u].size(); i++) {
      int v = g[u][i];
      int w = cost[u][i];
      if (visit[v] == 0) {
         visit[v] = 1;
         as_dfs (v, dis+w);
      }
   }
}
void bfs (int src, int n, ll *level) {
   queue <int> q;
   memset (visit, 0, sizeof (visit));
   q.push (src);
   visit[src] = 1;
   level[src] = 0;
   while (q.empty() == 0) {
      int u = q.front(); q.pop();
      for (int i = 0; i < g[u].size(); i++) {
         int v = g[u][i];
         if (visit[v] == 0) {
            visit[v] = 1;
            level[v] = level[u] + cost[u][i];
            q.push(v);
         }
      }
   }
}
int main ()
{
   int tc, cas = 0, n, u, v, w;
   //freopen ("in.txt", "r", stdin);
   scanf (" %d", &tc);
   while (tc--) {
      scanf (" %d", &n);
      for (int i = 0; i < n-1; i++) {
         scanf (" %d %d %d", &u, &v, &w);
         g[u].push_back (v);
         g[v].push_back (u);
         cost[u].push_back (w);
         cost[v].push_back (w);
      }
      printf ("Case %d:\n", ++cas);
      memset (visit, 0, sizeof (visit)); visit[0] = 1;
      mx = -1;
      as_dfs (0, 0);

      mx = -1;
      memset (visit, 0, sizeof (visit)); visit[start] = 1;
      int last = start;
      as_dfs (last, 0);

      ll da[n+1], db[n+1];
      bfs (start, n, da);
      bfs (last, n, db);

      for (int i = 0; i < n; i++) {
         ll p = max (da[i], db[i]);
         printf ("%lld\n", p);
      }
      vector <int> temp1[30009];
      vector <int> temp2[30009];
      swap (g, temp1);
      swap (cost, temp2);
   }
   return 0;
}
