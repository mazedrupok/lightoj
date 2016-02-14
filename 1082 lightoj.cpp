//https://www.youtube.com/watch?v=ZBHKZF5w4YU
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int mnm[400000];
int num[100050];
void build (int at, int L, int R) { //build array in O(log2n) ..
    if (L == R) {
        mnm[at] = num[L];
        return;
    }
    int mid = (L+R) /2;
    build (2*at, L, mid);
    build (2*at+1, mid+1, R);
    mnm[at] = min(mnm[2*at], mnm[2*at+1]);
}
//void update (int at, int L, int R, int pos, int value) { //update by O(logn)..
//    if (at == pos) {
//        mnm[at] = min (mnm[at], value);
//        return;
//    }
//    int mid = (L+R) /2;
//    if (pos <= at) update (2*at, L, mid, pos, value);
//    else update (2*at+1, mid+1, R, pos, value);
//    mnm[at] = min(mnm[2*at], mnm[2*at+1]);
//}
int query (int at, int L, int R, int l, int r) { ////search in range [1,5].. in O(logn)
    if (L > r || R < l) return 1e9;
    if (L >= l && R <= r) return mnm[at];
    int mid = (L+R) /2;
    int x = query (2*at, L, mid, l, r);
    int y = query (2*at+1, mid+1, R, l, r);
    return min(x, y);
}
int main ()
{
    int n, q, L, R, tc, k = 0;
    //freopen ("in.txt", "r", stdin);
    scanf (" %d", &tc);
    while (tc--) {
        scanf (" %d %d", &n, &q);
        for (int i = 1; i <= n; i++) scanf (" %d", &num[i]);
        build (1, 1, n);        //building mnm array.. take memory 2n or 2(n+1)+1
        printf ("Case %d:\n", ++k);
        while (q--) {
            scanf (" %d %d", &L, &R);
            printf ("%d\n", query (1, 1, n, L, R));
        }
    }
    return 0;
}
