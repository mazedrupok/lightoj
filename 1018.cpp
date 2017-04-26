#include <bits/stdc++.h>
using namespace std;
#define ll long long
const double EPS = 1e-7;
template <class T> inline T Set(T N,T pos){return N=N | (1<<pos);}
template <class T> inline T reset(T N,T pos){return N=N & ~(1<<pos);}
template <class T> inline bool check(T N,T pos){return (bool)(N & (1<<pos));}

int w, n, allTaken;
int dp[1<<16];
int mat[17][17];
struct point {
    int x; int y;
};
point ara[17];
bool coLinear (int i, int j, int k) { //determinant == 0
	return (ara[i].x * (ara[j].y - ara[k].y) - ara[i].y * (ara[j].x - ara[k].x) + ara[j].x * ara[k].y - ara[k].x * ara[j].y) == 0;
}
int fun (int mask) {
    if (mask == (1<<n) -1) return 0; //if all taken
    int &ret = dp[mask];
    if (ret != -1) return ret;
    if (__builtin_popcount(mask) == n-1) return 1; //if rest only 1
    int mn = 100; //inf
    int i;
    for (i = 0; check (mask, i); i++); //i = which not taken yet
    for (int j = 0; j < n; j++) {
        if (i != j && check(mask, j) == 0) mn = min (mn, 1 + fun (mask | mat[i][j]));
    }
    return ret = mn;
}
int main ()
{
    //freopen ("in.txt", "r", stdin);
    int tc, cs = 0, x, k;
    scanf (" %d", &tc);
    while (tc--) {
        scanf (" %d", &n);
        for (int i = 0; i < n; i++) {
            scanf (" %d %d", &ara[i].x, &ara[i].y);
            allTaken = Set (allTaken, i);
        }
        memset (dp, -1, sizeof (dp));
        memset (mat, 0, sizeof (mat));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                for (int k = 0; k < n; k++) //good technique to contain mask value
                if (coLinear(i, j, k) == true) mat[i][j] |= (1 << k); //using i, j maximum is taken

        printf ("Case %d: %d\n", ++cs, fun (0));
    }

    return 0;
}
