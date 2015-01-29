#include <stdio.h>
int main ()
{
   long int n, m, cas, k;

   scanf (" %ld", &cas);
   for (k = 1; k <= cas; k++) {
      scanf (" %ld %ld", &n, &m);
      n = n / 2;
      n = n * m;
      printf ("Case %ld: %ld\n", k, n);
   }
   return 0;
}
