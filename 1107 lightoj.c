#include <stdio.h>
int main ()
{
   int x1, y1, x2, y2, m, n;
   int cas, k, comd;
   scanf (" %d", &cas);
   for (k = 1; k <= cas; k++) {
      scanf (" %d %d %d %d", &x1, &y1, &x2, &y2);
      scanf (" %d", &comd);
      printf ("Case %d:\n", k);
      while (comd--) {
         scanf (" %d %d", &m, &n);
         if (m < x1 || n < y1 || m > x2 || n > y2) printf ("No\n");
         else printf ("Yes\n");
      }
   }

   return 0;
}
