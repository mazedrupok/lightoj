#include <stdio.h>
int main ()
{
   long int n;
   int cas, k;
   int count;
   scanf (" %d", &cas);
   for (k = 1; k <= cas; k++) {
      scanf (" %d", &n);
      count = 0;
      while (n != 0) {
         if (n % 2 == 1) count++;
         n = n / 2;
      }
      if (count % 2 == 0) printf ("Case %d: even\n", k);
      else  printf ("Case %d: odd\n", k);
   }
   return 0;
}
