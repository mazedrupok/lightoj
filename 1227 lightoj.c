#include <stdio.h>
int main ()
{
   int i, cas, k, n, p, q, c1, c2, sum;
   int ara[100];
   scanf (" %d", &cas);
   for (k = 1; k <= cas; k++) {
      scanf (" %d %d %d", &n, &p, &q);
      for (i = 0; i < n; i++)  scanf (" %d", &ara[i]);
      if (n >= p) c1 = p;
      else c1 = n;
      i = 0;
      sum = 0;
      c2 = 0;
      while (i < n) {
         if (ara[i] <= q) {
            sum += ara[i];
            if (sum <= q)  c2++;
            else  break;
         }
         else  break;
         i++;
      }
      if (c1 <= c2) printf ("Case %d: %d\n", k, c1);
      else printf ("Case %d: %d\n", k, c2);
   }
   return 0;
}
