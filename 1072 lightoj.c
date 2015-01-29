#include <stdio.h>
#include <math.h>
#define pi 2*acos(0.0)
int main ()
{
   double R, r, n, angle, temp;
   int cas, k;
   scanf (" %d", &cas);
   for (k = 1; k <= cas; k++) {
      scanf (" %lf %lf", &R, &n);
      angle = sin(pi/n);
      temp = 1 + angle;
      r = (R * angle) / temp;
      printf ("Case %d: %lf\n", k, r);
   }

   return 0;
}
