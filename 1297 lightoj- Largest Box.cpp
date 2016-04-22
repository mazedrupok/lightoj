#include <bits/stdc++.h>
using namespace std;
int main()
{
    int tc, cs = 0;
    double a, b, c, res, l, w, x;
    scanf(" %d", &tc);
    while(tc--) {
        scanf(" %lf %lf", &l, &w);
        a = 12.0;
        b = -4.0 * (l+w);
        c = l*w;
        x = (-b - sqrt (b*b - 4.0*a*c)) / (2.0*a);
        res = (l - 2*x) * (w - 2*x) * x;
        printf ("Case %d: %lf\n", ++cs, res);
    }
    return 0;
}
/*
   for area lw-4x^2 volume is --> (l-2x)(w-2x)x
                                    (l-2x)(w-2x)x
   for area    1    volume is -->  ----------------
                                       lw-4x^2
                                   (l-2x)(w-2x)x * lw
   for area   lw    volume is -->  ------------------- = 0  as when lw, hight is 0, so volume is 0.]
                                         lw-4x^2
   so, (l-2x)(w-2x)x = 0
   or, 12x^2-4(l+w)x+lw = 0
*/
