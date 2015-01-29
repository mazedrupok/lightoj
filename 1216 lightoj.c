#include <stdio.h>
#include <math.h>
#define pi 2*acos(0.0)
int main ()
{
   double r1, r2, h, p;
   double angle, r3, H, v, v1, v2;
   int cas, k;
   scanf (" %d", &cas);
   for (k = 1; k <= cas; k++) {
      scanf (" %lf %lf %lf %lf", &r1, &r2, &h, &p);
      angle = (r1 - r2) / h;
      r3 = r1 - ((h - p) * angle);
      //r3 = r1 - r3;
      H = r3 / angle;
      v1 = r3 * r3 * H; //volume of cone is = 1/3 (pi * r^2 * H) // volume of cylender is pi * r^2 * H
      v2 = r2 * r2 * (H - p);
      if (v1 < 0) v1 = v1 * -1;
      if (v2 < 0) v2 = v2 * -1;
      v = pi * (v1 - v2);
      v = v / 3;
      if (v < 0) v = v * -1;
      printf ("Case %d: %.9lf\n", k, v);
   }
   return 0;
}
