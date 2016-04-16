#include <bits/stdc++.h>
using namespace std;
int main ()
{
   int tc, cs = 0, n, k, d;
   scanf (" %d", &tc);
   while (tc--) {
      scanf (" %d", &n);
      int ara[n];
      k = 0;
      for (int i = 0; i < n; i++) {
         scanf (" %d", &ara[i]);
         if (i == 0) {k = ara[i]; continue;}

         d = ara[i] - ara[i-1];
         if (d > k) k = d;
         else if (d == k) k++;
      }
      printf ("Case %d: %d\n", ++cs, k);
   }
   return 0;
}
