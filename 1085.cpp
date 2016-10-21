#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;
int n;
int ara[100010], b[100010], s[100010];
int sum[400009];
void update (int at, int L, int R, int pos, int value) {
    if (L == R) {
        sum[at] = (sum[at] + value) %mod;
        return;
    }
    int mid = (L+R) /2;
    if (pos <= mid) update (2*at, L, mid, pos, value);
    else update (2*at+1, mid+1, R, pos, value);
    sum[at] = (sum[2*at] + sum[2*at+1]) %mod;
}
int query (int at, int L, int R, int l, int r) {
    if (L > r || R < l) return 0;
    if (L >= l && R <= r) return sum[at] %mod;
    int mid = (L+R) /2;
    int x = query (2*at, L, mid, l, r) %mod;
    int y = query (2*at+1, mid+1, R, l, r) %mod;
    return (x+y) %mod;
}
int main ()
{
    //ios::sync_with_stdio(0); cin.tie(0); //read("in.txt");
    int tc, cs = 0, n, mx, t;
    scanf (" %d", &tc);
    while (tc--) {
        scanf (" %d", &n);
        memset (sum, 0, sizeof (sum));
        for (int i = 0; i < n; i++) {
            scanf (" %d", &ara[i]);
            b[i] = ara[i];
        }
        sort (b, b+n);
        int cnt = 2;
        map <int, int> mp;
        for (int i = 0; i < n; i++) {
            if (mp.find(b[i]) == mp.end()) mp[b[i]] = cnt++;
        }
        mx = cnt;
        for (int i = 0; i < n; i++) ara[i] = mp[ara[i]];
        for (int i = 0; i < n; i++) {
            t = query (1, 1, mx, 1, ara[i]-1) %mod;
            s[i] = (1+t) %mod;
            update (1, 1, mx, ara[i], t+1);
        }
        int res = 0;
        for (int i = 0; i < n; i++) res = (res + s[i]) %mod;
        printf ("Case %d: %d\n", ++cs, res %mod);
    }
    return 0;
}

