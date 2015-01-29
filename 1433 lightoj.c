#include <stdio.h>
#include <math.h>
#define pi 2*acos(0.0)
int main ()
{
   int c1, c2, a1, a2, b1, b2, k, cas;
   double rad, d, angle, result;
   scanf (" %d", &cas);
   for (k = 1; k <= cas; k++) {
      scanf (" %d %d %d %d %d %d", &c1, &c2, &a1, &a2, &b1, &b2);
      c1 = (c1 - a1) * (c1 - a1);
      c2 = (c2 - a2) * (c2 - a2);
      c1 = c1 + c2;
      rad = sqrt (c1);
      c1 = (b1 - a1) * (b1 - a1);
      c2 = (b2 - a2) * (b2 - a2);
      c1 = c1 + c2;
      d = sqrt (c1);
      d = d / 2.0;
      angle = d / rad;
      angle = 2 * asin(angle);
      //angle = (angle * 180) / pi;
      result = rad * angle;
      //result = pi * rad * angle;
      //result = result / 180;
      printf ("Case %d: %lf\n", k, result);
   }
   return 0;
}
