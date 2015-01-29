#include <stdio.h>
#include <math.h>
#define pi 2*acos(0.0)
int main ()
{
   int cas, i;
   double rad, cA, sA, area;

   scanf (" %d", &cas);

   for (i = 1; i <= cas; i++) {
      scanf (" %lf", &rad);
      cA = pi * rad * rad;
      sA = (2 * rad) * (2 * rad);
      area = sA - cA;
      printf ("Case %d: %.2lf\n", i, area);
   }

   return 0;
}
