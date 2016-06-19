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
LL ara[18];
vector <LL> L, R;
int n, k;
void func (int suru, int sesh, LL sum, vector<LL> &vc) {
   if (sum > k) return;
   if (suru == sesh) {
      vc.push_back (sum);
      return;
   }
   for (int i = 0; i < 3; i++) {
      func (suru+1, sesh, sum + ara[suru]*i, vc);
   }
}
int main ()
{
   int tc, cs = 0;
   scanf (" %d", &tc);
   while (tc--) {
      scanf (" %d %d", &n, &k);
      for (int i = 0; i < n; i++) scanf (" %lld", &ara[i]);
      func (0, n/2, 0, L);
      func (n/2, n, 0, R);
      sort (L.begin(), L.end());
      //for (int i = 0; i < L.size(); i++) cout << L[i] << " "; cout << endl;
     // for (int i = 0; i < R.size(); i++) cout << R[i] << " "; cout << endl;
      bool flag = 0;
      for (int i = 0; i < R.size(); i++) {
         if (binary_search(L.begin(), L.end(), k-R[i]) == 1) {
            flag = 1; break;
         }
      }
      printf ("Case %d: ", ++cs);
      if (flag) printf ("Yes\n");
      else printf ("No\n");
      L.clear(); R.clear();
   }

   return 0;
}
