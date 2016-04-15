#include <bits/stdc++.h>
using namespace std;
int main ()
{
   int tc, cs = 0, n;
   scanf (" %d", &tc);
   while (tc--) {
      scanf (" %d", &n);
      int ara[n+1];
      for (int i = 1; i <= n; i++) {
         scanf (" %d", &ara[i]);
      }
      int cnt = 0;
      for (int i = 1; i <= n; i++) {
         if (ara[i] != i) {
            swap (ara[i], ara[ara[i]]);
            cnt++;
            i = 1;
         }
      }
      //for (int i = 1; i <= n; i++) cout << ara[i] << " "; cout << endl;
      printf ("Case %d: %d\n", ++cs, cnt);
   }
   return 0;
}
