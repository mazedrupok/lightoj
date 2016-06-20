/**
   MMM   MMM     A     ZZZZZZZ EEEEEEE DDDDD
   MM MMM MM    AAA    Z   ZZ  EE    E DDDDDDD
   MM  M  MM   AA AA      ZZ   EEEE    DD   DD
   MM     MM  AAAAAAA   ZZ   Z EE    E DDDDDDD
   MM     MM AA     AA ZZZZZZZ EEEEEEE DDDDD

 Name:     Md. Abdul Mazed (RUPOK)
           Noakhali Science & Technology University
 Email:    mazedrupok@gmail.com || mazed4g@gmail.com
 FB id:    www.facebook.com/mazedrupok
 github:   www.github.com/mazedrupok
 category: Backtracking DP
*/
#include <bits//stdc++.h>
using namespace std;
#define MX 100005
#define read(f)  freopen(f,"r",stdin)
#define write(f) freopen(f,"w",stdout)
#define LL long long
#define ULL unsigned long long
/****************************** END OF TEMPLATE ******************************/
int N, w;
int ara[31];
vector <LL> L, R;
void gener (int n, int lim, LL sum, vector<LL> &v) {
    if (sum > w) return;
    if (n >= lim) {
        if (sum <= w) v.push_back(sum);
        return;
    }
    gener (n+1, lim, sum, v);
    gener (n+1, lim, sum+ara[n], v);
}
int bs(LL val) {
    int lo = 0, hi = R.size() -1, mid, ans = lo-1;
    while (lo <= hi ) {
        mid = (lo+hi) /2;
        if(R[mid] <= val) {
            ans = mid; //Returning lower Bound
            lo = mid + 1;
        }
        else hi = mid - 1;
    }
    return ans;
}

int main ()
{
    int tc, cs = 0;
    cin >> tc;
    while (tc--) {
        cin >> N >> w;
        for (int i = 0; i < N; i++) cin >> ara[i];

        gener (0, N/2, 0, L);
        gener (N/2, N, 0, R);
        sort (L.begin(), L.end());
        sort (R.begin(), R.end());
        int cnt = 0;
        for (int i = 0; i < L.size(); i++) {
            cnt += bs (w-L[i]) +1;
        }
        printf ("Case %d: %d\n", ++cs, cnt);

        L.clear(); R.clear();
    }
    return 0;
}
