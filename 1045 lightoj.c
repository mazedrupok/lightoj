#include <stdio.h>
#include <math.h>
double ara[1000010];
int main ()
{
   int n, base, cas, k, i;
   double sum = 0, result;
   ara[i] = 0;
   for (i = 1; i <= 1000000; i++) {
      sum = sum + log10(i);
      ara[i] = sum;
   } // loop should be out of case loop. all fact should store in a array.
   //array should define globally.
   scanf (" %d", &cas);
   for (k = 1; k <= cas; k++) {
      scanf (" %d %d", &n, &base);
      /*for (i = 1; ; i++) {
         temp = i * log10(base);
         if (temp > ara[n]) break;
      } this work is done with formula */
      result = ara[n] / log10(base);
      i = result + 1;
      printf ("Case %d: %d\n", k, i);
   }
   return 0;
}
