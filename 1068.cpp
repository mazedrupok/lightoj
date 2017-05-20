#include <bits//stdc++.h>
using namespace std;
vector <int> inp; //to store digits
int sz, k; //vc.size()
int dp[12][82][82][2]; //k can be maxi 81
int fun (int pos, int remainder, int digit_sum, bool is_small) {
    if (pos == sz) return (remainder+digit_sum) == 0;
    int &ret = dp[pos][remainder][digit_sum][is_small];
    if (ret != -1) return ret;
    int lim = is_small ? 9 : inp[pos];
    int cnt = 0;
    for (int i = 0; i <= lim; i++) {
        cnt += fun (pos+1, (remainder*10+i)%k, (digit_sum+i)%k, is_small | i < inp[pos]);
    }
    return ret = cnt;
}
int fun1 (int x) {
    inp.clear();
    memset (dp, -1, sizeof (dp));
    while (x) {
        inp.push_back (x %10);
        x /= 10;
    }
    sz = inp.size();
    reverse (inp.begin(), inp.end());
    return fun (0, 0, 0, 0); //1 for value zero
}
int main ()
{
    int tc, cs = 0, l, r;
    scanf (" %d", &tc);
    while (tc--) {
        scanf (" %d %d %d", &l, &r, &k);
        if (k == 1) printf ("Case %d: %d\n", ++cs, r-l+1);
        else if (k > 81) printf ("Case %d: 0\n", ++cs);
        else printf ("Case %d: %d\n", ++cs, fun1 (r) - fun1 (l-1));
    }
    return 0;
}
