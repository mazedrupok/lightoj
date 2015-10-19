#include <stdio.h>
int main ()
{
   double v1, v2, v3, a1, a2, d, bd, t1, t2;
   int cas, k;
   scanf (" %d", &cas);
   for (k = 1; k <= cas; k++) {
      scanf (" %lf %lf %lf %lf %lf", &v1, &v2, &v3, &a1, &a2);
      t1 = v1/a1;
      t2 = v2/a2;

      d = (v1*t1 + v2*t2) / 2.0;
      if (t1 >= t2) bd = v3 * t1;
      else bd = v3 * t2;
      printf ("Case %d: %.8lf %.8lf\n", k, d, bd);
   }
   return 0;
}
//s1 =( (u1 + v1) /2) *t1;
//s2 =( (u2 + v2) /2) *t2;
//a1 = v1 / t1 so t1 = v1 / a1;
//s = v3 * t1; if t1 large than t2
//d = s1 + s2;
