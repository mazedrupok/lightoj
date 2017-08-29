#include <bits/stdc++.h>
#define ll long long
#define LL long long
using namespace std;
int ara[501][501];
int seg[501][1025];
int seg2[1025][1025];
int a, b, p, n;
void build (int at, int L, int R, int i) {
    if (L == R) {
        seg[i][at] = ara[i][L];
        return;
    }
    int mid = (L+R) >> 1;
    build (at << 1, L, mid, i);
    build (at << 1 | 1, mid+1, R, i);
    seg[i][at] = max (seg[i][at << 1], seg[i][at << 1 | 1]);
}
void build2 (int at, int L, int R) {
    if (L == R) {
        for (int i = 1; i < 1025; i++)
            seg2[at][i] = seg[L][i];
        return;
    }
    int mid = (L+R) >> 1;
    build2 (at << 1, L, mid);
    build2 (at << 1 | 1, mid+1, R);
    for (int i = 1; i < 1025; i++)
        seg2[at][i] = max (seg2[at << 1][i], seg2[at << 1 | 1][i]);
}
int query (int at, int L, int R, int l, int r, int i) {
    if (L > r || R < l) return 0;
    if (L >= l && R <= r) return seg2[i][at];
    int mid = (L+R) >> 1;
    int x = query (at << 1, L, mid, l, r, i);
    int y = query (at << 1 | 1, mid+1, R, l, r, i);
    return max (x, y);
}
int query2 (int at, int L, int R, int l, int r) {
    if (L > r || R < l) return 0;
    if (L >= l && R <= r) return query (1, 1, n, b, b+p-1, at); //seg2[at][0];
    int mid = (L+R) >> 1;
    int x = query2 (at << 1, L, mid, l, r);
    int y = query2 (at << 1 | 1, mid+1, R, l, r);
    return max (x, y);
}
int main ()
{
    //freopen ("in.txt", "r", stdin);
    int tc, cs = 0, q;
    scanf (" %d", &tc);
    while (tc--) {
        scanf (" %d %d", &n, &q);
        memset (seg, 0, sizeof (seg));
        memset (seg2, 0, sizeof (seg2));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                scanf (" %d", &ara[i][j]);
            }
            build (1, 1, n, i);
        }
        build2 (1, 1, n);
        printf ("Case %d:\n", ++cs);
        while (q--) {
            scanf (" %d %d %d", &a, &b, &p);
            printf ("%d\n", query2 (1, 1, n, a, a+p-1));
        }
    }
    return 0;
}
