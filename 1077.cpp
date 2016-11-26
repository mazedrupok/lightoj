/**   Lightoj 1090
    Simple line equation for two numbers:
             abs(y1-y2)=c
        Y = -------------- X +- something(R)
             abs(x1-x2)=d
    To be integer value of X must be  multiple of d.
    We can find d by, p = d/GCD(c,d).
    Then result should be range of X divided by p, abs(x1-x2)/p.
    Simply result is, abs(x1-x2)/abs(x1-x2)/GCD(c,d) = GCD(c,d).
    Example, (12,2) & (6,6)
        y = ((4/6)=(2/3)) x + 10
    So result is, range of x, 6/3 = 2. here multiple of zero should be counted.
    So result is, 2+1 = 3.
*/
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define MX 5000001
using namespace std;

int main ()
{
    int tc, cs = 0;
    ll x1, x2, y1, y2;
    scanf (" %d", &tc);
    while (tc--) {
        scanf (" %lld %lld %lld %lld", &x1, &y1, &x2, &y2);
        printf ("Case %d: %lld\n", ++cs, __gcd(abs(x1-x2), abs(y1-y2)) + 1LL);
    }
    return 0;
}
