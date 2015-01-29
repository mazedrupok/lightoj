#include <stdio.h>
#include <string.h>
int main ()
{
   char str[210];
   long long n, sum;
   int cas, k, len, i;
   scanf (" %d", &cas);
   for (k = 1; k <= cas; k++) {
      scanf (" %s %lld", str, &n);
      if (n < 0) n = n * -1;
      len = strlen (str);
      sum = 0;
      for (i = 0; i < len; i++) {
         if (str[i] == '-') i++;
         sum = sum * 10 + (str[i] - 48);
         if (sum >= n) {
            sum = sum % n;
         }
      }
      if (sum == 0) printf ("Case %d: divisible\n", k);
      else printf ("Case %d: not divisible\n", k);
   }
   return 0;
}
