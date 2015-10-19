#include <stdio.h>
#include <string.h>
int main ()
{
   char str[100], rev[100];
   int i, j, k, cas;

   scanf (" %d", &cas);
   for (k = 1; k <= cas; k++) {
      scanf (" %[^\n]s", str);
      scanf (" %[^\n]s", rev);

      for (i = 0; str[i]; i++)
         if (str[i] < 'Z' && str[i] != ' ')
            str[i] = str[i] + 32;
      for (i = 0; rev[i]; i++)
         if (rev[i] < 'Z' && rev[i] != ' ')
            rev[i] = rev[i] + 32;

      for (i = 0; rev[i]; i++)  {
         if (rev[i] == ' ')
            continue;
         for (j = 0; str[j]; j++)
            if (rev[i] == str[j])
               break;

         if (!str[j])
            break;
      }
      if (!rev[i])
         printf ("Case %d: Yes\n", k);
      else
         printf ("Case %d: No\n", k);
   }

   return 0;
}
