#include <bits/stdc++.h>
using namespace std;
int main ()
{
   //ios_base::sync_with_stdio(false); cin.tie(0);
   int tc, cs = 0, k, cnt, x, y;
   scanf (" %d", &tc);
   while (tc--) {
      scanf (" %d", &k);
      cnt = 0;
      for (int i = 0; i < k; i++) {
         scanf (" %d %d", &x, &y);
         cnt += (y-x-1);
      }
      printf ("Case %d: ", ++cs);
      if (cnt %2 == 0) printf ("Bob\n");
      else printf ("Alice\n");
   }
   return 0;
}

