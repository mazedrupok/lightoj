#include <stdio.h>
int main ()
{
   int cas, size, i, k, sum;

   scanf (" %d", &cas);

   for (i = 1; i <= cas; i++) {

      scanf (" %d", &size);
      int ara[size];
      sum = 0;
      for (k = 0; k < size; k++) {
         scanf (" %d", &ara[k]);
         if (ara[k] < 0) ara[k] = 0;
         sum += ara[k];
      }
      printf ("Case %d: %d\n", i, sum);
   }

   return 0;
}
