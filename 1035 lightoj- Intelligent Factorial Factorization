#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <math.h>
using namespace std;
int test_prime (int n)
{
    int i;
    int root;
    root = sqrt(n);
    if (n == 1) return 0; //not prime
    if (n <= 3) return 1; //prime..
    if (n % 2 == 0) return 0; //not prime..
    for (i = 3; i <= root; i += 2) {
        if (n %i == 0) return 0;
    }
    return 1;
}
int main(){
   int tc, k = 0, n, p;
   cin >> tc;
   while (tc--) {
      cin >> n;
      int ara[n];
      for (int i = 2; i <= n; i++) ara[i] = 0;
      for (int i = 2; i <= n; i++) {
         if (test_prime (i) == 1) {
            ara[i] = 1;
            for (int j = i+i; j <= n; j+=i) {
               p = j;
               while (p%i == 0) {ara[i] = ara[i] + 1; p /= i;}
               //printf ("%d %d\n", i, ara[i]);
            }
         }
      }
      printf ("Case %d: %d =", ++k, n);
      int t = 0;
      for (int i = 2; i <= n; i++) {
         if (ara[i] != 0 && t == 0) {printf (" %d (%d)", i, ara[i]); t = 1;}
         else if (ara[i] != 0 && t == 1) printf (" * %d (%d)", i, ara[i]);
      }
      printf ("\n");
   }
}
