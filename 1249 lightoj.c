#include <stdio.h>
#include <string.h>
int main ()
{
   int a, b, c, cas, k, n, v, max, min, i;
   char str[100], thief[100], s[100];
   scanf (" %d", &cas);
   for (k = 1; k <= cas; k++) {
      scanf (" %d %s %d %d %d", &n, thief, &a, &b, &c);
      max = a * b * c;
      min = max;
      strcpy (s, thief);
      for (i = 1; i < n; i++) {
         scanf (" %s %d %d %d", str, &a, &b, &c);
         v = a * b * c;
         if (v > max) {
            strcpy (thief , str);
            max = v;
         }
         else if (v < min) {
            strcpy (s , str);
            min = v;
         }
      }
      if (max == min) printf ("Case %d: no thief\n", k);
      else printf ("Case %d: %s took chocolate from %s\n", k, thief, s);
   }
   return 0;
}
