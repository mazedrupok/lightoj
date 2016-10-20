/**
Lightoj->1170
https://en.wikipedia.org/wiki/Catalan_number
        (2n)!
Cn = ----------- ///Catalan Numbers
     (n+1)! * n!
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 100000007;
ll ara[1000006];
ll fac[1000006];
int cnt=0;
void generate_num () {
    for(ll i = 2; i <= 100000; i++) {
        ll num = i*i;
        while(num <= 10000000000) {
          ara[cnt++] = num;
          num *= i;
        }
    }
    sort (ara, ara+cnt);
    cnt = unique (ara, ara+cnt) - ara; //deletes repeats
    ara[cnt++] = 1000000000000000; //for boundary
}
void gen_fac() {
    fac[0] = 1;
    for(int i = 1; i<= 1000005; i++) {
        fac[i] = (fac[i-1]*i) % MOD;
    }
}
template <class T> inline T bigmod(T p,T e,T M){
    ll ret = 1;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return (T)ret;
}
int main()
{
    generate_num();
    gen_fac();
    int tc, cs = 0;
    ll a, b, n, ans;
    scanf (" %d", &tc);
    while (tc--) {
        scanf (" %lld %lld", &a, &b);
        ll r = upper_bound(ara, ara+cnt,b) - ara;
        ll l = lower_bound(ara, ara+cnt,a) - ara;
        n = (r-l);
        printf ("Case %d: ", ++cs);
        if(n == 0) printf("0\n");
        else {
            ans = (fac[n+1] * fac[n]) %MOD;
            ans = bigmod (ans, MOD-2, MOD);
            ans = (fac[2*n] * ans) %MOD;
            printf ("%lld\n", ans);
        }
    }
    return 0;
}
