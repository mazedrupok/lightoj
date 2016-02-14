#include <iostream>
#include <cstdio>
using namespace std;
int ara[100050], n;
int bsearch (int value) {
    int lo = 0, hi = n;
    int mid = (lo+hi) /2;
    while (lo <= hi) {
        if (ara[mid] == value) break;
        else if (ara[mid] < value) lo = mid+1;
        else if (ara[mid] > value) hi = mid-1;
        mid = (lo+hi) /2;
    }
    while (mid+1 <= n && ara[mid+1] <= value) mid++;
    while (mid-1 >= 0 && ara[mid-1] > value) mid--;
    return mid;
}
int main ()
{
    int tc, q, k = 0, lo, hi;
    //freopen ("in.txt", "r", stdin);
    scanf (" %d", &tc);
    while (tc--) {
        scanf (" %d %d", &n, &q);
        ara[0] = -1000;
        for (int i = 1; i <= n; i++) scanf (" %d", &ara[i]);
        printf ("Case %d:\n", ++k);
        while (q--) {
            scanf (" %d %d", &lo, &hi);
            int x = bsearch(lo-1);
            int y = bsearch(hi);
            //printf ("%d %d ", x, y);
            printf ("%d\n", y-x);
        }
    }
    return 0;
}
