#include <stdio.h>
#include <string.h>
int main ()
{
   char comd[10];
   char url[101][101];
   int i, j, cas, k;
   scanf (" %d", &cas);
   for (k = 1; k <= cas; k++) {
      strcpy(url[0] , "http://www.lightoj.com/");
      i = 0;
      j = 0;
      printf ("Case %d:\n", k);
      while (scanf (" %s", comd) == 1) {
         if (strcmp(comd, "VISIT") == 0) {
            i++;
            scanf (" %s", &url[i]);
            printf ("%s\n", url[i]);
            j = i;
         }
         else if (strcmp(comd, "BACK") == 0) {
            i--;
            if (i < 0) {
               printf ("Ignored\n");
               i++;
            }
            else {
               printf ("%s\n", url[i]);
            }
         }
         else if (strcmp(comd, "FORWARD") == 0) {
            i++;
            if (i > j) {
               printf ("Ignored\n");
               i--;
            }
            else {
               printf ("%s\n", url[i]);
            }
         }
         else if (strcmp(comd, "QUIT") == 0) break;
      }
   }
   return 0;
}
