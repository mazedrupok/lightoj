#include <bits/stdc++.h>
using namespace std;
vector <long long> vc;
int main ()
{
   int tc, cs = 0, n, w, res;
   long long a, b;
   scanf (" %d", &tc);
   while (tc--) {
      scanf (" %d %d", &n, &w);
      for (int i = 0; i < n; i++) {
         scanf (" %lld %lld", &a, &b);
         vc.push_back (b);
      }
      sort (vc.begin(), vc.end());
      a = vc[0];
      res = 1;
      for (int i = 1; i < vc.size(); i++) {
         if (vc[i] - a > w) {
            res++;
            a = vc[i];
         }
      }
      printf ("Case %d: %d\n", ++cs, res);

      vc.clear();
   }
   return 0;
}
