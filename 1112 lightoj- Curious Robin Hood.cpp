/*
    Md. Abdul Mazed
    Noakhali Science & Technology University
    mazed4g@gmail.com
    http://www.facebook.com/mazedrupok/bd
    github.com/mazedrupok
    problem category: Segment Tree
        :) :) :) 
*/
#include <bits/stdc++.h>
using namespace std;
int sum[400050];
int num[100050];
void build (int at, int L, int R) {
    if (L == R) {
        sum[at] = num[L];
        return;
    }
    int mid = (L+R) /2;
    build (2*at, L, mid);
    build (2*at+1, mid+1, R);
    sum[at] = sum[2*at] + sum[2*at+1];
}
void update (int at, int L, int R, int pos, int value) {
    if (L > pos || R < pos) return;
    if (L == R && L == pos) {
        sum[at] += value;
        return;
    }
    int mid = (L+R) /2;
    if (mid >= pos) update (2*at, L, mid, pos, value);
    else update (2*at+1, mid+1, R, pos, value);
    sum[at] = sum[2*at] + sum[2*at+1];
}
int query (int at, int L, int R, int l, int r) {
    if (L > r || R < l) return 0;
    if (L >= l && R <= r) return sum[at];
    int mid = (L+R) /2;
    int x = query (2*at, L, mid, l, r);
    int y = query (2*at+1, mid+1, R, l, r);
    return x+y;
}
int main ()
{
    //freopen ("in.txt", "r", stdin);
    int tc, k = 0, n, q, a, b, c;
    scanf (" %d", &tc);
    while (tc--) {
        scanf (" %d %d", &n, &q);
        for (int i = 0; i < n; i++) scanf (" %d", &num[i]);
        for (int i = 0; i < n*4; i++) sum[i] = 0;
        build (1, 0, n-1);
        //for (int i = 0; i < n*3; i++) cout << sum[i] << " "; cout << endl;
        printf ("Case %d:\n", ++k);
        while (q--) {
            scanf (" %d", &a);
            if (a == 1) {
                scanf (" %d", &b);
                printf ("%d\n", num[b]);
                update (1, 0, n-1, b, -num[b]);
                num[b] = 0;
            }
            else if (a == 2) {
                scanf (" %d %d", &b, &c);
                update(1, 0, n-1, b, c);
                num[b] += c;
            }
            else if (a == 3) {
                scanf (" %d %d", &b, &c);
                int x = query (1, 0, n-1, b, c);
                printf ("%d\n", x);
            }
            //for (int i = 0; i < n*3; i++) cout << sum[i] << " "; cout << endl;
        }
    }
    return 0;
}
