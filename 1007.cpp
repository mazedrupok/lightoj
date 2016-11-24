/* lightoj 1007
counting co-prime
CoPrime # = n * (p-1)/p * (q-1)/q * (r-1)/r * ...
*/
#include <bits/stdc++.h>
#define pb push_back
#define ull unsigned long long
#define MX 5000001
using namespace std;
int coPrime[MX];
ull cum[MX]; //cumulated sum
bool mark[MX] = {0};
void solve () {      //0 for prime
    mark[0] = 1; mark[1] = 1;
    int limit = sqrt (MX);
    for (int i = 0; i < MX; i++) coPrime[i] = i;

    for (int i = 2; i < MX; i++) {
        if (mark[i] == 0) {
            coPrime[i] = i-1; //prime
            for (int j = i+i; j < MX; j += i) {
                mark[j] = 1;
                coPrime[j] = coPrime[j] /i * (i-1);
            }
        }
    }
    cum[1] = coPrime[1] = 0;
    for (int i = 2; i < MX; i++) {
        cum[i] = cum[i-1] + ((ull) coPrime[i] * (ull) coPrime[i]);
    }
}

int main ()
{
    solve();
    int tc, cs = 0, n, a, b;
    scanf (" %d", &tc);
    while (tc--) {
        scanf (" %d %d", &a, &b);
        printf ("Case %d: %llu\n", ++cs, cum[b] - cum[a-1]);
    }
    return 0;
}
