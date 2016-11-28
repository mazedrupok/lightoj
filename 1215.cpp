#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll solve (ll n, ll m, ll L) {
    ll lcmab, y, p;
    lcmab = (n*m) /(ll)__gcd (n,m);
    y = L / lcmab; //let it 3rd number
    while (1) {
        p = __gcd (lcmab, y);
        if (p <= 1) break;
        lcmab /= p;
        y *= p;
    }
    return y;
}
int main ()
{
    int tc, cs = 0;
    ll a, b, L;
    scanf (" %d", &tc);
    while (tc--) {
        scanf (" %lld %lld %lld", &a, &b, &L);
        if (L %a || L %b) printf ("Case %d: impossible\n", ++cs);
        else printf ("Case %d: %lld\n", ++cs, solve(a, b, L));
    }
    return 0;
}
