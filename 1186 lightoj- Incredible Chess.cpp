#include <bits/stdc++.h>
using namespace std;
int main ()
{
   int tc, n, cs = 0, res;
   scanf (" %d", &tc);
   while (tc--) {
      scanf (" %d", &n);
      int w[n], b[n];
      for (int i = 0; i < n; i++) scanf (" %d", &w[i]);
      for (int i = 0; i < n; i++) scanf (" %d", &b[i]);
      res = 0;
      for (int i = 0; i < n; i++) res ^= (b[i] - w[i] - 1);
      if (res) printf ("Case %d: white wins\n", ++cs);
      else printf ("Case %d: black wins\n", ++cs);
   }
}

