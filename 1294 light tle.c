#include <stdio.h>
int main ()
{
   long int  m, cas, k, p, i, j;
   long int n, sum;

   scanf (" %ld", &cas);
   for (k = 1; k <= cas; k++) {
      scanf (" %ld %ld", &n, &m);
      sum = 0;
      p = 1;
      for (i = 1; i <= n/m; i++) {
         if (i % 2 == 0)
            for (j = 1; j <= m; j++) {
               sum = sum + p;
               p++;
            }
         else
            for (j = 1; j <= m; j++) {
               sum =  sum + (p * (-1));
               p++;
            }
      }
      printf ("Case %ld: %ld\n", k, sum);
   }
   return 0;
}
