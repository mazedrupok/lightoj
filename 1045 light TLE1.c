#include <stdio.h>
int main ()
{
   int n, base, cas, k, i, j, m;
   double fact, temp;
   scanf (" %d", &cas);
   for (k = 1; k <= cas; k++) {
      scanf (" %d %d", &n, &base);
      fact = 0;
      for (i = 2; i <= n; i++) {
         fact = fact + log10(i);
      }
      for (i = 1; ; i++) {
         temp = i * log10(base);
         if (temp > fact) break;
      }
      printf ("Case %d: %d\n", i);
   }
   return 0;
}
