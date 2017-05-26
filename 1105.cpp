#include <bits/stdc++.h>
using namespace std;
#define amin main
int lim = 1e9, sz;
int a[50];
void preProcess () {
    a[0] = 1;
    a[1] = 2;
    int i;
    for (i = 2; ; i++) {
        a[i] = a[i-1] + a[i-2];
        //cout << a[i] << endl;
        if (a[i] > lim) break;
    }
    sz = i;
}
int amin ()
{
    preProcess ();
    int tc, cs = 0, n;
    scanf (" %d", &tc);
    bool test;
    while (tc--) {
        scanf (" %d", &n);
        printf ("Case %d: ", ++cs);
        test = 0;
        for (int i = sz; i >= 0; i--) {
            if (a[i] <= n) {
                printf ("1");
                test = 1;
                n -= a[i];
            }
            else if (test == 1) printf ("0");
        }
        printf ("\n");
    }

    return 0;
}
