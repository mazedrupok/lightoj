#include <bits//stdc++.h>
using namespace std;
vector <int > vc[10009];
int visit[10009];
void BFS (int src) {
   queue <int > q;
   int visited[10009] = {0};
   visited[src] = 1;
   visit[src]++;
   q.push (src);
   while (q.empty() == 0) {
      int u = q.front ();
      for (int i = 0; i < vc[u].size(); i++) {
         int v = vc[u][i];
         if (visited[v] == 0) {
            visited[v] = 1;
            visit[v]++;
            q.push (v);
         }
      }
      q.pop();
   }
}
int main ()
{
   int tc, cas = 0, k, m, n, u, v;
   //freopen ("in.txt", "r", stdin);
   scanf (" %d", &tc);
   while (tc--) {
      scanf (" %d %d %d", &k, &n, &m);
      int stay[k];
      for (int i = 0; i < k; i++) scanf (" %d", &stay[i]);
      for (int i = 0; i < m; i++) {
         scanf (" %d %d", &u, &v);
         vc[u].push_back (v);
      }
      for (int i = 0; i < k; i++) {
         BFS (stay[i]);
      }
      int cnt = 0;
      for (int i = 0; i < 10009; i++) {
         if (visit[i] == k) cnt++;
      }
      printf ("Case %d: %d\n", ++cas, cnt);
      memset (visit, 0, sizeof (visit));
      vector <int > temp[10009];
      swap (temp, vc);
   }
}
