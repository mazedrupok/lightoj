#include <bits/stdc++.h>
using namespace std;
#define ll long long
template <class T> inline T Set(T N,T pos){return N=N | (1<<pos);}
template <class T> inline T reset(T N,T pos){return N=N & ~(1<<pos);}
template <class T> inline bool check(T N,T pos){return (bool)(N & (1<<pos));}
int digitValue(char ch) {return ch > 64 ? ch-55 : ch-48;}
int n, base, k;
ll dp[22][66000];
char digit[100];
ll fun (int m, int mask) {
    if (mask == (1 << n) - 1) return (m == 0); //if mask = 1111 = 2^4 -1
    ll &ret = dp[m][mask];
    if (ret != -1) return ret;
    ret = 0;
    for (int i = 0; i < n; i++) {
        if (check (mask, i)) continue;
        int ad = digitValue(digit[i]);
        ret += fun ((m * base + ad) %k, Set(mask, i) );
    }
    return ret;
}
int main ()
{
    int tc, cs = 0;
    ll res;
    scanf (" %d", &tc);
    while (tc--) {
        scanf (" %d %d %s", &base, &k, digit);
        n = strlen (digit);
        memset (dp, -1, sizeof (dp));
        res = fun (0, 0);
        printf ("Case %d: %lld\n", ++cs, res);
    }
}
