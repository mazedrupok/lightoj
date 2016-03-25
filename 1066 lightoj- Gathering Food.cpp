#include <bits/stdc++.h>
using namespace std;
int fa[] = {1, -1, 0, 0};
int fb[] = {0, 0, -1, 1};
char s[13][13];
int visit[13][13], n;
int bfs (int sr, int sc, int dr, int dc) {
   queue <pair<int,int> > q;
   int level[n+1][n+1];
   q.push (make_pair(sr, sc));
   memset (visit, 0, sizeof (visit));
   visit[sr][sc] = 1;
   level[sr][sc] = 0;
   while (q.empty() == 0) {
      pair <int, int> pi;
      pi = q.front(); q.pop();
      int ua, ub, va, vb;
      ua = pi.first; ub = pi.second;
      for (int i = 0; i < 4; i++) {
         va = ua + fa[i];
         vb = ub + fb[i];
         if (va < 0 || va >= n || vb < 0 || vb >= n) continue;
         if (visit[va][vb] == 0 && s[va][vb] == '.') {
            visit[va][vb] = 1;
            q.push (make_pair(va, vb));
            level[va][vb] = level[ua][ub] + 1;
         }
         if (va == dr && vb == dc) return level[ua][ub] +1;
      }
   }
   return -1;
}
int main ()
{
   int tc, cas = 0, r, c, sr[150], sc[150], x, cnt, k;
   scanf (" %d", &tc);
   while (tc--) {
      scanf (" %d", &n);
      k = 64;
      for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) {
         scanf (" %c", &s[i][j]);
         if (s[i][j] >= 'A' && s[i][j] <= 'Z') {
            k++;
            x = s[i][j];
            sr[x] = i;
            sc[x] = j;
         }
      }

      cnt = 0;
      for (int i = 65; i < k; i++) {
         x = bfs (sr[i], sc[i], sr[i+1], sc[i+1]);
         s[sr[i]][sc[i]] = '.';
         if (x == -1) {
            cnt = -1;
            break;
         }
         else cnt += x;
      }
      if (cnt == -1) printf ("Case %d: Impossible\n", ++cas);
      else printf ("Case %d: %d\n", ++cas, cnt);
   }
   return 0;
}
