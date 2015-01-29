#include <stdio.h>
int main ()
{
   int cas, k, n, x1, x2, y1, y2, z1, z2;
   int ara[10], i, j, volume;
   scanf (" %d", &cas);
   for (k = 1; k <= cas; k++) {
      scanf (" %d", &n);
      scanf (" %d %d %d %d %d %d", &x1, &y1, &z1, &x2, &y2, &z2);
      for (i = 1; i < n; i++) {
         for (j = 0; j < 6; j++) scanf (" %d", &ara[j]);
         if (ara[0] >= x2 || ara[3] <= x1 || ara[1] >= y2 || ara[4] <= y1 || ara[2] >= z2 || ara[5] <= z1)
            goto jump;

         if (ara[0] > x1) x1 = ara[0];
         if (ara[3] < x2) x2 = ara[3];
         if (ara[1] > y1) y1 = ara[1];
         if (ara[4] < y2) y2 = ara[4];
         if (ara[2] > z1) z1 = ara[2];
         if (ara[5] < z2) z2 = ara[5];
      }
      x1 = x1 - x2;
      y1 = y1 - y2;
      z1 = z1 - z2;
      volume = x1 * y1 * z1;
      if (volume < 0) volume = volume * -1;
      printf ("Case %d: %d\n", k, volume);
      if (i != n) jump:
         printf ("Case %d: 0\n", k);
   }
   return 0;
}
