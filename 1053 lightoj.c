#include <stdio.h>
int main ()
{
   int a, b, c, cas;
   int m, i;

   scanf (" %d", &cas);
   for (i = 1; i <= cas; i++) {
      scanf (" %d %d %d", &a, &b, &c);
      if (((a*a + b*b) == c*c) || ((b*b + c*c) == a*a) || ((c*c + a*a) == b*b))
         printf ("Case %d: yes\n", i);
      else printf ("Case %d: no\n", i);
   }
   return 0;
}
