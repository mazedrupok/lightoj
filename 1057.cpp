#include <bits/stdc++.h>
using namespace std;
#define ll long long
template <class T> inline T Set(T N,T pos){return N=N | (1<<pos);}
template <class T> inline T reset(T N,T pos){return N=N & ~(1<<pos);}
template <class T> inline bool check(T N,T pos){return (bool)(N & (1<<pos));}

struct point {
    int x; int y;
};
point ara[25];
char s[25][25];
int n, dp[16][1 << 16];
int distan (int i, int j) {
    int a = abs(ara[i].x - ara[j].x);
    int b = abs(ara[i].y - ara[j].y);
    return max (a, b);
}
int fun (int pos, int mask) {
    if (pos >= n) return 0;
    if (mask == (1 << n) -1) {
        return distan(pos, 0);
    }
    int &ret = dp[pos][mask];
    if (ret != -1) return ret;
    int best = 1e9;
    for (int i = 1; i < n; i++) {
        if (i == pos || check(mask, i)) continue;
        best = min (best, distan(i, pos) + fun (i, Set (mask, i)));
    }
    return ret = best;
}
int main ()
{
    //freopen ("in.txt", "r", stdin);
    int tc, cs = 0, r, c;
    scanf (" %d", &tc);
    while (tc--) {
        scanf (" %d %d ", &r, &c);
        n = 1;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                scanf (" %c", &s[i][j]);
                if (s[i][j] == 'x') {
                    ara[0].x = i;
                    ara[0].y = j;
                }
                if (s[i][j] == 'g') {
                    ara[n].x = i;
                    ara[n].y = j;
                    n++;
                }
            }
        }
        memset (dp, -1, sizeof (dp));
        printf ("Case %d: %d\n", ++cs, fun (0, 1));
    }

    return 0;
}
