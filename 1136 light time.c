#include <stdio.h>
int main ()
{
   long long m, n, sum, temp, count, i;
   int cas, k;

   scanf (" %d", &cas);
   for (k = 1; k <= cas; k++) {
      scanf (" %lld %lld", &m, &n);
      if (m > 0 && n > 0) {
         if (m > n) {
            temp = m;
            m = n;
            n = temp;
         }
         count = 0;
         for (i = n; i >= m; i--) {
            sum = i*(i+1) / 2;
            if (sum % 3 == 0) count++;

         }
         printf ("Case %d: %ld\n", k, count);
      }
   }
   return 0;
}
