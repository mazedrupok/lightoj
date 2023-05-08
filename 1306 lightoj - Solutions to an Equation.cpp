// https://lightoj.com/problem/solutions-to-an-equation

#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Extended euclidean algorithm
ll gcdExtended(ll a, ll b, ll *x, ll *y) {
    if (a == 0) {
        *x = 0;
        *y = 1;
        return b;
    }
    ll x1, y1;
    ll gcd = gcdExtended(b%a, a, &x1, &y1);
    
    *x = y1 - (b/a) * x1;
    *y = x1;
    
    return gcd;
}

// Calculate numberOfSolutions of ax+by+c = 0
ll numberOfSolutions(ll a, ll b, ll c, ll x1, ll x2, ll y1, ll y2) {
    if (a == 0 && b == 0) {
        if (c == 0) { // any solution can be possible
            return (x2 - x1 + 1) * (ll) (y2 - y1 + 1LL);
        }
        else { return 0; } // solution not possible
    }
    if (a == 0) { // ax = 0. So, y = -c/b, b can't be 0
        if (c %b != 0) { return 0; } // no integer solution for y.
        ll y = -c/b;
        
        if (y >= y1 && y <= y2) return x2 - x1 + 1LL;
        else { return 0; } // no solution in [y1, y2]
    }
    if (b == 0) {
        if (c %a != 0) { return 0; }
        ll x = -c/a;
        
        if (x >= x1 && x <= x2) return y2 - y1 + 1LL;
        else { return 0; }
    }
    ll x = 0, y = 0;
    ll d = gcdExtended(a, b, &x, &y); // x, y is solution of ax+by = d = gcd(a,b)

    // c%d > 0, otherwise solution not exist as equation (3) & (4) not possible
    if (c %d != 0) { return 0; }

    // Soluton of Ax+By+C=0
    x = x * (-c/d);
    y = y * (-c/d);

    a = a / d;
    b = b / d;

    // x1 = x + k * b / gcd(a,b), so k = ?
    double kx1 = (x1 - x) / (double) b;
    double kx2 = (x2 - x) / (double) b;
    if (kx1 > kx2) swap(kx1, kx2);

    // y1 = y - k * a / gcd(a,b), so k = ?
    double ky1 = (y - y1) / (double) a;
    double ky2 = (y - y2) / (double) a;
    if (ky1 > ky2) swap(ky1, ky2);

    ll kMin = (ll) ceil(max(kx1, ky1));
    ll kMax = (ll) floor(min(kx2, ky2));
    return max(0LL, kMax - kMin + 1LL);
}

int main () {
    int tc;
    cin >> tc;
    
    for (int cs = 1; cs <= tc; cs++) {
        ll a, b, c, x1, x2, y1, y2, result;
        cin >> a >> b >> c >> x1 >> x2 >> y1 >> y2;
        result = numberOfSolutions(a, b, c, x1, x2, y1, y2);
        printf("Case %d: %lld\n", cs, result);
    }
}

/*
Explanation,
  ax + by + c = 0
> ax + by = -c ---(1)

Solution of x', y' of below equation can be found 
using extended euclid algorithm.
  a x'          + b y'          = d; where d is gcd(a, b)
> a x' * (-c/d) + b y' * (-c/d) = d * (-c/d)
> a x' * (-c/d) + b y' * (-c/d) = -c ---(2)

Comparing coefficient of a, b in equations 1 and 2,
We got solution of equation (1),
x = x' * (-c/d) ---(3)
y = y' * (-c/d) ---(4)

There can be infinite solutions of equation (1)
Other solutions of equation (1) is,
x1 = x + k * (b / gcd(a, b))
y1 = y - k * (a / gcd(a, b))
Where, k belongs to Z.
*/
