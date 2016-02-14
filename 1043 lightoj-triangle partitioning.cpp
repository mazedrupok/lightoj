#include <iostream>
#include <cstdio>
#include <math.h>
#include <cstdlib>
using namespace std;
double abs (double c) {
    if (c < 0) c = -c;
    return c;
}
double area (double ab, double ac, double bc) {
    double s = (ab+ac+bc) /2;
    return sqrt (s*(s-ab)*(s-ac)*(s-bc));
}
double bsearch (double ab, double ac, double bc, double r) {
    double Tarea = area (ab, ac, bc);
    double lo = 0, hi = ab, mid, pre;
    mid = (lo+hi) /2;
    pre = mid;
    while (lo <= hi) {
        double ab1, ac1, bc1, area1, area2;
        ab1 = mid;
        ac1 = (mid * ac) /ab;
        bc1 = (mid * bc) /ab;
        area1 = area (ab1, ac1, bc1);
        area2 = Tarea - area1;
        if (area1/area2 == r) return mid;
        else if (area1/area2 > r) hi = mid;
        else lo = mid;

        mid = (lo+hi) /2;
        if (abs(mid-pre) < 0.0000001) break;
        pre = mid;
    }
    return mid;
}
int main ()
{
    int tc, k = 0;
    double mid, pre, ab, bc, ac, r;
    scanf (" %d", &tc);
    while (tc--) {
        scanf (" %lf %lf %lf %lf", &ab, &ac, &bc, &r);
        printf ("Case %d: %lf\n", ++k, bsearch(ab, ac, bc, r));
    }
    return 0;
}
