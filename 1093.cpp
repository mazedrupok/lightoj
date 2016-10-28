#include <bits//stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
const int inf = 2e9;
int ara[100005], n;
int mx[400005];
int mn[400005];
void build (int at, int L, int R) {
    if (L == R) {
        mx[at] = ara[L];
        mn[at] = ara[L];
        return;
    }
    int mid = (L+R) >> 1;
    build (2*at, L, mid);
    build (2*at+1, mid+1, R);
    mx[at] = max (mx[2*at], mx[2*at+1]);
    mn[at] = min (mn[2*at], mn[2*at+1]);
}
int queryMax (int at, int L, int R, int l, int r) {
    if (L >= l && R <= r) return mx[at];
    if (L > r || R < l) return 0;
    int mid = (L+R) >> 1;
    int a = queryMax (2*at, L, mid, l, r);
    int b = queryMax (2*at+1, mid+1, R, l, r);
    return max (a, b);
}
int queryMin (int at, int L, int R, int l, int r) {
    if (L >= l && R <= r) return mn[at];
    if (L > r || R < l) return inf;
    int mid = (L+R) >> 1;
    int a = queryMin (2*at, L, mid, l, r);
    int b = queryMin (2*at+1, mid+1, R, l, r);
    return min (a, b);
}
int main ()
{
    int tc, cs = 0, res, d;
    scanf (" %d", &tc);
    ara[0] = inf;
    while (tc--) {
        scanf (" %d %d", &n, &d);
        for (int i = 1; i <= n; i++) scanf (" %d", &ara[i]);
        ara[n+1] = inf;
        build (1, 1, n);
        res = 0;
        for (int i = 1; i+d-1 <= n; i++) {
            int a = queryMin (1, 1, n, i, i+d-1);
            int b = queryMax (1, 1, n, i, i+d-1);
            res = max (res, b-a);
        }
        printf ("Case %d: %d\n", ++cs, res);
    }
    return 0;
}
