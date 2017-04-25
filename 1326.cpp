#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, dp[1001][1001], res[1001];
const int mod = 10056;
vector <int > v[1001];
void generateNCR () { //it can count nCr less than 10000
   v[0].push_back(1); //10000 takes 2 sec..
   v[1].push_back(1);
   v[1].push_back(1);
   for (int i = 2; i <= 1000; i++) {
      for (int j = 0; j <= i; j++) {
         if (i == j || j == 0) v[i].push_back(1);
         else if (j == 1 || j == i-1) v[i].push_back(i);
         else {
            int temp = (v[i-1][j-1] + v[i-1][j]) %mod;
            v[i].push_back(temp);
         }
         v[i][j] %= mod;
      }
   }
}

int main ()
{
    generateNCR ();
    res[0] = 1; res[1] = 1;
    for (int i = 2; i <= 1000; i++) {
        for (int j = i-1; j >= 0; j--) {
            res[i] += v[i][j] * res[j];
            res[i] %= mod;
        }
    }
    int tc, cs = 0;
    scanf (" %d", &tc);
    while (tc--) {
        scanf (" %d", &n);
        printf ("Case %d: %d\n", ++cs, res[n] %mod);
    }

    return 0;
}
