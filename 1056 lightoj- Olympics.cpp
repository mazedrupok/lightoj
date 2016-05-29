/*
   Name:  Md. Abdul Mazed
   Noakhali Science & Technology University
   Email:  mazedrupok@gmail.com || mazed4g@gmail.com
   FB id:  www.facebook.com/mazedrupok
   github: www.github.com/mazedrupok
   Category: Computational Geometry.
   Problem link:
   Comment:
*/
#include <bits/stdc++.h>
using namespace std;
#define MX 10005
#define read(f) freopen(f, "r", stdin)
#define write(f) freopen(f, "w", stdout)
typedef long long LL;
double sq (double x) {return x*x;}
int main ()
{
   int cs = 0, tc;
   double l, w, r, arc, angle, peri, rati;
   scanf (" %d", &tc);
   while (tc--) {
      scanf (" %lf : %lf", &l, &w);
      r = sqrt (sq(l/2) + sq(w/2));
      angle = acos ((sq(r) + sq(r) - sq(w)) / (2*r*r));
      arc = r * angle;
      peri = 2*arc + 2*l;
      rati = 400 / peri;
      printf ("Case %d: %.7lf %.7lf\n", ++cs, rati*l, rati*w);
   }
   return 0;
}
