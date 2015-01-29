#include <stdio.h>
#include <math.h>
int main ()
{
   int size, cas, k, i, count, temp;

   scanf (" %d", &cas);
   for (k = 1; k <= cas; k++) {
      scanf (" %d", &size);
      int ara[size];
      for (i = 0; i < size; i++)  scanf (" %d", &ara[i]);
      count = 0;
      if (ara[0] > 2) {
         count += ceil((ara[0] - 2) / 5.0);
      }
      for (i = 0; i < size-1; i++) {
         temp = ara[i+1] - ara[i];
         if (temp > 0)  {
            count += ceil(temp / 5.0);
         }
      }
      printf ("Case %d: %d\n", k, count);
   }
   return 0;
}
