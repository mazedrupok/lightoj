#include <stdio.h>
int a[25];
int main () {
   int i, cas, k, n, m;
   int r, l, p, x;
   char s[15];
   scanf (" %d", &cas);
   for (k = 1; k <= cas; k++) {
      scanf (" %d %d", &m, &n);
      printf ("Case %d:\n", k);
      p = 0;
      l = 10;
      r = 11;
      for (i = 0; i < n; i++) {
         scanf (" %s", s);
         if (strcmp(s, "pushLeft") == 0) {
            scanf (" %d", &x);
            if (p == m) {
               printf ("The queue is full\n");
               continue;
            }
            p++;
            a[l] = x;
            printf ("Pushed in left: %d\n", a[l]);
            l--;
         }
         else if (strcmp(s, "pushRight") == 0) {
            scanf (" %d", &x);
            if (p == m) {
               printf ("The queue is full\n");
               continue;
            }
            p++;
            a[r] = x;
            printf ("Pushed in right: %d\n", a[r]);
            r++;
         }
         else if (strcmp(s, "popLeft") == 0) {
            if (p == 0) {
               printf ("The queue is empty\n");
               continue;
            }
            p--;
            l++;
            printf ("Popped from left: %d\n", a[l]);
         }
         else if (strcmp(s, "popRight") == 0) {
            if (p == 0) {
               printf ("The queue is empty\n");
               continue;
            }
            p--;
            r--;
            printf ("Popped from right: %d\n", a[r]);
         }
      }
   }
   return 0;
}
