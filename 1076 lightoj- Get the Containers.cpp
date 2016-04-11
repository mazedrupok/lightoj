#include <bits/stdc++.h>
using namespace std;
int ara[1001];
int main ()
{
   int tc, cs = 0, n, m, hi, lo, k, mid, sum;
   scanf (" %d", &tc);
   while (tc--) {
      scanf (" %d %d", &n, &m);
      hi = 0, lo = 0;
      for (int i = 0; i < n; i++) {
         scanf (" %d", &ara[i]);
         lo = max (lo, ara[i]);
         hi += ara[i];
      }
      while (lo < hi) {
         mid = (lo + hi) /2;
         k = 1, sum = 0;
         for (int i = 0; i < n; i++) {
            sum += ara[i];
            if (sum > mid) {
               sum = ara[i];
               k++;
            }
         }
         if (k <= m) hi = mid;
         else lo = mid + 1;
      }
      printf ("Case %d: %d\n", ++cs, hi);
   }
   return 0;
}

