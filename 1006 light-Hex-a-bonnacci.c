
#include <stdio.h>
#include <math.h>
int main ()
{
   long long fn[100005], n, result;
   int cas, k, i, j;
   scanf (" %d", &cas);
   for (k = 1; k <= cas; k++) {
      scanf(" %lld %lld %lld %lld %lld %lld %lld", &fn[0],&fn[1],&fn[2],&fn[3],&fn[4],&fn[5],&n);
      for (i = 6; i <= n; i++)
         fn[i] = (fn[i-1] + fn[i-2] + fn[i-3] + fn[i-4] + fn[i-5] + fn[i-6]) %10000007;
      result = fn[n] %10000007;
      printf ("Case %d: %lld\n", k, result);
   }
   return 0;
}
