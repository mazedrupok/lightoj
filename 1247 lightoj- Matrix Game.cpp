#include <bits/stdc++.h>
using namespace std;
int main ()
{
   //ios_base::sync_with_stdio(false); cin.tie(0);
   int tc, cs = 0, r, c, cnt, x, res;
   scanf (" %d", &tc);
   while (tc--) {
      scanf (" %d %d", &r, &c);
      res = 0;
      for (int i = 0; i < r; i++) {
         cnt = 0;
         for (int j = 0; j < c; j++) {
            scanf (" %d", &x);
            cnt += x;
         }
         res ^= cnt;
      }
      printf ("Case %d: ", ++cs);
      if (!res) printf ("Bob\n");
      else printf ("Alice\n");
   }
   return 0;
}

