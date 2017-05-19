#include <bits//stdc++.h>
using namespace std;
#define ll long long
vector <int> vc; //to store digits
int sz; //vc.size()
ll dp[12][12][2][2];
ll fun (int pos, int zeros, bool start, bool small) {
    if (pos == sz) return zeros;
    ll &ret = dp[pos][zeros][start][small];
    if (ret != -1LL) return ret;
    ll cnt = 0LL;
    if (start == 1) {      //1st digit can't be zero
        cnt = fun (pos+1, zeros+1, 1, small | 0 < vc[pos]);
    }
    int r = small ? 9 : vc[pos]; //previous digit is less or not
    for (int i = 1; i <= r; i++) {
        cnt += fun (pos+1, zeros, 1, small | i < vc[pos]);
    }
    if (!start) cnt += fun (pos+1, 0, 0, 1); //suppose start from here
    return ret = cnt;
}
ll fun1 (ll x) {
    if (x < 0) return 0;
    if (x <= 9) return 1;
    vc.clear();
    memset (dp, -1, sizeof (dp));
    while (x) {
        vc.push_back (x %10);
        x /= 10;
    }
    sz = vc.size();
    reverse (vc.begin(), vc.end());
    return fun (0, 0, 0, 0) + 1; //1 for value zero
}
int main ()
{
    ll l, r;
    int tc, cs = 0;
    memset (dp, -1, sizeof (dp));
    scanf (" %d", &tc);
    while (tc--) {
        scanf (" %lld %lld", &l, &r);
        printf ("Case %d: %lld\n", ++cs, fun1 (r) - fun1 (l-1));
    }
    return 0;
}
