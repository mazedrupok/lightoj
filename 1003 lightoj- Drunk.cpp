#include <bits/stdc++.h>
using namespace std;
#define mx 10005
vector <int> g[mx];
vector <int> vc;
int indeg[mx];
int main ()
{
   int tc, cs = 0, cnt = 1, m;
   string s, t;
   map <string, int> mp;

   cin >> tc;
   while (tc--) {
      memset (indeg, 0, sizeof (indeg));
      cnt = 1;
      cin >> m;
      while (m--) {
         cin >> s >> t;
         if (mp[s] == 0) mp[s] = cnt++;
         if (mp[t] == 0) mp[t] = cnt++;
         g[mp[s]].push_back (mp[t]);
         indeg[mp[t]]++;
      }
      //cout << cnt << endl; cnt always 4 for this problem.
      printf ("Case %d: ", ++cs);
      for (int i = 1; i < cnt; i++) {
         if (indeg[i] == 0) vc.push_back (i);
      }
      for (int i = 0; i < vc.size(); i++) {
         int u = vc[i];
         for (int j = 0; j < g[u].size(); j++) {
            int v = g[u][j];
            indeg[v]--;
            if (indeg[v] == 0) vc.push_back (v);
         }
      }
      bool temp = false;
      for (int i = 1; i < cnt; i++) {
         if (indeg[i] > 0) {temp = true; break;}
      }
      if (temp == true ) cout << "No" << endl;
      else cout << "Yes" << endl;

      vector <int> t1[mx];
      swap (t1, g);
      vc.clear();
      mp.clear();
   }
   return 0;
}
