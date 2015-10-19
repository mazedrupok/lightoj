#include <iostream>
#include <cstdio>
using namespace std;
int main ()
{
   int cas, i, j, k, p;
   long long n, m;
   long long fact[25];
   int ara[25];
   fact[0] = 1;
   for (i = 1; i <= 20; i++) {
      fact[i] = 1;
      fact[i] = fact[i-1] * i;
   }
   /*for (i = 0; i <= 20; i++) {
      printf ("%lld\n", fact[i]);
   }*/
   scanf (" %d", &cas);
   for (k = 1; k <= cas; k++) {
      scanf (" %lld", &n);
      m = n;
      p = 0;
      for (i = 20; i >= 0 && m > 0; i--) {
         if (m >= fact[i]) {
            ara[p++] = i;
            m = m - fact[i];
         }
      }

      if (m == 0) {
         printf ("Case %d: ", k);
         for (i = p-1; i >= 0; i--) {
            printf ("%d!", ara[i]);
            if (i != 0) printf ("+");
         }
         printf ("\n");
      }
      else printf ("Case %d: impossible\n", k);
   }
   return 0;
}
