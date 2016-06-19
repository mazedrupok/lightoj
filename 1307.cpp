/**
   MMM   MMM     A     ZZZZZZZ EEEEEEE DDDDD
   MM MMM MM    AAA    Z   ZZ  EE    E DDDDDDD
   MM  M  MM   AA AA      ZZ   EEEE    DD   DD
   MM     MM  AAAAAAA   ZZ   Z EE    E DDDDDDD
   MM     MM AA     AA ZZZZZZZ EEEEEEE DDDDD

 Name:     Md. Abdul Mazed (RUPOK)
           Noakhali Science & Technology University
 Email:    mazedrupok@gmail.com || mazed4g@gmail.com
 FB id:    www.facebook.com/mazedrupok
 github:   www.github.com/mazedrupok

*/
#include <bits//stdc++.h>
using namespace std;
#define MX 100005
#define read(f)  freopen(f,"r",stdin)
#define write(f) freopen(f,"w",stdout)
#define LL long long
#define ULL unsigned long long
/****************************** END OF TEMPLATE ******************************/

LL ara[2005];
int bin_ser (int lo, int hi, LL val) {
   int mid, ans;
   while (lo <= hi) {
      mid = (lo+hi) /2;
      if (ara[mid] < val) {
         ans = mid;
         lo = mid+1;
      }
      else hi = mid-1;
   }
   return ans;
}
int main ()
{
   int tc, cs = 0, n;
   scanf (" %d", &tc);
   while (tc--) {
      scanf (" %d", &n);
      for (int i = 0; i < n; i++) scanf (" %lld", &ara[i]);
      sort (ara, ara+n);
      int res = 0;
      for (int i = 0; i < n; i++) {
         for (int j = i+1; j < n; j++) {
            res += bin_ser (0, n-1, ara[i]+ara[j]);
            res -= j;
         }
      }
      printf ("Case %d: %d\n", ++cs, res);
   }

   return 0;
}
