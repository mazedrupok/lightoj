#include <bits//stdc++.h>
using namespace std;
typedef long long ll;
vector <int > vc[1000];
void bfs (int src, int *level) {
   queue <int > q;
   int visit[110] = {0};
   visit[src] = 1; level[src] = 0;
   q.push (src);
   while (q.empty() == 0) {
      int u = q.front(); q.pop();
      for (int i = 0; i < vc[u].size(); i++) {
         int v = vc[u][i];
         if (visit[v] == 0) {
            visit[v] = 1;
            level[v] = level[u] + 1;
            q.push (v);
         }
      }
   }
}
int main ()
{
   int tc, k = 0;
   int node, edge, x, y, src, des, mx = 0;
   scanf (" %d", &tc);
   while (tc--) {
      scanf (" %d %d", &node, &edge);
      while (edge--) {
         scanf (" %d %d", &x, &y);
         vc[x].push_back(y);
         vc[y].push_back(x);
      }
      scanf (" %d %d", &src, &des);
      int time1[110], time2[110];
      bfs (src, time1);
      bfs (des, time2);
      mx = 0;
      for (int i = 0; i < node; i++) {
         mx = max (mx, time1[i]+time2[i]);
      }
      printf ("Case %d: %d\n", ++k, mx);
      for (int i = 0; i < 110; i++) vc[i].clear();
   }
   return 0;
}
