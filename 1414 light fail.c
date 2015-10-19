#include <stdio.h>
int main ()
{
   char monthA[10], monthB[10], coma;
   int month1, month2, day1, day2, year1, year2;
   int i, j, cas, count;
   scanf (" %d", &cas);

   for (j = 1; j <= cas; j++) {
         count = 0;
      scanf (" %s %d%c %d", &monthA, &day1, &coma, &year1);
      scanf (" %s %d%c %d", &monthB, &day2, &coma, &year2);
      if (strcmp(monthA, "January") == 0) month1 = 1;
      else if (strcmp(monthA, "February") == 0) month1 = 2;
      else month1 = 4;

      if (strcmp(monthB, "January") == 0) month2 = 1;
      else if (strcmp(monthB, "February") == 0) month2 = 2;
      else month2 = 4;

      if (month1 > 2) year1++;
      if ((month2 == 2 && day2 < 29) || month2 == 1) year2--;
      for (i = year1; i <= year2; i++) {
         if (i % 400 == 0) count++;
         else if (i % 100 == 0) continue;
         else if (i % 4 == 0) count++;

      }
      printf ("Case %d: %d\n", j, count);
   }


   return 0;
}
