#include <stdio.h>
#include <math.h>
int main ()
{
   int i, k, cas, n, base, result;
   double sum;
   scanf (" %d", &cas);
   for (k = 1; k <= cas; k++) {
      scanf (" %d %d", &n, &base);
      sum = 0;
      for (i = 2; i <= n; i++) {
         sum = sum + log10f(i);
      }
      /*for (i = 1; ; i++) {
         temp = i * log10(base);
         if (temp > ara[n]) break;
      } this work is done with formula */
      result = sum / log10f(base);
      result = result + 1;
      printf ("Case %d: %d\n", k, result);
   }
   return 0;
}
