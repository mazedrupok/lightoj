#include <stdio.h>
int main ()
{
   freopen ("input.txt", "r", stdin);
   freopen ("output.txt", "w", stdout);
   int ara[5][5] = {1,4,5,16,17,
                     2,3,6,15,18,
                     9,8,7,14,19,
                     10,11,12,13,20,
                     25,24,23,22,21};
   int i, j, k, cas, n;
   scanf (" %d", &cas);
   for (k = 1; k <= cas; k++) {
      scanf (" %d", &n);

      for (i = 0; i < 5; i++) {
         for (j = 0; j < 5; j++) {
            if (n == ara[i][j]) goto level;
         }
      }
      level:
         printf ("Case %d: %d %d\n", k, j+1 , i+1);
   }
   return 0;
}
