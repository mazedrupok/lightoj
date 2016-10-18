#include <bits/stdc++.h>
using namespace std;
#define LL long long
int ara[1001];
bool check (int n, int k, int x) {
    int temp = 0;
    for (int i = 0; i <= n; i++) {
        if (temp + ara[i] > x) {
            temp = 0; k--;
        }
        temp += ara[i];
    }
    if (k > -1) return 1;
    else return 0;
}
int main ()
{
    //freopen ("in.txt", "r", stdin);
    int tc, cs = 0, n, k, x, mx, sum;
    scanf (" %d", &tc);
    while (tc--) {
        scanf (" %d %d", &n, &k);
        mx = 0;
        sum = 0;
        for (int i = 0; i <= n; i++) {
            scanf (" %d", &ara[i]);
            if (mx < ara[i]) mx = ara[i];
            sum += ara[i];
        }
        int lo = mx, hi = sum, mid;

        while (lo < hi) {
            mid = (lo+hi) >> 1;
            if (check (n, k, mid) == 1) hi = mid;
            else lo = mid+1;
        }

        printf ("Case %d: %d\n", ++cs, hi);
        int temp = 0;
        for (int i = 0, j = 0; i <= n; i++) {
            if (temp + ara[i] > hi || k-j > n-i) {
                if (temp == 0) continue;
                printf ("%d\n", temp);
                j++;
                temp = 0;
            }
            temp += ara[i];
        }
        if (temp > 0) printf ("%d\n", temp);
    }
    return 0;
}
