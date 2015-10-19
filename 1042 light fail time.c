#include <stdio.h>
int main ()
{
   long long n, m, i, j, count, con, p;
   int cas, k;

   scanf (" %d", &cas);

   for (k = 1; k <= cas; k++) {
      scanf (" %lld", &m);
      count = 0;
      n = m;
      for (i = 0; n > 0; i++) {
         if (n % 2 == 1) count++;
         n = n / 2;
      }
      if (count == 1) {
         i = m * 2;
         printf ("Case %d: %lld\n", k, i);
         continue;
      }
      for (i = m+1; ; i++ ) {
         n = i;
         con = 0;
         for (j = 0; n > 0; j++) {
            if (n % 2 == 1) con++;
            n = n / 2;
         }
         if (count == con) break;
      }
      printf ("Case %d: %lld\n", k, i);
   }
   return 0;
}
