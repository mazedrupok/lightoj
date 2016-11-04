#include <bits//stdc++.h>
using namespace std;
#define MX 100005
#define read(f)  freopen(f,"r",stdin)
#define write(f) freopen(f,"w",stdout)
#define LL long long
#define ULL unsigned long long
#define inf        INT_MAX
#define mod        1000000007
const double EPS = 1e-9;
struct node {
    int zero, one, two;
};
node seg[263000];
int lazy[263000];
void build (int at, int L, int R) {
    if (L == R) {
        seg[at].zero = 1;
        seg[at].one = 0;
        seg[at].two = 0;
        return;
    }
    int mid = (L+R) >> 1;
    build (2*at, L, mid);
    build (2*at+1, mid+1, R);

    seg[at].zero = seg[2*at].zero + seg[2*at+1].zero;
    seg[at].one = seg[2*at].one + seg[2*at+1].one;
    seg[at].two = seg[2*at].two + seg[2*at+1].two;
}
void increment (int at, int L, int R, int l, int r) {
    if (lazy[at] != 0) {
        if (L != R) { //not child
            lazy[2*at] += lazy[at]; lazy[2*at] %= 3;
            lazy[2*at+1] += lazy[at]; lazy[2*at+1] %= 3;
        }
        if (lazy[at] == 1) {
            int temp = seg[at].two; //swapping
            seg[at].two = seg[at].one;
            seg[at].one = seg[at].zero;
            seg[at].zero = temp;
        }
        else if (lazy[at] == 2) { //swapping
            int temp = seg[at].two;
            seg[at].two = seg[at].zero;
            seg[at].zero = seg[at].one;
            seg[at].one = temp;
        }
        lazy[at] = 0;
    }
    if (L > r || R < l) return;
    if (L >= l && R <= r) {
        int temp = seg[at].two; //swapping
        seg[at].two = seg[at].one;
        seg[at].one = seg[at].zero;
        seg[at].zero = temp;
        if (L != R) {
            lazy[2*at]++; lazy[2*at] %= 3;
            lazy[2*at+1]++; lazy[2*at+1] %= 3;
        }
        return;
    }
    int mid = (L+R) >> 1;
    increment (2*at, L, mid, l, r);
    increment (2*at+1, mid+1, R, l, r);
    seg[at].zero = seg[2*at].zero + seg[2*at+1].zero;
    seg[at].one = seg[2*at].one + seg[2*at+1].one;
    seg[at].two = seg[2*at].two + seg[2*at+1].two;
}
int query (int at, int L, int R, int l, int r) {
    if (lazy[at] != 0) {
        if (L != R) { //not child
            lazy[2*at] += lazy[at]; lazy[2*at] %= 3;
            lazy[2*at+1] += lazy[at]; lazy[2*at+1] %= 3;
        }
        if (lazy[at] == 1) {
            int temp = seg[at].two; //swapping
            seg[at].two = seg[at].one;
            seg[at].one = seg[at].zero;
            seg[at].zero = temp;
        }
        else if (lazy[at] == 2) { //swapping
            int temp = seg[at].two;
            seg[at].two = seg[at].zero;
            seg[at].zero = seg[at].one;
            seg[at].one = temp;
        }
        lazy[at] = 0;
    }
    if (L > r || R < l) return 0;
    if (L >= l && R <= r) return seg[at].zero;
    int mid = (L+R) >> 1;
    int a = query (2*at, L, mid, l, r);
    int b = query (2*at+1, mid+1, R, l, r);
    seg[at].zero = seg[2*at].zero + seg[2*at+1].zero;
    seg[at].one = seg[2*at].one + seg[2*at+1].one;
    seg[at].two = seg[2*at].two + seg[2*at+1].two;
    return a+b;
}
int main ()
{
  //ios::sync_with_stdio(0); cin.tie(0);
  //read("in.txt"); //write("out.txt");
    int tc, cs = 0, n, q, test, a, b;
    scanf (" %d", &tc);
    while (tc--) {
        scanf (" %d %d", &n, &q);
        build (1, 1, n);
        memset (lazy, 0, sizeof (lazy));
        printf ("Case %d:\n", ++cs);
        while (q--) {
            scanf (" %d %d %d", &test, &a, &b);
            a++; b++;
            if (test == 0) {
                increment (1, 1, n, a, b);
            }
            else {
                printf ("%d\n", query (1, 1, n, a, b));
            }
        }
    }
    return 0;
}
