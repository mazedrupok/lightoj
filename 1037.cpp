#include <bits/stdc++.h>
using namespace std;
#define LL long long
int Set(int N,int pos){return N=N | (1<<pos);}
int reset(int N,int pos){return N=N & ~(1<<pos);}
bool check(int N,int pos){return (bool)(N & (1<<pos));}

int ara[16], n, dp[(1<<15) +2];
char mat[16][16];
int solve (int mask) {
    if (mask == (1<<n) -1) return 0;
    if (dp[mask] != -1) return dp[mask];
    int ret, mn = 1e9;
    for (int i = 0; i < n; i++) {
        if (check(mask, i) == 0) { //Searching alive target
            ret = ara[i];
            for (int j = 0; j < n; j++) { //Searching died targets & collect their weapons
                if (check (mask, j) == 1 && mat[j][i] != '0') {
                    ret = min (ret, (int)ceil((double) ara[i] /(double)(mat[j][i] -48)));
                //calculate needed shoot to make target health zero. & get minimum
                }
            }
            ret += solve(Set(mask, i)); //summing total shoot for all targets
            mn = min (mn, ret); //getting minimum for mask dp
        }
    } 
    return dp[mask] = mn;
}
int main()
{
    //freopen ("in.txt", "r", stdin);
    int tc, cs = 0;
    cin >> tc;
    while (tc--) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> ara[i];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) cin >> mat[i][j];
        memset (dp, -1, sizeof (dp));
        int res = solve(0);
        printf ("Case %d: %d\n", ++cs, res);
    }


}
