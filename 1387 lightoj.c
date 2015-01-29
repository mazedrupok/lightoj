#include <stdio.h>
int main()
{
   int n, comd, cas, k, i;
   long int amount, sum;
   char str[6];
   scanf (" %d", &cas);
   for (k = 1; k <= cas; k++) {
      scanf (" %d", &comd);
      sum = 0;
      printf ("Case %d:\n", k);
      for (i = 0; i < comd; i++) {
         scanf (" %s", str);
         if (strcmp(str, "donate") == 0) {
            scanf (" %ld", &amount);
            sum += amount;
         }
         else if (strcmp(str, "report") == 0)
            printf ("%ld\n", sum);
      }
   }
   return 0;
}
