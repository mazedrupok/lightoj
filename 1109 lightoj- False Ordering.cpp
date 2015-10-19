//number catagorised with the number of divisors from low to high.. :)
#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;
int ara[1010];
void fn () {
   int i, j, k, n, m;
   vector <int > v[1000];
   v[1].push_back(1);
   for (i = 1000; i > 1; i--) {
      n = 1;
      for (j = 2; j <= sqrt(i); j++) {
         if (i %j == 0) {
            if (i /j == j) n++;
            else n += 2;
         }
      }
      v[n].push_back (i);
   }
   /*for (i = 2; i <= 11; i++) {
      sort (v[i].begin(), v[i].end());
   }*/
   m = 1;
   for (i = 1; i <= 31; i++) {
      for (j = 0; j < v[i].size(); j++) {
         ara[m++] = v[i][j];
         //printf ("%d: %d\t", m-1, ara[m-1]);
      }
   }

}
int main ()
{
   int cas, k, i, j, n;
   fn();
   scanf (" %d", &cas);
   for (k = 1; k <= cas; k++) {
      scanf (" %d", &n);
      printf ("Case %d: %d\n", k, ara[n]);
   }
   return 0;
}
