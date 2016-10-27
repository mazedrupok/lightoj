#include <bits//stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
const int inf = 1e9;
int ara[100005], n;
int seg[400005];
void build_minIndex (int at, int L, int R) {
    if (L == R) {
        seg[at] = L;
        return;
    }
    int mid = (L+R) >> 1;
    build_minIndex (2*at, L, mid);
    build_minIndex (2*at+1, mid+1, R);

    if (ara[seg[2*at]] <= ara[seg[2*at+1]]) seg[at] = seg[2*at];
    else seg[at] = seg[2*at+1];
}
int query_minIndex (int at, int L, int R, int l, int r) {
    if (L > r || R < l) return 0;
    if (L >= l && R <= r) return seg[at];
    int mid = (L+R) >> 1;
    int a = query_minIndex (2*at, L, mid, l, r);
    int b = query_minIndex (2*at+1, mid+1, R, l, r);

    if (ara[a] <= ara[b]) return a;
    else return b;
}
LL findArea (int L, int R) {
    if (L == R) return ara[L];
    if (L > R) return 0;
    int minIndex = query_minIndex (1, 1, n, L, R);
    LL ans = max (findArea(L, minIndex-1), findArea(minIndex+1, R));
    return max (ans, (LL) (R-L+1)*ara[minIndex]);
}
int main ()
{
    int tc, cs = 0;
    scanf (" %d", &tc);
    ara[0] = inf;
    while (tc--) {
        scanf (" %d", &n);
        for (int i = 1; i <= n; i++) scanf (" %d", &ara[i]);
        ara[n+1] = inf;
        build_minIndex (1, 1, n);
        LL res = findArea (1, n);
        printf ("Case %d: %lld\n", ++cs, res);
    }
    return 0;
}
