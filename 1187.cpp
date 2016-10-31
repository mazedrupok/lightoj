//O(N) greedy solution
#include <bits//stdc++.h>
using namespace std;
#define N 100005
#define LL long long
#define ULL unsigned long long
int ara[N];
int seg[270000];
void build (int at, int L, int R) {
    if (L == R) {
        seg[at] = 1;
        return;
    }
    int mid = (L+R) >> 1;
    build (2*at, L, mid);
    build (2*at+1, mid+1, R);
    seg[at] = seg[2*at] + seg[2*at+1];
}
void makeZero (int at, int L, int R, int p) {
    if (L == R) {
        seg[at] = 0;
        return;
    }
    int mid = (L+R) >> 1;
    if (p <= seg[2*at]) {
        makeZero (2*at, L, mid, p);
    }
    else {
        makeZero (2*at+1, mid+1, R, p-seg[2*at]);
    }
    seg[at] = seg[2*at] + seg[2*at+1];
}
int query (int at, int L, int R, int p) {
    if (L == R) {
        return L;
    }
    int mid = (L+R) >> 1;
    if (p <= seg[2*at]) {
        return query (2*at, L, mid, p);
    }
    else {
        return query (2*at+1, mid+1, R, p-seg[2*at]);
    }
}
int main ()
{
    int tc, cs = 0, n;
    scanf (" %d", &tc);
    while (tc--) {
        scanf (" %d", &n);
        for (int i = 1; i <= n; i++) {
            scanf (" %d", &ara[i]);
        }
        int m = n;
        build (1, 1, n);
        for (int i = n; i > 1; i--) {
            makeZero (1, 1, n, m-ara[i]);
            m--;
        }
        printf ("Case %d: %d\n", ++cs, query(1, 1, n, 1));
    }
    return 0;
}

