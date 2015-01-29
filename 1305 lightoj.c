#include <stdio.h>
int main ()
{
   int cas, k;
   int a1, a2, b1, b2, c1, c2, d1, d2, area;
   scanf (" %d", &cas);
   for (k = 1; k <= cas; k++) {
      scanf (" %d %d %d %d %d %d", &a1, &a2, &b1, &b2, &c1, &c2);
      d1 = a1 + c1 - b1;
      d2 = a2 + c2 - b2;
      area = (a1 * b2) - (b1 * a2) + (b1 * c2) - (c1 * b2) + (c1 * d2) - (d1 * c2) + (d1 * a2) - (a1 * d2);
      area = area / 2;
      if (area < 0) area = area * -1;
      printf ("Case %d: %d %d %d\n", k, d1, d2, area);
    }
   return 0;
}
