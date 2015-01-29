#include <stdio.h>
#include <math.h>
int main ()
{
   long long n, m, x, i;
   int a, cas, k;
   scanf (" %d", &cas);
   for (k = 1; k <= cas; k++) {
      scanf (" %lld", &x);
      if (x <= 5) {
         printf ("Case %d: Impossible\n", k);
         continue;
      }
      if (x %2 == 1) {
         printf ("Case %d: Impossible\n", k);
         continue;
      }
      n = 4611686018427387904;
      a = 0;
      for (i = n; i >= 8; i /= 2) {
         if (x == i) {
            printf ("Case %d: Impossible\n", k);
            a = 2;
            break;
         }
      }
      if (a == 2) continue;
      for (i = 2; i <= x/2; i++) {
         if (x % i == 0) {
            m = i;
            n = x / i;
            if (n % 2 == 1) {
               printf ("Case %d: %lld %lld\n", k, n, m);
               a = 2;
               break;
            }
         }
         i++;
      }
      if (a != 2)  printf ("Case %d: Impossible\n", k);
   }
   return 0;
}
