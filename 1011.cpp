#include <bits//stdc++.h>
using namespace std;
#define MX 100005
#define read(f)  freopen(f,"r",stdin)
#define write(f) freopen(f,"w",stdout)
#define LL long long
#define ULL unsigned long long
#define inf        INT_MAX
#define mod        1000000007
template <class T> inline T Set(T N,T pos){return N=N | (1<<pos);}
template <class T> inline T reset(T N,T pos){return N=N & ~(1<<pos);}
template <class T> inline bool check(T N,T pos){return (bool)(N & (1<<pos));}
const double EPS = 1e-9;
int ara[20][20], n;
int dp[16][66000]; //2^16
int func (int i, int prev) {
    if (i == n) return 0;
    if (dp[i][prev] != -1) return dp[i][prev];
    int mx = 0;
    for (int j = 0; j < n; j++) {
        if (check (prev, j)) continue; //check the bit on
        mx = max (mx, ara[i][j] + func (i+1, Set(prev,j) )); //Set the bit on
    }
    return dp[i][prev] = mx;
}
int main ()
{
  //ios::sync_with_stdio(0); cin.tie(0);
  //read("in.txt"); //write("out.txt");
    int tc, cs = 0;
    scanf (" %d", &tc);
    while (tc--) {
        scanf (" %d", &n);
        memset (dp, -1, sizeof (dp));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf (" %d", &ara[i][j]);
            }
        }
        printf ("Case %d: %d\n", ++cs, func (0, 0));
    }

    return 0;
}
