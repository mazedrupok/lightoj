//helpful link: https://en.wikipedia.org/wiki/Rook_polynomial
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull solve (int n, int k) {
   if (k > n) return 0;
   ull ans = 1;

   int p = max (n-k, k);
   for (int i = p+1; i <= n; i++) ans *= i; // (n,k)
   p = min (n-k, k);
   for (int i = 2; i <= p; i++) ans /= i;

   ans = (ans * ans);                       // (n,k) * (n,k)
   for (int i = 2; i <= k; i++) ans *= i;   // (n,k) * (n,k) * k!
   return ans;
}
int main ()
{
   int tc, cs = 0, n, k;
   ull res;
   scanf (" %d", &tc);
   while (tc--) {
      scanf (" %d %d", &n, &k);
      res = solve (n, k);
      printf ("Case %d: %llu\n", ++cs, res);
   }
   return 0;
}
