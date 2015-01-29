#include <stdio.h>
int main ()
{
   int a, b, c, d, cas, k, i, j, result;
   char dot, str[35], ch;
   scanf (" %d", &cas);
   for (k = 1; k <= cas; k++) {
      scanf (" %d %c %d %c %d %c %d", &a, &dot, &b, &dot, &c, &dot, &d);

      scanf (" %[^\n]s", str);
      result = 1;
      for (i = 0, j = 7; i < 8; i++, j--) {
         if (a % 2 == 1) ch = '1';
         else ch = '0';

         if (ch != str[j]) {
            result = 0;
            break;
         }
         a = a / 2;
      }
      if (result != 0) {
         for (i = 0, j = 16; i < 8; i++, j--) {
            if (b % 2 == 1) ch = '1';
            else ch = '0';

            if (ch != str[j]) {
               result = 0;
               break;
            }
            b = b / 2;
         }
      }
      if (result != 0) {
         for (i = 0, j = 25; i < 8; i++, j--) {
            if (c % 2 == 1) ch = '1';
            else ch = '0';

            if (ch != str[j]) {
               result = 0;
               break;
            }
            c = c / 2;
         }
      }
      if (result != 0) {
         for (i = 0, j = 34; i < 8; i++, j--) {
            if (d % 2 == 1) ch = '1';
            else ch = '0';

            if (ch != str[j]) {
               result = 0;
               break;
            }
            d = d / 2;
         }
      }
      if (result == 1) printf ("Case %d: Yes\n", k);
      else printf ("Case %d: No\n", k);

   }
   return 0;
}
