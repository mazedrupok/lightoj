#include <bits/stdc++.h>
using namespace std;
#define LL long long

int seg[270000];
int lazy[270000];
void update (int at, int L, int R, int l, int r, int v) {
    if (L >= l && R <= r) {
        seg[at] = (R-L+1) * v;
        if (L != R) {
            lazy[2*at] = v;
            lazy[2*at+1] = v;
        }
        lazy[at] = -1;
        return;
    }
    if (lazy[at] != -1) {
        seg[at] = (R-L+1) * lazy[at];
        if (L != R) {
            lazy[2*at] = lazy[at];
            lazy[2*at+1] = lazy[at];
        }
        lazy[at] = -1;
    }
    if (L > r || R < l) return;
    int mid = (L+R) >> 1;
    update (2*at, L, mid, l, r, v);
    update (2*at+1, mid+1, R, l, r, v);
    seg[at] = seg[2*at] + seg[2*at+1];
}
int query (int at, int L, int R, int l, int r) {
    if (lazy[at] != -1) {
        seg[at] = (R-L+1) * lazy[at];
        if (L != R) {
            lazy[2*at] = lazy[at];
            lazy[2*at+1] = lazy[at];
        }
        lazy[at] = -1;
    }
    if (L > r || R < l) return 0;
    if (L >= l && R <= r) {
        return seg[at];
    }
    int mid = (L+R) >> 1;
    int a = query (2*at, L, mid, l, r);
    int b = query (2*at+1, mid+1, R, l, r);
    return a+b;
}
int main ()
{
    int tc, cs = 0, n, q, a, b, v, res, g, p, test;
    scanf (" %d", &tc);
    while (tc--) {
        scanf (" %d %d", &n, &q);
        memset (seg, 0, sizeof(seg));
        memset (lazy, -1, sizeof (lazy));
        printf ("Case %d:\n", ++cs);
        while (q--) {
            scanf (" %d", &test);
            if (test == 1) {
                scanf (" %d %d %d", &a, &b, &v);
                a++; b++;
                update (1, 1, n, a, b, v);
            }
            else {
                scanf (" %d %d", &a, &b);
                a++; b++;
                res = query (1, 1, n, a, b);
                p = (b-a+1);
                g = __gcd(res, b-a+1);
                res /= g; p /= g;
                if (p == 1) printf ("%d\n", res);
                else printf ("%d/%d\n", res, p);
            }
        }
    }
    return 0;
}
