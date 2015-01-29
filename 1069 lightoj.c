#include <stdio.h>
int main ()
{
   int pos, lift, cas, time, k, temp;

   scanf (" %d", &cas);
   for (k = 1; k <= cas; k++) {
      scanf (" %d %d", &pos, &lift);
      if (lift >= pos)   temp = lift - pos;
      else  temp = pos - lift;
      time = 4 * temp + 4 * pos + 19;

      printf ("Case %d: %d\n", k, time);
   }
   return 0;
}
