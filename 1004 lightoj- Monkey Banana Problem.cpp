#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main ()
{
   int tc, cs = 0, n, k, m, t;
   scanf (" %d", &tc);
   while (tc--) {
      scanf (" %d", &n);
      ll dp[2*n+1][2*n+1], i;
      for (i = 0; i <= 2*n; i++) {
         dp[i][0] = 0;
         dp[0][i] = 0;
      }

      for (i = 1; i <= n; i++) {
         for (int j = 1; j <= i; j++) scanf (" %lld", &dp[i][j]);
      }
      m = n-1;
      for (; i < 2*n; i++, m--) {
         for (int j = 1; j <= m; j++) scanf (" %lld", &dp[i][j]);
      }

      for (i = 1; i <= n; i++) {
         for (int j = 1; j <= i; j++) {
            if (j == i) dp[i][j] += dp[i-1][j-1];
            else dp[i][j] += max (dp[i-1][j-1], dp[i-1][j]);
         }
      }
      m = n-1;
      for (; i < 2*n; i++, m--) {
         for (int j = 1; j <= m; j++) {
            dp[i][j] += max (dp[i-1][j], dp[i-1][j+1]);
         }
      }
      printf ("Case %d: %lld\n", ++cs, dp[2*n-1][1]);
   }
   return 0;
}
