#include <stdio.h>
#include <string.h>
int main ()
{
   char s1[5000], s2[5000], s3[5000];
   int i, j, k, m, n, t;
   int cas, p, count, max;
   scanf (" %d", &cas);
   for (p = 1; p <= cas; p++) {
      scanf (" %[^\n]s", s1);
      scanf (" %[^\n]s", s2);
      scanf (" %[^\n]s", s3);
      max = 0;
      for (i = 0; i < strlen(s1); i++)
         for (j = 0; j < strlen(s2); j++) {
            if (s1[i] != s2[j]) continue;
            for (k = 0; k < strlen(s3); k++) {
               count = 0;
               if (s1[i] == s3[k]) {
                  count++;
                  m = i + 1;
                  n = j + 1;
                  t = k + 1;
                  for (; (s1[m] == s2[n]) && (s1[m] == s3[t]); m++, n++, t++) count++;
                  if (max < count) max = count;
               }
            }
         }
      printf ("Case %d: %d\n", p, max);
   }
   return 0;
}
