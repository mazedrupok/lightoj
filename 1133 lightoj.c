#include <stdio.h>
int main ()
{
   int cas, i, j, p, k, size, comd, n, m, temp;
   char ch;

   scanf (" %d", &cas);
   for (k = 1; k <= cas; k++) {
      scanf (" %d %d", &size, &comd);
      int ara[size];
      for (i = 0; i < size; i++)
         scanf (" %d", &ara[i]);
      for (i = 0; i < comd; i++) {
         scanf (" %c", &ch);
         if (ch == 'S') {
            scanf (" %d", &n);
            for (j = 0; j < size; j++) ara[j] = ara[j] + n;
         }
         else if (ch == 'M') {
            scanf (" %d", &n);
            for (j = 0; j < size; j++)  ara[j] = ara[j] * n;
         }
         else if (ch == 'D') {
            scanf (" %d", &n);
            if (n != 0)
               for (j = 0; j < size; j++) ara[j] = ara[j] / n;
         }
         else if (ch == 'R') {
            for (j = 0, p = size-1; j < size/2; j++, p--) {

               temp = ara[j];
               ara[j] = ara[p];
               ara[p] = temp;
            }
         }
         else if (ch == 'P') {
            scanf (" %d %d", &n, &m);
            temp = ara[n];
            ara[n] = ara[m];
            ara[m] = temp;
         }
      }
      printf ("Case %d:\n", k);
      for (j = 0; j < size-1; j++) {
         printf ("%d ", ara[j]);
      }
      printf ("%d\n", ara[j]);
   }

   return 0;
}
