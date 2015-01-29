#include <stdio.h>
int main ()
{
   int cas, n, m, i;
   scanf (" %d", &cas);
   for (i = 1; i <= cas; i++) {
         scanf (" %d", &n);
         m = n / 2;
         printf ("%d %d\n", m, n - m );
      }
   return 0;
}
