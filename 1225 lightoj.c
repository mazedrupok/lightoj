#include <stdio.h>
#include <string.h>
int main ()
{
   char str[10], s[10];
   int cas, k, len, i;

   scanf (" %d", &cas);

   for (k = 1; k <= cas; k++) {

      scanf (" %[^\n]s", str);
      len = strlen(str);
      len--;
      for (i = 0; str[i]; i++, len--) {
         s[i] = str[len];
      }
      s[i] = '\0';
      if (strcmp(str, s) == 0) printf ("Case %d: Yes\n", k);
      else printf ("Case %d: No\n", k);

   }
   return 0;
}
