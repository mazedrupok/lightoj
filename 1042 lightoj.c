#include <stdio.h>
#include <string.h>
int main ()
{
   char str[64];
   long long n, i, j, result;
   int cas, k, count, con, a;
   scanf (" %d", &cas);
   for (k = 1; k <= cas; k++) {
      scanf (" %lld", &n);
      count = 0;
      con = 0;
      result = 0;
      for (j = 0; n > 0; j++) {
         if (n % 2 == 1) {
            count++;
            str[j] = '1';
         }
         else str[j] = '0';
         n = n / 2;
      }
      str[j] = '\0';
      i = 0;
      while (1) {
         if (str[i] == '1') {
            str[i] = '0';
            i++;
            while (str[i] == '1') {
               str[i] = '0';
               i++;
            }
            str[i] = '1';
            break;
         }
         i++;
      }
      if (i == j) str[j+1] = '\0';
      else str[j] = '\0';
      for (i = 0; str[i]; i++) {
         if (str[i] == '1') con++;
      }
      count = count - con;
      if (count != 0)
         for (i = 0; i < count; i++) str[i] = '1';
      for (i = 0; str[i]; i++) {
         a = str[i] - 48;
         result = result + a * pow (2, i);
      }
      printf ("Case %d: %lld\n", k, result);
   }
   return 0;
}
