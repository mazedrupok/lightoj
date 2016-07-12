#include <bits/stdc++.h>
using namespace std;
#define LL long long
vector <int> vc[40];
bool taken[40];
int main()
{
    //freopen ("in.txt", "r", stdin);
    int tc, cs = 0, n, m, k, x, p;
    cin >> tc;
    while (tc--) {
        cin >> n >> m >> k;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) {
                cin >> x;
                vc[i].push_back (x);
            }
        }
        cin >> p;
        memset (taken, 0, sizeof (taken));
        while (p--) {
            cin >> x;
            if (x > 0) taken[x] = 1;
        }
        bool test = false, t = true;
        for (int i = 0; i < n; i++) {
            test = false;
            for (int j = 0; j < k; j++) {
                if (vc[i][j] > 0 && taken[vc[i][j]] == 1) {test = true; break;}
                else if (vc[i][j] < 0 && taken[-vc[i][j]] == 0) {test = true; break;}
            }
            if (test == false) {t = false; break;}
        }
        if (t == false ) printf ("Case %d: No\n", ++cs);
        else printf ("Case %d: Yes\n", ++cs);
        vector <int> tt[40]; swap (tt, vc);
    }
    return 0;

}
