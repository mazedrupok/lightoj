#include <bits//stdc++.h>
using namespace std;
#define inf 2147483647
vector <int> G[105];
vector <int> cost[105];
int dis[105];
struct node {
   int city; int dist;
   node (int a, int b) {city = a; dist = b;}
   bool operator < (const node &p) const {
      return dist < p.dist; //large to small..
   }
};
int dijkstra (int src, int n) {
   for (int i = 0; i < 105; i++) dis[i] = inf;
   priority_queue <node > pq;
   dis[src] = 0;
   pq.push(node(src, 0));
   while (!pq.empty()) {
      node a = pq.top(); pq.pop();
      int u = a.city;
      
      int len = G[u].size();
      for (int i = 0; i < len; i++) {
         int v = G[u][i];
         if (dis[v] > dis[u] + cost[u][i]) {
            dis[v] = dis[u] + cost[u][i];
            pq.push (node (v, dis[v]));
         }
      }
   }
   return dis[n];
}
int main ()
{
   int tc, cas = 0, u, v, w, e, n;
   int ara[105][105];
   //freopen ("in.txt", "r", stdin);
   scanf (" %d", &tc);
   while (tc--) {
      scanf (" %d %d", &n, &e);
      for (int i = 0; i <= n; i++)
         for (int j = 0; j <= n; j++) ara[i][j] = inf;
      for (int i = 0; i < e; i++) {
         scanf (" %d %d %d", &u, &v, &w);
         if (u > v) swap (u, v);   //bidirected graph.. u-v same as v-u
         ara[u][v] = min (w, ara[u][v]); //same node can be appear again & again.. so I take their minimum
      }
      for (int i = 0; i <= n; i++)
         for (int j = 0; j <= n; j++) {
            if (ara[i][j] != inf) {
               G[i].push_back (j);
               G[j].push_back (i);
               cost[i].push_back (ara[i][j]);
               cost[j].push_back (ara[i][j]);
            }
         }
      int res = dijkstra(1, n);
      if (res == inf) printf ("Case %d: Impossible\n", ++cas);
      else printf ("Case %d: %d\n", ++cas, res);

      vector <int > t1[105], t2[105];
      swap (G, t1); swap (cost, t2);
   }
}
