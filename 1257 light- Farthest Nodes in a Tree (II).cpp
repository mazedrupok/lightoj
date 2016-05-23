/*
   Name:  Md. Abdul Mazed
   Noakhali Science & Technology University
   Email:  mazedrupok@gmail.com || mazed4g@gmail.com
   FB id:  www.facebook.com/mazedrupok
   github: www.github.com/mazedrupok

   Catagory: Graph (Minimum Vertex Cover)
   Comment:  MVC by using DP technique.

*/
#include <bits/stdc++.h>
using namespace std;
#define MX  30050
vector <int> g[MX];
vector <int> cost[MX];

int BFS (int src, int n) {
   queue <int> q;
   int level[n]; bool visit[n];
   memset (visit, 0, sizeof (visit));
   visit[src] = 1; level[src] = 0;
   q.push (src);
   while (q.empty() == 0) {
      int u = q.front(); q.pop();
      for (int i = 0; i < g[u].size(); i++) {
         int v = g[u][i];
         if (visit[v] == 0) {
            visit[v] = 1;
            level[v] = level[u] + cost[u][i];
            q.push (v);
         }
      }
   }
   int mx = -1, pos;
   for (int i = 0; i < n; i++) {
      if (level[i] > mx) {
         mx = level[i];
         pos = i;
      }
   }
   return pos;
}
void BFS1 (int src, int n, int *level) {
   queue <int > q;
   bool visit[n];
   memset (visit, 0, sizeof (visit));
   visit[src] = 1; level[src] = 0;
   q.push(src);
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
   int tc, cs = 0, n, u, v, w;
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
      int dis1[n], dis2[n];
      int a = BFS (0, n);
      int b = BFS (a, n);
      BFS1 (a, n, dis1);
      BFS1 (b, n, dis2);
      printf ("Case %d:\n", ++cs);
      for (int i = 0; i < n; i++) {
         printf ("%d\n", max (dis1[i], dis2[i]));
      }
      vector <int> t[MX]; swap (t, g);
      vector <int> t1[MX]; swap (t1, cost);
   }
   return 0;
}
