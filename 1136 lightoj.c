#include <stdio.h>
int main ()
{
   long long a, b, cas, k, i, temp, count, m;
   double diff;
   scanf (" %lld", &cas);
   for (k = 1; k <= cas; k++) {
      scanf (" %lld %lld", &a, &b);
      m = b - a;
      diff = m / 3.0;
      diff = diff * 2;
      if (m % 3 == 1) {
         count = ceil(diff);
         if (a % 3 == 2) count++;
      }
      else if (m % 3 == 0) {
         count = diff + 1;
         if (a % 3 == 1) count--;
      }
      else {
         count = ceil(diff);
      }
      printf ("Case %lld: %lld\n", k, count);
   }
   return 0;
}
