#include <bits/stdc++.h>
using namespace std;
int main ()
{
   int tc, cs = 0, n, cnt;
   string s;
   cin >> tc;
   while (tc--) {
      cin >> n;
      cin >> s;
      cnt = 0;
      for (int i = 0; i < n; i++) {
         if (s[i] == '.') {
            cnt++;
            i += 2;
         }
      }
      printf ("Case %d: %d\n", ++cs, cnt);
   }
   return 0;
}
