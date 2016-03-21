//BFS Graph implementation catagory
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector <int > vc[30009];
vector <int > cost[30009];
int n;
void input_vector () {
   int u, v, w;
   scanf (" %d", &n);
   for (int i = 0; i < 30000; i++) {
      vc[i].clear();
      cost[i].clear();
   }
   for (int i = 0; i < n-1; i++) {
      scanf (" %d %d %d", &u, &v, &w);
      vc[u].push_back(v);
      vc[v].push_back(u);
      cost[u].push_back(w);
      cost[v].push_back(w);
   }
}
ll mx = 0; int start = 0;
bool visit[30009];
void result (int u, ll dis) {
   if (dis > mx) {
      mx = dis;
      start = u;
   }

   for (int i = 0; i < vc[u].size(); i++) {
      int v = vc[u][i];
      int w = cost[u][i];
      if (visit[v] == 0) {
         visit[v] = 1;
         result (v, dis+w);
      }
   }
}
int main ()
{
   int tc, k = 0;
   scanf (" %d", &tc);
   while (tc--) {
      input_vector();
      mx = 0;
      memset (visit, 0, sizeof (visit));
      visit[0] = 1;
      result (0, 0);
      mx = 0;
      memset (visit, 0, sizeof (visit));
      visit[start] = 1;
      result (start, 0);
      printf ("Case %d: %lld\n", ++k, mx);
   }
   return 0;
}
