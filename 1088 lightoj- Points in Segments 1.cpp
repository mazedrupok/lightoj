#include <bits//stdc++.h>
using namespace std;

int main ()
{
   int tc, cs = 0, n, q, a, b;
   scanf (" %d", &tc);
   while (tc--) {
      scanf (" %d %d", &n, &q);
      int ara[n];
      for (int i = 0; i < n; i++) scanf (" %d", &ara[i]);
      //sort (ara, ara+n); //no need for these library
      printf ("Case %d:\n", ++cs);
      while (q--) {
         scanf (" %d %d", &a, &b);
         int x, y;
         x = lower_bound (ara, ara+n, a)-ara; //counts less of a
         y = upper_bound (ara, ara+n, b)-ara; //counts less equal of b
         //printf ("%d %d\n", x, y);
         printf ("%d\n", y-x);
      }
   }
   return 0;
}
