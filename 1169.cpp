#include <bits//stdc++.h>
using namespace std;
const int N = 1005;
const int inf = 1e9;
#define ll long long
int l[N], r[N], lr[N], rl[N], dp[N][2], n;
int fun (int floor, bool dir) {
    if (floor > n) return 0;
    int &ret = dp[floor][dir];
    if (ret != -1) return ret;
    int a, b;
    if (dir == 0) { //left
        a = fun (floor+1, dir);
        b = lr[floor] + fun (floor+1, !dir);
        return ret = l[floor] + min (a, b);
    }
    //else right
    a = fun (floor+1, dir);
    b = rl[floor] + fun (floor+1, !dir);
    return r[floor] + min (a, b);
}
int main ()
{
    int tc, cs = 0;
    scanf (" %d", &tc);
    while (tc--) {
        scanf (" %d", &n);
        l[0] = r[0] = lr[0] = rl[0] = 0;
        memset (dp, -1, sizeof (dp));
        for (int i = 1; i <= n; i++) scanf (" %d", &l[i]);
        for (int i = 1; i <= n; i++) scanf (" %d", &r[i]);
        for (int i = 1; i < n; i++) scanf (" %d", &lr[i]);
        for (int i = 1; i < n; i++) scanf (" %d", &rl[i]);
        printf ("Case %d: %lld\n", ++cs, fun (0, 0));
    }
    return 0;
}
